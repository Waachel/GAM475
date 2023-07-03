//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef HEAP_H
#define HEAP_H

#include "Mem.h"
#include "DLink.h"

namespace Azul
{

	//-------------------------------------------------------------------------
	// Namespace Weird thing
	//   Please declare your forward declarations INSIDE namespace
	//   Outside the namespace cause all kinds of hell
	//-------------------------------------------------------------------------

	// Forward declaration
	class Block;

	// Heap class
	class Heap
	{
	public:
		friend class Mem;

		// Constants 
		static const uint32_t NameLength = 64;
		static const uint32_t NameNumChar = (NameLength - 1);

		// -----------------------------------------------------------------
		// When declaring a fixed heap... need space for overhead
		//    initial size = numAlloc*sizeBlock+sizeof(Heap)+FreeHeapExtra
		// -----------------------------------------------------------------
		static const uint32_t FreeHeapExtra = 4 * 1024;

		// Heap Types
		enum class Type : size_t
		{
			NORMAL,
			FIXED
		};

		// Info structure
		struct Info
		{
			size_t    TotalSize;
			size_t	  PeakNumAlloc;
			size_t	  CurrNumAlloc;
			size_t	  PeakBytesUsed;
			size_t	  CurrBytesUsed;
			char Name[Heap::NameLength];
		};

	public:
		//Specialized Constructor
		Heap(HANDLE winHeapHandle, size_t HeapSize, const char* const HeapName, Heap::Type hType);
		Heap() = delete;

		// Public Interface (For Customers)
		void GetInfo(Info &info) const;

		// Tracking block 
		Block *GetTrackingHead() const;
		void* HeapAllocate(size_t inSize, Azul::Heap* const pHeap, Azul::Mem::Align align, const char* inName, size_t lineNum);
		void* PreAllocateFixed(size_t inSize, Azul::Heap* const pHeap, Azul::Mem::Align align);
		void* HeapAllocateFixed(size_t inSize, Azul::Heap* const pHeap, const char* inName, size_t lineNum);
		void* HeapFreeBlock(Azul::Heap* const pHeap, void* p);
		void* HeapFreeFixedBlock(Azul::Heap* const pHeap, void* p);
		void AddBlockToFront(Block* block);
		void AddBlockToFrontFree(Block* block);
		void AddBlockToEnd(Block* block);
		Block* GrabBlockFromFront();
		void RemoveBlock(void* pBlock);
		void RemoveFreeBlock(void* pBlock);
		Block* glueBlocks(Block*& pFree1, Block*& pFree2);
		Heap::Type GetHeapType() const;

		// Overflow Heap
		void SetOverflowHeap(Heap *);
		Heap *GetOverflowHeap() const;

		// Needed for Testings (Not for Customers)
		Heap *DebugGetNext() const;
		Heap *DebugGetPrev() const;


		DLink   hLink;   // Heap Link
		HANDLE  mWinHeapHandle;
		Mem* pMem;
		Block* pBlkHead;

	private:
		void privSetHeapName(const char* const hName);

		// data ------------------------------------------------

		Type	mType;
		
		Info	mInfo;


		// null for Normal, used only in FixedHeap
		Block *pFixedFreeHead;

		// Overflow heap
		Heap *pOverflow;

		// Back link to the memory system


		size_t	totalHeapSize;

		char heapName[NameLength];
	};

}

#endif

// --- End of File ---
