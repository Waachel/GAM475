//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Heap.h"
#include "Block.h"

namespace Azul
{
	Heap::Heap(HANDLE winHeapHandle, size_t heapSize, const char* const HeapName, Heap::Type hType)
		: mType(hType),
		mWinHeapHandle(winHeapHandle),
		totalHeapSize(heapSize),
		heapName{ 0 }
	{
		// set the name
		this->privSetHeapName(HeapName);
		this->mInfo.CurrBytesUsed = 0;
		this->mInfo.CurrNumAlloc = 0;
		this->mInfo.PeakBytesUsed = 0;
		this->mInfo.PeakNumAlloc = 0;
		this->mInfo.TotalSize = totalHeapSize;
	};

	void Heap::privSetHeapName(const char* const hName)
	{
		// Next couple lines, have safety to only copy a maximum of allowed characters
		assert(hName);

		unsigned int len = strlen(hName);

		if (len > NameNumChar)
		{
			len = NameNumChar;
		}

		memset(this->heapName, 0x0, NameLength);
		memcpy(this->heapName, hName, len);

		for (int i = 0; i < NameLength; i++)
		{
			this->mInfo.Name[i] = hName[i];
		}
	}

	Heap::Type Heap::GetHeapType() const
	{
		return mType;
	}

	// Overflow Heap
	void Heap::SetOverflowHeap(Heap* pHeap)
	{
		AZUL_REPLACE_ME(pHeap);
	}

	Heap* Heap::GetOverflowHeap() const
	{
		return (Heap*)AZUL_REPLACE_ME_STUB(77);
	}

	void Heap::GetInfo(Info& retInfo) const
	{
		retInfo.CurrBytesUsed = this->mInfo.CurrBytesUsed;
		retInfo.CurrNumAlloc = this->mInfo.CurrNumAlloc;
		for (int i = 0; i < NameLength; i++)
		{
			retInfo.Name[i] = this->mInfo.Name[i];
		}

		retInfo.PeakBytesUsed = this->mInfo.PeakBytesUsed;
		retInfo.PeakNumAlloc = this->mInfo.PeakNumAlloc;
		retInfo.TotalSize = this->mInfo.TotalSize;
	};

	Heap* Heap::DebugGetNext() const
	{

		return (Heap*)this->hLink.pNext;
	};

	Heap* Heap::DebugGetPrev() const
	{
		return (Heap*)this->hLink.pPrev;
	};

	Block* Heap::GetTrackingHead() const
	{
		return this->pBlkHead;
	}

	void* Heap::HeapAllocate(size_t inSize, Azul::Heap* const pHeap, Azul::Mem::Align align, const char* inName, size_t lineNum)
	{

		Mem* tmp = pMem->privGetInstance();
		void* s = nullptr;
		size_t size = 0;
		Block* b = new Block(inSize, pHeap->mWinHeapHandle, s, align, size);
		AddBlockToFront(b);
		b->SetAllocIndex(tmp->poRegistration->count + 1);
		b->SetFileName(inName);
		b->SetLineNum(lineNum);

		if (align != Azul::Mem::Align::Default)
		{
			size = 200;
		}
		//update stats
		this->mInfo.CurrBytesUsed += size;
		tmp->mInfo.CurrBytesUsed += size;

		if (tmp->mInfo.PeakBytesUsed < tmp->mInfo.CurrBytesUsed)
		{
			tmp->mInfo.PeakBytesUsed = tmp->mInfo.CurrBytesUsed;
		}

		if (this->mInfo.PeakBytesUsed < this->mInfo.CurrBytesUsed)
		{
			this->mInfo.PeakBytesUsed = this->mInfo.CurrBytesUsed;
		}

		tmp->mInfo.CurrAllocIndex += 1;

		tmp->mInfo.CurrNumAlloc += 1;
		this->mInfo.CurrNumAlloc += 1;

		if (tmp->mInfo.PeakNumAlloc < tmp->mInfo.CurrNumAlloc)
		{
			tmp->mInfo.PeakNumAlloc = tmp->mInfo.CurrNumAlloc;
		}

		if (this->mInfo.PeakNumAlloc < this->mInfo.CurrNumAlloc)
		{
			this->mInfo.PeakNumAlloc = this->mInfo.CurrNumAlloc;
		}

		return s;
	}

