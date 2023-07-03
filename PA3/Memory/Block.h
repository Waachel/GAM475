//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#ifndef BLOCK_H
#define BLOCK_H

#include "DLink.h"
#include <Mem.h>


namespace Azul
{

	class Heap;  // forward declare

	//-------------------------------------------------------------------------
	// Weird thing
	//   Please declare your forward declarations INSIDE namespace
	//   Outside the namespace cause all kinds of hell
	//-------------------------------------------------------------------------

	class Block
	{
	public:
		friend class Heap;  // forward declare
		// defines for the heap name length
		static const uint32_t NameLength = 64;
		static const uint32_t NameNumChar = (Block::NameLength - 1);

		// info structure
		struct Data
		{
			void* voidP;
		};

	public:
		// Public methods
		Block(size_t inSize, HANDLE h, void*& s, Azul::Mem::Align align, size_t& size);
		Block *GetHeapNext() const;
		Block *GetHeapPrev() const;
		Block *GetGlobalNext() const;
		Block *GetGlobalPrev() const;
		void SetGlobalNext(Block* prev, Block* next) const;
		void SetGlobalPrev(Block* b, Block* next) const;
		const char *GetFileName() const;
		size_t GetLineNum() const;
		size_t GetAllocIndex() const;
		size_t GetAllocSize() const;
		Heap *GetHeap() const;
		void *GetUserBlock() const;

		void SetAllocIndex(size_t i);
		void SetAllocSize(size_t s);

		void SetFileName(const char* inName);

		void SetLineNum(size_t lineNum);

	private:
		// Add tracking links 
		DLink bLink;   // Block links
		DLink gLink;   // Global links

		// stats
		Heap *pHeap;
		void *pUserBlock;

		size_t	mLineNum;
		size_t	mAllocIndex;
		size_t	mAllocSize;

		Data	mData;
		bool	aboveBlockFree = false;

		char	mFileName[Block::NameLength];

		int countBlocks = 0;
		// back pointer
		Block *pSecret;   // back pointer to the top of the trackingblock
	};

}

#endif

// ---  End of File ---