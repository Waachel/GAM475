//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "Mem.h"
#include "GlobalNew.h"

//-------------------------------------------------------------------------
// Namespace Weird thing:
//   Don't use namespace here...
//   Since new/delete isn't allowed namespace
//   do all declaraton with full name Azul::Heap... or Azul::Mem::Align...
//-------------------------------------------------------------------------


// --------------------------------------------
// For Normal Heap
// --------------------------------------------
#ifndef align_up
#define align_up(num, align) \
    (((num) + ((align) - 1)) & ~((align) - 1))

bool fixed = false;

void* operator new(size_t inSize, Azul::Heap* const pHeap, Azul::Mem::Align align, const char* inName, size_t lineNum)
{
	fixed = false;
	uint32_t hdrSize = 0;
	if (align == Azul::Mem::Align::Byte_8)
	{

	}
	else if (align == Azul::Mem::Align::Byte_16)
	{
		uint16_t offset_t;
		hdrSize = sizeof(offset_t) + (16 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_32)
	{
		uint32_t offset_t;
		hdrSize = sizeof(offset_t) + (32 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_64)
	{
		uint64_t offset_t;
		hdrSize = sizeof(offset_t) + (64 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_128)
	{
		uint64_t offset_t;
		hdrSize = sizeof(offset_t * 2) + (128 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_256)
	{
		uint64_t offset_t;
		hdrSize = sizeof(offset_t * 4) + (256 - 1);
	}
	else
	{
		//do nothing
		//default Byte_4
	}

	void* p = pHeap->HeapAllocate(inSize + hdrSize, pHeap, align, inName, lineNum);

	void* ptr = p;


	if (p)
	{
		/*
		 * Add the offset size to malloc's pointer
		 * (we will always store that)
		 * Then align the resulting value to the
		 * target alignment
		 */

		if (align == Azul::Mem::Align::Byte_8)
		{

		}
		else if (align == Azul::Mem::Align::Byte_16)
		{
			uint16_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t))) + (16 - 1)) & ~(16 - 1));

			*((uint16_t*)ptr - 1) = (uint16_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_32)
		{
			uint32_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t))) + (32 - 1)) & ~(32 - 1));

			*((uint32_t*)ptr - 1) = (uint32_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_64)
		{
			uint64_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t))) + (64 - 1)) & ~(64 - 1));

			*((uint64_t*)ptr - 1) = (uint64_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_128)
		{
			uint64_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t * 2))) + (128 - 1)) & ~(128 - 1));

			*((uint64_t*)ptr - 1) = (uint64_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_256)
		{
			uint64_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t * 4))) + (256 - 1)) & ~(256 - 1));

			*((uint64_t*)ptr - 1) = (uint64_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else
		{
			//do nothing
			//default Byte_4
		}

	}

	//Trace::out("Look at my file: \n%s  \nat line:\n %d\n", inName, lineNum);
	Azul::Mem* tmp = pHeap->pMem->privGetInstance();

	bool f = tmp->poRegistration->Register(p, ptr, pHeap);
	AZUL_REPLACE_ME(f);
	return ptr;
}

void operator delete(void *p, Azul::Heap *const pHeap, Azul::Mem::Align align, const char *inName, size_t lineNum)
{
	// -----------------------------------------
	// You don't need to implement this... 
	// its here to shut up compiler warnings
	// just this function
	//------------------------------------------
	AZUL_REPLACE_ME(p);
	AZUL_REPLACE_ME(pHeap);
	AZUL_REPLACE_ME(align);
	AZUL_REPLACE_ME(inName);
	AZUL_REPLACE_ME(lineNum);
}

void *operator new[](size_t inSize, Azul::Heap *const pHeap, Azul::Mem::Align align, const char *inName, size_t lineNum)
{
	fixed = false;
	uint32_t hdrSize = 0;
	if (align == Azul::Mem::Align::Byte_8)
	{

	}
	else if (align == Azul::Mem::Align::Byte_16)
	{
		uint16_t offset_t;
		hdrSize = sizeof(offset_t) + (16 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_32)
	{
		uint32_t offset_t;
		hdrSize = sizeof(offset_t) + (32 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_64)
	{
		uint64_t offset_t;
		hdrSize = sizeof(offset_t) + (64 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_128)
	{
		uint64_t offset_t;
		hdrSize = sizeof(offset_t * 2) + (128 - 1);
	}
	else if (align == Azul::Mem::Align::Byte_256)
	{
		uint64_t offset_t;
		hdrSize = sizeof(offset_t * 4) + (256 - 1);
	}
	else
	{
		//do nothing
		//default Byte_4
	}

	void* p = pHeap->HeapAllocate(inSize + hdrSize, pHeap, align, inName, lineNum);

	void* ptr = p;


	if (p)
	{
		/*
		 * Add the offset size to malloc's pointer
		 * (we will always store that)
		 * Then align the resulting value to the
		 * target alignment
		 */

		if (align == Azul::Mem::Align::Byte_8)
		{

		}
		else if (align == Azul::Mem::Align::Byte_16)
		{
			uint16_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t))) + (16 - 1)) & ~(16 - 1));

			*((uint16_t*)ptr - 1) = (uint16_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_32)
		{
			uint32_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t))) + (32 - 1)) & ~(32 - 1));

			*((uint32_t*)ptr - 1) = (uint32_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_64)
		{
			uint64_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t))) + (64 - 1)) & ~(64 - 1));

			*((uint64_t*)ptr - 1) = (uint64_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_128)
		{
			uint64_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t * 2))) + (128 - 1)) & ~(128 - 1));

			*((uint64_t*)ptr - 1) = (uint64_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else if (align == Azul::Mem::Align::Byte_256)
		{
			uint64_t offset_t;
			ptr = (void*)(((((uintptr_t)p + sizeof(offset_t * 4))) + (256 - 1)) & ~(256 - 1));

			*((uint64_t*)ptr - 1) = (uint64_t)((uintptr_t)ptr - (uintptr_t)p);
		}
		else
		{
			//do nothing
			//default Byte_4
		}

	}

	//Trace::out("Look at my file: \n%s  \nat line:\n %d\n", inName, lineNum);
	Azul::Mem* tmp = pHeap->pMem->privGetInstance();

	bool f = tmp->poRegistration->Register(p, ptr, pHeap);
	AZUL_REPLACE_ME(f);
	return ptr;
}