	void* Heap::PreAllocateFixed(size_t inSize, Azul::Heap* const pHeap, Azul::Mem::Align align)
	{

		void* s = nullptr;
		size_t size = 0;

		//one giant free block
		Block* freeB = new Block(inSize, pHeap->mWinHeapHandle, s, align, size);

		AddBlockToFrontFree(freeB);

		return s;
	}

	void* Heap::HeapAllocateFixed(size_t inSize, Azul::Heap* const pHeap, const char* inName, size_t lineNum)
	{
		Mem* tmp = pMem->privGetInstance();

		//find a free block
		Block* availFree = pHeap->pFixedFreeHead;
		pHeap->pFixedFreeHead = (Block*)pHeap->pFixedFreeHead->bLink.pNext;
		size_t availFreeSize = availFree->mAllocSize;
		while (true)
		{
			if (availFree->mAllocSize >= inSize)
			{
				break;
			}
			availFree = (Block*)availFree->bLink.pNext;
			if (availFree == 0)
			{
				// throw an exception here!
			}
		}

		//create a used block
		void* s = nullptr;
		size_t size = 0;
		Block* startUsed = availFree;

		Block* usedBlock = new (startUsed)Block(inSize, pHeap->mWinHeapHandle, s, Azul::Mem::Align::Default, size);

		AddBlockToFront(usedBlock);
		usedBlock->SetAllocIndex(tmp->poRegistration->count + 1);
		usedBlock->SetFileName(inName);
		usedBlock->SetLineNum(lineNum);

		//update stats
		this->mInfo.CurrBytesUsed += size;
		tmp->mInfo.CurrBytesUsed += size;

		if (tmp->mInfo.PeakBytesUsed < tmp->mInfo.CurrBytesUsed)
		{
			tmp->mInfo.PeakBytesUsed = tmp->mInfo.CurrBytesUsed;
		}

		if (this->mInfo.PeakBytesUsed < this->mInfo.CurrBytesUsed)
		{
			this->mInfo.PeakBytesUsed = this->mInfo.CurrBytesUsed;
		}

		tmp->mInfo.CurrAllocIndex += 1;

		tmp->mInfo.CurrNumAlloc += 1;
		this->mInfo.CurrNumAlloc += 1;

		if (tmp->mInfo.PeakNumAlloc < tmp->mInfo.CurrNumAlloc)
		{
			tmp->mInfo.PeakNumAlloc = tmp->mInfo.CurrNumAlloc;
		}

		if (this->mInfo.PeakNumAlloc < this->mInfo.CurrNumAlloc)
		{
			this->mInfo.PeakNumAlloc = this->mInfo.CurrNumAlloc;
		}

		//above block is not free
		usedBlock->aboveBlockFree = false;

		//adjust free block
		size_t remaining = availFreeSize - usedBlock->mAllocSize;

		//if we used the full block
		if (remaining == 0)
		{
			RemoveFreeBlock(availFree);
		}

		//create new free
		else
		{
			RemoveFreeBlock(availFree);
			Block* startFreeNew = (Block*)((size_t)usedBlock + 200 + sizeof(Block));
			startFreeNew->bLink.pNext = nullptr;
			startFreeNew->bLink.pPrev = nullptr;
			Block* freeB = new (startFreeNew) Block(remaining, pHeap->mWinHeapHandle, s, Azul::Mem::Align::Default, size);

			AddBlockToFrontFree(freeB);

		}

		//secret pointer

		return usedBlock;

	}

	void* Heap::HeapFreeBlock(Azul::Heap* const pHeap, void* p)
	{

		Mem* tmp = pMem->privGetInstance();

		//call HeapFree
		BOOL freeStatus;

		RemoveBlock(p);
		//RemoveUpdateGlobal(p);

		size_t size = HeapSize(pHeap->mWinHeapHandle, 0, p);

		//unregister
		//tmp->poRegistration->UnRegister(p);

		// note it's a BOOL not a bool
		freeStatus = HeapFree(pHeap->mWinHeapHandle, 0, p);

		//update stats
		this->mInfo.CurrBytesUsed -= size;
		tmp->mInfo.CurrBytesUsed -= size;

		this->mInfo.CurrNumAlloc -= 1;
		tmp->mInfo.CurrNumAlloc -= 1;

		return p;
	}

