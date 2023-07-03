//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Mem.h"
#include "Block.h"
#include "heap.h"

namespace Azul
{
	// Create the heap.
	Mem::Code Mem::NormalHeap(Heap *&newHeap, unsigned int heapSize, const char *const Name)
	{
		Mem* tmp = privGetInstance();

		if (!tmp->mInitialized)
		{
			newHeap = nullptr;
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

		// Create a heap of size heapSize, and max size = 0 to make it growable
		HANDLE heapWinHandle = HeapCreate(0, heapSize, 0);

		void* s = HeapAlloc(heapWinHandle, 0, sizeof(Heap));

		newHeap = new(s) Heap(heapWinHandle, heapSize, Name, Heap::Type::NORMAL);

		tmp->AddToFront(newHeap);

		tmp->mInfo.CurrHeapCount++;
		tmp->mInfo.PeakHeapCount++;

		tmp->mWrongHeap = false;

		return Mem::Code::OK;

	}

	Mem::Code Mem::FixedHeap(Heap *&newHeap, unsigned int numBlocks, int sizePerBlock, const char *const Name)
	{
		Mem* tmp = privGetInstance();

		size_t heapSize = (size_t)(numBlocks * sizePerBlock);

		if (!tmp->mInitialized)
		{
			newHeap = nullptr;
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

		// Create a heap of size heapSize, and max size = 0 to make it growable
		HANDLE heapWinHandle = HeapCreate(0, heapSize, 0);

		void* s = HeapAlloc(heapWinHandle, 0, sizeof(Heap));

		newHeap = new(s) Heap(heapWinHandle, heapSize, Name, Heap::Type::FIXED);

		tmp->poHead = newHeap;
		tmp->mInfo.CurrHeapCount++;
		tmp->mInfo.PeakHeapCount++;

		tmp->mWrongHeap = false;

		newHeap->PreAllocateFixed(heapSize, newHeap, Azul::Mem::Align::Default);

		return Mem::Code::OK;

	}

	//list of heaps - add to front
	void Mem::AddToFront(Heap*& pHeap)
	{
		Mem* tmp = privGetInstance();

		//if list of heaps is empty
		if (tmp->poHead == nullptr)
		{
			tmp->poHead = pHeap;
			tmp->poHead->hLink.pNext = nullptr;
			tmp->poHead->hLink.pPrev = nullptr;
		}

		//else
		else
		{
			//Heap's next is the current head
			pHeap->hLink.pNext = (DLink*) tmp->poHead;

			//Current head's prev equals heap
			tmp->poHead->hLink.pPrev = (DLink*)pHeap;

			tmp->poHead = pHeap;
			tmp->poHead->hLink.pPrev = nullptr;
		}

	}

	//singleton
	Mem* Mem::privGetInstance()
	{
		static Mem instance;
		return &instance;
	}

	// Initialize the memory system  (Public method)
	Mem::Code Mem::Create(void)
	{
		privGetInstance()->privInitialize();
		return Mem::Code::OK;
	}

	void Mem::privInitialize(void)
	{
		this->poHead = nullptr;
		this->pGlobalHead = nullptr;
		this->mInitialized = true;
		this->mInfo.CurrAllocIndex = 0;
		this->mInfo.CurrBytesUsed = 0;
		this->mInfo.CurrHeapCount = 0;
		this->mInfo.CurrNumAlloc = 0;
		this->mInfo.PeakBytesUsed = 0;
		this->mInfo.PeakHeapCount = 0;
		this->mInfo.PeakNumAlloc = 0;
		this->poRegistration = new Registration();
	}

	Mem::Code Mem::Destroy(void)
	{
		Mem* tmp = privGetInstance();

		if (!tmp->mInitialized)
		{
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

		tmp->mInitialized = false;

		return Mem::Code::OK;
	}

	Mem::Code Mem::GetInfo(Mem::Info &retInfo)
	{
		Mem * tmp = privGetInstance();

		if (!tmp->mInitialized)
		{
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}
		retInfo.CurrAllocIndex = tmp->mInfo.CurrAllocIndex;
		retInfo.CurrBytesUsed = tmp->mInfo.CurrBytesUsed;
		retInfo.CurrHeapCount = tmp->mInfo.CurrHeapCount;
		retInfo.CurrNumAlloc = tmp->mInfo.CurrNumAlloc;
		retInfo.PeakBytesUsed = tmp->mInfo.PeakBytesUsed;
		retInfo.PeakHeapCount = tmp->mInfo.PeakHeapCount;
		retInfo.PeakNumAlloc = tmp->mInfo.PeakNumAlloc;
		return Mem::Code::OK;
	}

	Heap *Mem::DebugGetHeapHead()
	{
		Mem* tmp = privGetInstance();
		return tmp->poHead;
	}

	Block *Mem::DebugGetGlobalTrackingHead()
	{
		Mem* tmp = privGetInstance();
		return tmp->pGlobalHead;
	}

	Mem::Code Mem::RemoveHeap(Heap *pInHeap)
	{

		Mem* tmp = privGetInstance();

		//No_Initialize_NullHeap_Destroy
		if (pInHeap == nullptr && !tmp->mInitialized)
		{
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

		//No_Initialize_Heap_Destroy
		if (pInHeap != nullptr && !tmp->mInitialized)
		{
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

		//Initialize_WrongHeap_Destroy
		if (tmp->mInitialized)
		{
			bool match = false;
			Heap* tmpHeapHeader = tmp->poHead;
			while (tmpHeapHeader != nullptr)
			{
				if (tmpHeapHeader == pInHeap)
				{
					match = true;
					break;
				}

				//not found, go to next heap
				tmpHeapHeader = tmpHeapHeader->DebugGetNext();
			}

			if (match == false)
			{
				return Mem::Code::ERROR_Illegal_Heap;
			}

		}

		//No_Initialize_Destroy 
		if (!tmp->mInitialized)
		{
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

		//Initialize_NullHeap_Destroy
		if (tmp->mInitialized && pInHeap == nullptr)
		{
			return Mem::Code::ERROR_Illegal_Heap;
		}

		//delete allocations
		Block* tmpB = pInHeap->pBlkHead;
		while (tmpB != nullptr)
		{
			tmp->mInfo.CurrBytesUsed -= tmpB->GetAllocSize();
			tmp->mInfo.CurrNumAlloc--;
			tmpB = tmpB->GetHeapNext();
		}

		//delete only
		if (pInHeap == tmp->poHead && tmp->poHead->hLink.pNext == nullptr)
		{
			tmp->poHead = nullptr;
			tmp->mInfo.CurrHeapCount--;
			return Mem::Code::OK;
		}

		//delete front
		if (pInHeap == tmp->poHead)
		{
			tmp->poHead = (Heap*)tmp->poHead->hLink.pNext;
			tmp->poHead->hLink.pPrev = nullptr;
			tmp->mInfo.CurrHeapCount--;
			return Mem::Code::OK;
		}

		Heap* tmpHeapHeader = tmp->poHead;
		while (tmpHeapHeader != nullptr)
		{
			if (tmpHeapHeader == pInHeap)
			{
				//delete end
				if (tmpHeapHeader->hLink.pNext == nullptr)
				{
					tmpHeapHeader->hLink.pPrev->pNext = nullptr;
					tmp->mInfo.CurrHeapCount--;
					return Mem::Code::OK;
				}

				//delete middle
				else
				{
					//A - > B -> C : delete B
					//A's next will now point to		C
					tmpHeapHeader->hLink.pPrev->pNext = tmpHeapHeader->hLink.pNext;

					//C's prev will now point to		A
					tmpHeapHeader->hLink.pNext->pPrev = tmpHeapHeader->hLink.pPrev;
					tmp->mInfo.CurrHeapCount--;
					return Mem::Code::OK;
				}
			}
			//not found, go to next heap
			tmpHeapHeader = tmpHeapHeader->DebugGetNext();

		}

		return Mem::Code::OK;
		
	}

	Mem::Code Mem::GetHeapByAddr(Heap *&pHeap, void *p)
	{
		Mem* tmp = privGetInstance();
		Heap* tmpHeap;
		//check if p exists
		bool e = tmp->poRegistration->Find(p, tmpHeap);

		//No_Initialize_NullHeap_Destroy
		if (!tmp->mInitialized)
		{
			return Mem::Code::ERROR_Mem_Not_Initialized;
		}

		if (tmp->mInitialized)
		{
			bool match = false;
			Heap* tmpHeapHeader = tmp->poHead;
			while (tmpHeapHeader != nullptr && match == false)
			{
				if (tmpHeapHeader == p)
				{
					match = true;
					pHeap = tmpHeapHeader;
					break;
				}
				//not found, go to next heap
				tmpHeapHeader = tmpHeapHeader->DebugGetNext();
			}

			if (match == false && e == true)
			{
				pHeap = tmpHeap;
				match = true;
			}

			if (match == false)
			{
				pHeap = tmp->poHead;
				return Mem::Code::ERROR_Invalid_Addr;
			}

		}
		AZUL_REPLACE_ME(pHeap);
		return (Mem::Code)AZUL_REPLACE_ME_STUB(77);
	}

}

// --- End of File ---