void operator delete[](void *p, Azul::Heap *const pHeap, Azul::Mem::Align align, const char *inName, size_t lineNum)
{
	// -----------------------------------------
	// You don't need to implement this... 
	// its here to shut up compiler warnings
	// just this function
	//------------------------------------------
	AZUL_REPLACE_ME(p);
	AZUL_REPLACE_ME(pHeap);
	AZUL_REPLACE_ME(align);
	AZUL_REPLACE_ME(inName);
	AZUL_REPLACE_ME(lineNum);
}

// --------------------------------------------
// For Fixed Heap
// --------------------------------------------

void *operator new(size_t inSize, Azul::Heap *const pHeap, const char *inName, size_t lineNum)
{
	void* p = pHeap->HeapAllocateFixed(inSize, pHeap, inName, lineNum);
	//void* p = pHeap->HeapAllocateFixed(inSize, pHeap);
	//Trace::out("Look at my file: \n%s  \nat line:\n %d\n", inName, lineNum);
	Azul::Mem* tmp = pHeap->pMem->privGetInstance();

	bool f = tmp->poRegistration->Register(p, p, pHeap);
	fixed = true;
	return p;
}

void operator delete(void *p, Azul::Heap *const pHeap, const char *inName, size_t lineNum)
{
	// -----------------------------------------
	// You don't need to implement this... 
	// its here to shut up compiler warnings
	// just this function
	//------------------------------------------
	AZUL_REPLACE_ME(p);
	AZUL_REPLACE_ME(pHeap);
	AZUL_REPLACE_ME(inName);
	AZUL_REPLACE_ME(lineNum);
}

// --------------------------------------------
// For Global Standard new/delete
// --------------------------------------------

void *operator new(size_t inSize)
{
	void *p = malloc(inSize);
	return p;
}

void operator delete(void *p)
{
	Azul::Heap* pHeap;
	Azul::Mem::GetHeapByAddr(pHeap, p);
	Azul::Mem* tmp = pHeap->pMem->privGetInstance();
	
	if (fixed == true)
	{
		if (!tmp->poRegistration->Find(p, pHeap))
		{
			free(p);
		}
		else
		{
			int i = 0;
			for (i = 0; i < tmp->poRegistration->ReserveSize; i++)
			{
				if (tmp->poRegistration->mSetData.voidPtr[i] == p)
				{
					break;
				}
			}
			pHeap->HeapFreeFixedBlock(pHeap, tmp->poRegistration->mSetData.voidP[i]);
			tmp->poRegistration->UnRegister(p);
		}
	}
	else if (!tmp->poRegistration->Find(p, pHeap))
	{
		free(p);
	}
	else
	{
		int i = 0;
		for (i = 0; i < tmp->poRegistration->ReserveSize; i++)
		{
			if (tmp->poRegistration->mSetData.voidPtr[i] == p)
			{
				break;
			}
		}
		
		tmp->poRegistration->UnRegister(p);
		pHeap->HeapFreeBlock(pHeap, tmp->poRegistration->mSetData.voidP[i]);
	}
}

void *operator new[](size_t inSize)
{
	void *p = malloc(inSize);
	return p;
}

void operator delete[](void *p)
{
	Azul::Heap* pHeap;
	Azul::Mem::GetHeapByAddr(pHeap, p);
	Azul::Mem* tmp = pHeap->pMem->privGetInstance();

	if (!tmp->poRegistration->Find(p, pHeap))
	{
		free(p);
	}
	else
	{
		int i = 0;
		for (i = 0; i < tmp->poRegistration->ReserveSize; i++)
		{
			if (tmp->poRegistration->mSetData.voidPtr[i] == p)
			{
				break;
			}
		}

		tmp->poRegistration->UnRegister(p);
		pHeap->HeapFreeBlock(pHeap, tmp->poRegistration->mSetData.voidP[i]);
	}
}
#endif

// --- End of File ---