	void* Heap::HeapFreeFixedBlock(Azul::Heap* const pHeap, void* p)
	{
		Block* tmp = (Block*) p;

		//create free block
		void* s = nullptr;
		size_t size = 0;
		Block* newFreeBlock = tmp;
		size_t freeSize = tmp->mAllocSize;
		Block* freeB = new (newFreeBlock) Block(freeSize, pHeap->mWinHeapHandle, s, Azul::Mem::Align::Default, size);

		AddBlockToFrontFree(freeB);

		Mem* tmpMem = pMem->privGetInstance();
		//update stats
		this->mInfo.CurrBytesUsed -= size;
		tmpMem->mInfo.CurrBytesUsed -= size;

		this->mInfo.CurrNumAlloc -= 1;
		tmpMem->mInfo.CurrNumAlloc -= 1;

		return p;
	}

	//list of blocks in heap - add to front
	void Heap::AddBlockToFront(Block* block)
	{

		//if list of heaps is empty
		if (pBlkHead == nullptr)
		{
			pBlkHead = block;
			pBlkHead->bLink.pNext = nullptr;
			pBlkHead->bLink.pPrev = nullptr;
		}

		//else
		else
		{
			//Heap's next is the current head
			block->bLink.pNext = (DLink*)pBlkHead;

			//Current head's prev equals heap
			pBlkHead->bLink.pPrev = (DLink*)block;

			pBlkHead = block;
			pBlkHead->bLink.pPrev = nullptr;
		}

		//global head
		Mem* tmp = pMem->privGetInstance();

		if (tmp->pGlobalHead == nullptr)
		{
			tmp->pGlobalHead = block;
			tmp->pGlobalHead->gLink.pNext = nullptr;
			tmp->pGlobalHead->gLink.pPrev = nullptr;
		}

		else
		{
			//Heap's next is the current head
			block->gLink.pNext = (DLink*)tmp->pGlobalHead;

			//Current head's prev equals heap
			tmp->pGlobalHead->gLink.pPrev = (DLink*)block;

			tmp->pGlobalHead = block;
			tmp->pGlobalHead->gLink.pPrev = nullptr;
		}
	}

	//free blocks
	void Heap::AddBlockToFrontFree(Block* block)
	{

		//if list of heaps is empty
		if (pFixedFreeHead == nullptr)
		{
			pFixedFreeHead = block;
			pFixedFreeHead->bLink.pNext = nullptr;
			pFixedFreeHead->bLink.pPrev = nullptr;
		}

		//else
		else
		{
			//Heap's next is the current head
			block->bLink.pNext = (DLink*)pFixedFreeHead;

			//Current head's prev equals heap
			pFixedFreeHead->bLink.pPrev = (DLink*)block;

			pFixedFreeHead = block;
			pFixedFreeHead->bLink.pPrev = nullptr;
		}
	}

	//add to end
	void Heap::AddBlockToEnd(Block* block)
	{

		//if list of heaps is empty
		if (pBlkHead == nullptr)
		{
			pBlkHead = block;
			pBlkHead->bLink.pNext = nullptr;
			pBlkHead->bLink.pPrev = nullptr;
		}

		//else
		else
		{
			Block* tmp = pBlkHead;
			Block* savePrev = pBlkHead;
			//find end
			while (tmp->bLink.pNext != nullptr)
			{
				savePrev = tmp;
				tmp = (Block*)tmp->bLink.pNext;
			}

			//adjust links
			tmp->bLink.pNext = (DLink*)block;

		}

	}

	//grab first block
	Block* Heap::GrabBlockFromFront()
	{
		Mem* tmp = pMem->privGetInstance();
		Block* firstBlock;


		//none available
		if (tmp->poHead->pBlkHead == nullptr)
		{
			firstBlock = nullptr;
		}

		//block available
		else
		{
			//grab first block from list
			firstBlock = tmp->poHead->pBlkHead;

			//set original head's next as head
			tmp->poHead->pBlkHead = (Block*)tmp->poHead->pBlkHead->bLink.pNext;

		}

		return firstBlock;
	}

