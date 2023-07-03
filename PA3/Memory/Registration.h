#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <unordered_set>
#include <Heap.h>
#include <Mem.h>

namespace Azul
{
	class Registration
	{
	public:
		static const unsigned int ReserveSize = 256;

		struct setData
		{
			Heap* heapPtr[ReserveSize];
			void* voidP[ReserveSize];
			void* voidPtr[ReserveSize];
		};


	public:
		Registration();
		Registration(const Registration &) = delete;
		Registration& operator = (const Registration&) = delete;
		~Registration();

		bool Register(void* p, void* ptr, Heap* heap);
		bool Find(void* p, Heap*& heapLoc);
		bool UnRegister(void* p);

		std::unordered_set<void *>set;

		setData mSetData;
		Block* mBlock;
		int count = 0;
	};
}

#endif