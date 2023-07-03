#include "Registration.h"

Azul::Registration::Registration()
{
}

Azul::Registration::~Registration()
{
}

bool Azul::Registration::Register(void* p, void* ptr, Heap* heap)
{
	set.insert(ptr);
	mSetData.heapPtr[count] = heap;
	mSetData.voidP[count] = p;
	mSetData.voidPtr[count] = ptr;
	count++;
	return true;
}

bool Azul::Registration::Find(void* p, Heap*& heapLoc)
{
	if (set.find(p) == set.end())
	{
		heapLoc = nullptr;
		return false;
	}
	else
	{
		for (int i = 0; i < ReserveSize; i++)
		{
			if (mSetData.voidPtr[i] == p)
			{
				heapLoc = this->mSetData.heapPtr[i];
				break;
			}
		}
		return true;
	}
}

bool Azul::Registration::UnRegister(void* p)
{
	set.erase(p);
	return true;
}