	void Heap::RemoveBlock(void* pBlock)
	{
		Mem* tmp = pMem->privGetInstance();

		Block* tmpBlockHeader = pBlkHead;

		//save tmp->pGlobalHead
		Block* saveHead = tmp->pGlobalHead;
		Block* savePrev = tmp->pGlobalHead;
		//delete only

		if (pBlkHead->mData.voidP == pBlock && pBlkHead->bLink.pNext == nullptr)
		{
			pBlkHead = nullptr;
			//only Block and only global
			if (tmp->pGlobalHead->gLink.pNext == nullptr && tmp->pGlobalHead->gLink.pPrev == nullptr)
			{
				tmp->pGlobalHead = nullptr;
			}

			//only Block but not only global
			else
			{
				//find block to remove from global
				while (tmp->pGlobalHead != nullptr)
				{

					//pGlobal is now the block to remove
					if (tmp->pGlobalHead->mData.voidP == pBlock)
					{
						//pGlobal's previous' next needs to equal pGlobal's next
						//removed block going next to next
						savePrev->gLink.pNext = tmp->pGlobalHead->gLink.pNext;

						//pGlobal's nexts' prev needs to equal pGlobal's prev
							//restart at the beginning
						tmp->pGlobalHead = saveHead;
						while (tmp->pGlobalHead != nullptr)
						{
							//block before the one we deleted
							if (tmp->pGlobalHead->gLink.pNext != nullptr)
							{
								if (tmp->pGlobalHead != tmp->pGlobalHead->GetGlobalNext()->GetGlobalPrev())
								{
									saveHead->GetGlobalNext()->SetGlobalPrev(tmp->pGlobalHead, (Block*)tmp->pGlobalHead->gLink.pNext);
								}
							}

							tmp->pGlobalHead = (Block*)tmp->pGlobalHead->gLink.pNext;
						}

						//put GlobalHead back to real global head
						tmp->pGlobalHead = saveHead;
						break;
					}

					//not found, go to next in the list
					savePrev = tmp->pGlobalHead;
					tmp->pGlobalHead = (Block*)tmp->pGlobalHead->gLink.pNext;

				}


			}
		}

		//delete front
		else if (pBlkHead->mData.voidP == pBlock && pBlkHead != nullptr)
		{
			pBlkHead = (Block*)pBlkHead->bLink.pNext;
			pBlkHead->bLink.pPrev = nullptr;
			if (tmp->pGlobalHead != nullptr)
			{
				//Block's head and global's head
				if (tmp->pGlobalHead->mData.voidP == pBlock)
				{
					tmp->pGlobalHead = (Block*)tmp->pGlobalHead->gLink.pNext;
					if (tmp->pGlobalHead != nullptr)
					{
						tmp->pGlobalHead->gLink.pPrev = nullptr;
					}
				}

				//Block's head but not global's head
				else
				{
					//global head
					saveHead = tmp->pGlobalHead;
					savePrev = tmp->pGlobalHead;
					tmp->pGlobalHead = tmp->pGlobalHead;
					while (tmp->pGlobalHead != nullptr)
					{
						if (tmp->pGlobalHead->mData.voidP == pBlock)
						{
							savePrev->gLink.pNext = tmp->pGlobalHead->gLink.pNext;
							//pGlobal's nexts' prev needs to equal pGlobal's prev
							//restart at the beginning
							tmp->pGlobalHead = saveHead;
							while (tmp->pGlobalHead != nullptr)
							{
								//block before the one we deleted
								if (tmp->pGlobalHead->gLink.pNext != nullptr)
								{
									if (tmp->pGlobalHead != tmp->pGlobalHead->GetGlobalNext()->GetGlobalPrev())
									{
										saveHead->GetGlobalNext()->SetGlobalPrev(tmp->pGlobalHead, (Block*)tmp->pGlobalHead->gLink.pNext);
									}
								}

								tmp->pGlobalHead = (Block*)tmp->pGlobalHead->gLink.pNext;
							}
							tmp->pGlobalHead = saveHead;
							return;
						}

						//not found, go to next Block
						savePrev = tmp->pGlobalHead;
						tmp->pGlobalHead = tmp->pGlobalHead->GetGlobalNext();
					}
				}
			}

		}

		else
		{
			tmpBlockHeader = pBlkHead;
			int count = 0;
			while (tmpBlockHeader != nullptr)
			{
				if (tmpBlockHeader->mData.voidP == pBlock)
				{
					//delete end
					if (tmpBlockHeader->bLink.pNext == nullptr)
					{
						tmpBlockHeader->bLink.pPrev->pNext = nullptr;
					}

					//delete middle
					else
					{
						//A - > B -> C : delete B
						//A's next will now point to		C
						tmpBlockHeader->bLink.pPrev->pNext = tmpBlockHeader->bLink.pNext;

						//C's prev will now point to		A
						tmpBlockHeader->bLink.pNext->pPrev = tmpBlockHeader->bLink.pPrev;

					}
				}
				//not found, go to next Block
				tmpBlockHeader = tmpBlockHeader->GetHeapNext();
				count++;
			}

			//global head
			saveHead = tmp->pGlobalHead;
			savePrev = tmp->pGlobalHead;
			tmp->pGlobalHead = tmp->pGlobalHead;
			while (tmp->pGlobalHead != nullptr)
			{
				if (tmp->pGlobalHead->mData.voidP == pBlock)
				{
					//only
					if (tmp->pGlobalHead->gLink.pNext == nullptr && tmp->pGlobalHead->gLink.pPrev == nullptr)
					{
						//do nothing
					}

					//delete end
					else if (tmp->pGlobalHead->gLink.pNext == nullptr)
					{
						savePrev->gLink.pNext = nullptr;
						tmp->pGlobalHead = saveHead;
						return;
					}

					//delete middle
					else
					{
						//A - > B -> C : delete B
						//A's next will now point to		C
						savePrev->gLink.pNext = tmp->pGlobalHead->gLink.pNext;

						//C's prev will now point to		A
						//pGlobal's nexts' prev needs to equal pGlobal's prev
						//restart at the beginning
						tmp->pGlobalHead = saveHead;
						while (tmp->pGlobalHead != nullptr)
						{
							//block before the one we deleted
							if (tmp->pGlobalHead->gLink.pNext != nullptr)
							{
								if (tmp->pGlobalHead != tmp->pGlobalHead->GetGlobalNext()->GetGlobalPrev())
								{
									saveHead->GetGlobalNext()->SetGlobalPrev(tmp->pGlobalHead, (Block*)tmp->pGlobalHead->gLink.pNext);
								}
							}

							tmp->pGlobalHead = (Block*)tmp->pGlobalHead->gLink.pNext;
						}

						tmp->pGlobalHead = saveHead;
						return;
					}
				}
				//not found, go to next Block
				savePrev = tmp->pGlobalHead;
				tmp->pGlobalHead = tmp->pGlobalHead->GetGlobalNext();

			}
			tmp->pGlobalHead = saveHead;
		}


	}

