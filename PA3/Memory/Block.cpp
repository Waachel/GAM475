//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Block.h"

namespace Azul
{

	Block::Block(size_t inSize, HANDLE h, void*& s, Azul::Mem::Align align, size_t& size)
	{
		//call HeapAlloc
		s = HeapAlloc(h, 0, inSize);

		//register
		//tmp->poRegistration->Register(s);

		//void* s = (p + (64 –1)) & ~(64 - 1);
		AZUL_REPLACE_ME(align);

		size = HeapSize(h, 0, s);
		SetAllocSize(size);
		mData.voidP = s;
	}

	Block *Block::GetHeapNext() const
	{
		return (Block*)bLink.pNext;
	}

	Block *Block::GetHeapPrev() const
	{
		return (Block*)bLink.pPrev;
	}

	Block *Block::GetGlobalNext() const
	{
		return (Block*)gLink.pNext;
	}

	Block *Block::GetGlobalPrev() const
	{
		return (Block*)gLink.pPrev;
	}


	void Block::SetGlobalNext(Block* prev, Block* next) const
	{

			prev->gLink.pNext = (DLink*)next;
	}

	void Block::SetGlobalPrev(Block* prev, Block* next) const
	{
		next->gLink.pPrev = (DLink*)prev;
	}

	const char *Block::GetFileName() const
	{
		return mFileName;
	}

	size_t Block::GetLineNum() const
	{
		return mLineNum;
	}

	size_t Block::GetAllocIndex() const
	{
		return mAllocIndex;
	}

	size_t Block::GetAllocSize() const
	{
		return mAllocSize;
	}

	Heap *Block::GetHeap() const
	{
		return pHeap;
	}

	void *Block::GetUserBlock() const
	{
		return pUserBlock;
	}

	void Block::SetAllocIndex(size_t i)
	{
		mAllocIndex = i;
	}

	void Block::SetAllocSize(size_t s)
	{
		mAllocSize = s;
	}

	void Block::SetFileName(const char* inName)
	{
		// Next couple lines, have safety to only copy a maximum of allowed characters
		assert(inName);
		char* next_token;
		char* fName = (char*)inName;
		fName = strrchr(fName, '\\' );

		fName = strtok_s(fName, "\\", &next_token);

		unsigned int len = strlen(fName);

		if (len > NameNumChar)
		{
			len = NameNumChar;
		}

		memset(mFileName, 0x0, NameLength);
		memcpy(mFileName, fName, len);
	}

	void Block::SetLineNum(size_t lineNum)
	{
		mLineNum = lineNum;
	}

}

// --- End of File ---