	void Heap::RemoveFreeBlock(void* pBlock)
	{
		Mem* tmp = pMem->privGetInstance();

		Block* tmpBlockHeader = pFixedFreeHead;

		//delete only

		if (pFixedFreeHead == pBlock && pFixedFreeHead->bLink.pNext == nullptr)
		{
			pFixedFreeHead = nullptr;

		}

		//delete front
		else if (pFixedFreeHead == pBlock && pFixedFreeHead != nullptr)
		{
			pFixedFreeHead = (Block*)pFixedFreeHead->bLink.pNext;
			pFixedFreeHead->bLink.pPrev = nullptr;

		}

		else
		{
			tmpBlockHeader = pFixedFreeHead;
			int count = 0;
			while (tmpBlockHeader != nullptr)
			{
				if (tmpBlockHeader->mData.voidP == pBlock)
				{
					//delete end
					if (tmpBlockHeader->bLink.pNext == nullptr)
					{
						tmpBlockHeader->bLink.pPrev->pNext = nullptr;
					}

					//delete middle
					else
					{
						//A - > B -> C : delete B
						//A's next will now point to		C
						tmpBlockHeader->bLink.pPrev->pNext = tmpBlockHeader->bLink.pNext;

						//C's prev will now point to		A
						tmpBlockHeader->bLink.pNext->pPrev = tmpBlockHeader->bLink.pPrev;

					}
				}
				//not found, go to next Block
				tmpBlockHeader = tmpBlockHeader->GetHeapNext();
				count++;
			}


		}

	}

	Block* Heap::glueBlocks(Block*& pFree1, Block*& pFree2)
	{
		pFree1->bLink.pNext = pFree2->bLink.pNext;
		if (pFree2->bLink.pNext != 0)
		{
			pFree2->bLink.pNext->pPrev = (DLink*)pFree1;
		}
		pFree1->mAllocSize = pFree1->mAllocSize + sizeof(Block) + pFree2->mAllocSize;

		return pFree1;
	}
}

// --- End of File ---
