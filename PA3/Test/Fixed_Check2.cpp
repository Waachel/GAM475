//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MemEngine.h"
#include "Dog.h"

using namespace Azul;

//--------------------------------------------------------------------------
// MACROS Test
//--------------------------------------------------------------------------

#define TEST_4_BYTE(ptr)      ( ((size_t)ptr & 0x3) == 0 )
#define TEST_8_BYTE(ptr)      ( ((size_t)ptr & 0x7) == 0 )
#define TEST_16_BYTE(ptr)     ( ((size_t)ptr & 0xF) == 0 )
#define TEST_32_BYTE(ptr)     ( ((size_t)ptr & 0x1F) == 0 )
#define TEST_64_BYTE(ptr)     ( ((size_t)ptr & 0x3F) == 0 )
#define TEST_128_BYTE(ptr)    ( ((size_t)ptr & 0x7F) == 0 )
#define TEST_256_BYTE(ptr)    ( ((size_t)ptr & 0xFF) == 0 )

//---------------------------------------------------------------------------
// Test Files:
// Single step, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(fixed_check2, TestConfig::VERSION_CHECK)
{
#if fixed_check2

	// Initialize the memory system
	Mem::Create();

	// create heap
	Heap *heap_A;
	Mem::Code memResult;
	memResult = Mem::FixedHeap(heap_A, 100, 200, "HEAP_A_FIXBLOCK");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::FIXED);

	Heap::Info info;

	char *pA0 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA1 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA2 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA3 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA4 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA5 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA6 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA7 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA8 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pA9 = new(heap_A, __FILE__, __LINE__) char[200];

	CHECK(TEST_4_BYTE(pA0));
	CHECK(TEST_4_BYTE(pA1));
	CHECK(TEST_4_BYTE(pA2));
	CHECK(TEST_4_BYTE(pA3));
	CHECK(TEST_4_BYTE(pA4));
	CHECK(TEST_4_BYTE(pA5));
	CHECK(TEST_4_BYTE(pA6));
	CHECK(TEST_4_BYTE(pA7));
	CHECK(TEST_4_BYTE(pA8));
	CHECK(TEST_4_BYTE(pA9));

	// datum - pA0
	CHECK(pA0);

	// Make sure they are next to each other
	CHECK((size_t)pA1 == ((size_t)pA0 + (200 + sizeof(Block))));
	CHECK((size_t)pA2 == ((size_t)pA0 + 2 * (200 + sizeof(Block))));
	CHECK((size_t)pA3 == ((size_t)pA0 + 3 * (200 + sizeof(Block))));
	CHECK((size_t)pA4 == ((size_t)pA0 + 4 * (200 + sizeof(Block))));
	CHECK((size_t)pA5 == ((size_t)pA0 + 5 * (200 + sizeof(Block))));
	CHECK((size_t)pA6 == ((size_t)pA0 + 6 * (200 + sizeof(Block))));
	CHECK((size_t)pA7 == ((size_t)pA0 + 7 * (200 + sizeof(Block))));
	CHECK((size_t)pA8 == ((size_t)pA0 + 8 * (200 + sizeof(Block))));
	CHECK((size_t)pA9 == ((size_t)pA0 + 9 * (200 + sizeof(Block))));

	heap_A->GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrBytesUsed == 10 * (200));
	CHECK(info.CurrNumAlloc == 10);
	CHECK(info.PeakBytesUsed == 10 * (200));
	CHECK(info.PeakNumAlloc == 10);

	char *pB0 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB1 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB2 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB3 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB4 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB5 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB6 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB7 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB8 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pB9 = new(heap_A, __FILE__, __LINE__) char[200];

	CHECK(TEST_4_BYTE(pB0));
	CHECK(TEST_4_BYTE(pB1));
	CHECK(TEST_4_BYTE(pB2));
	CHECK(TEST_4_BYTE(pB3));
	CHECK(TEST_4_BYTE(pB4));
	CHECK(TEST_4_BYTE(pB5));
	CHECK(TEST_4_BYTE(pB6));
	CHECK(TEST_4_BYTE(pB7));
	CHECK(TEST_4_BYTE(pB8));
	CHECK(TEST_4_BYTE(pB9));

	// datum - pA0
	CHECK(pA0);

	// Make sure they are next to each other
	CHECK((size_t)pB0 == ((size_t)pA0 + 10 * (200 + sizeof(Block))));
	CHECK((size_t)pB1 == ((size_t)pA0 + 11 * (200 + sizeof(Block))));
	CHECK((size_t)pB2 == ((size_t)pA0 + 12 * (200 + sizeof(Block))));
	CHECK((size_t)pB3 == ((size_t)pA0 + 13 * (200 + sizeof(Block))));
	CHECK((size_t)pB4 == ((size_t)pA0 + 14 * (200 + sizeof(Block))));
	CHECK((size_t)pB5 == ((size_t)pA0 + 15 * (200 + sizeof(Block))));
	CHECK((size_t)pB6 == ((size_t)pA0 + 16 * (200 + sizeof(Block))));
	CHECK((size_t)pB7 == ((size_t)pA0 + 17 * (200 + sizeof(Block))));
	CHECK((size_t)pB8 == ((size_t)pA0 + 18 * (200 + sizeof(Block))));
	CHECK((size_t)pB9 == ((size_t)pA0 + 19 * (200 + sizeof(Block))));

	heap_A->GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrBytesUsed == 20 * (200));
	CHECK(info.CurrNumAlloc == 20);
	CHECK(info.PeakBytesUsed == 20 * (200));
	CHECK(info.PeakNumAlloc == 20);

	char *pC0 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC1 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC2 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC3 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC4 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC5 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC6 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC7 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC8 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC9 = new(heap_A, __FILE__, __LINE__) char[200];

	CHECK(TEST_4_BYTE(pC0));
	CHECK(TEST_4_BYTE(pC1));
	CHECK(TEST_4_BYTE(pC2));
	CHECK(TEST_4_BYTE(pC3));
	CHECK(TEST_4_BYTE(pC4));
	CHECK(TEST_4_BYTE(pC5));
	CHECK(TEST_4_BYTE(pC6));
	CHECK(TEST_4_BYTE(pC7));
	CHECK(TEST_4_BYTE(pC8));
	CHECK(TEST_4_BYTE(pC9));

	// datum - pA0
	CHECK(pA0);

	// Make sure they are next to each other
	CHECK((size_t)pC0 == ((size_t)pA0 + 20 * (200 + sizeof(Block))));
	CHECK((size_t)pC1 == ((size_t)pA0 + 21 * (200 + sizeof(Block))));
	CHECK((size_t)pC2 == ((size_t)pA0 + 22 * (200 + sizeof(Block))));
	CHECK((size_t)pC3 == ((size_t)pA0 + 23 * (200 + sizeof(Block))));
	CHECK((size_t)pC4 == ((size_t)pA0 + 24 * (200 + sizeof(Block))));
	CHECK((size_t)pC5 == ((size_t)pA0 + 25 * (200 + sizeof(Block))));
	CHECK((size_t)pC6 == ((size_t)pA0 + 26 * (200 + sizeof(Block))));
	CHECK((size_t)pC7 == ((size_t)pA0 + 27 * (200 + sizeof(Block))));
	CHECK((size_t)pC8 == ((size_t)pA0 + 28 * (200 + sizeof(Block))));
	CHECK((size_t)pC9 == ((size_t)pA0 + 29 * (200 + sizeof(Block))));

	heap_A->GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrBytesUsed == 30 * (200));
	CHECK(info.CurrNumAlloc == 30);
	CHECK(info.PeakBytesUsed == 30 * (200));
	CHECK(info.PeakNumAlloc == 30);

	delete pA2;
	delete pB2;
	delete pC2;
	delete pA4;
	delete pB4;
	delete pC4;
	delete pA8;
	delete pB8;
	delete pC8;
	delete pA0;

	heap_A->GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrBytesUsed == 20 * (200));
	CHECK(info.CurrNumAlloc == 20);
	CHECK(info.PeakBytesUsed == 30 * (200));
	CHECK(info.PeakNumAlloc == 30);

	char *pD0 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD1 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD2 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD3 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD4 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD5 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD6 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD7 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD8 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pD9 = new(heap_A, __FILE__, __LINE__) char[200];

	CHECK(TEST_4_BYTE(pD0));
	CHECK(TEST_4_BYTE(pD1));
	CHECK(TEST_4_BYTE(pD2));
	CHECK(TEST_4_BYTE(pD3));
	CHECK(TEST_4_BYTE(pD4));
	CHECK(TEST_4_BYTE(pD5));
	CHECK(TEST_4_BYTE(pD6));
	CHECK(TEST_4_BYTE(pD7));
	CHECK(TEST_4_BYTE(pD8));
	CHECK(TEST_4_BYTE(pD9));

	// datum - pA0
	CHECK(pD0);

	// Make sure they are next to each other
	CHECK((size_t)pD0 == ((size_t)pD0 + 0 * (200 + sizeof(Block))));
	CHECK((size_t)pD1 == ((size_t)pD0 + 28 * (200 + sizeof(Block))));
	CHECK((size_t)pD2 == ((size_t)pD0 + 18 * (200 + sizeof(Block))));
	CHECK((size_t)pD3 == ((size_t)pD0 + 8 * (200 + sizeof(Block))));
	CHECK((size_t)pD4 == ((size_t)pD0 + 24 * (200 + sizeof(Block))));
	CHECK((size_t)pD5 == ((size_t)pD0 + 14 * (200 + sizeof(Block))));
	CHECK((size_t)pD6 == ((size_t)pD0 + 4 * (200 + sizeof(Block))));
	CHECK((size_t)pD7 == ((size_t)pD0 + 22 * (200 + sizeof(Block))));
	CHECK((size_t)pD8 == ((size_t)pD0 + 12 * (200 + sizeof(Block))));
	CHECK((size_t)pD9 == ((size_t)pD0 + 2 * (200 + sizeof(Block))));

	heap_A->GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrBytesUsed == 30 * (200));
	CHECK(info.CurrNumAlloc == 30);
	CHECK(info.PeakBytesUsed == 30 * (200));
	CHECK(info.PeakNumAlloc == 30);

	delete pA1;
	delete pB1;
	delete pC1;
	delete pD1;
	delete pD2;

	heap_A->GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrBytesUsed == 25 * (200));
	CHECK(info.CurrNumAlloc == 25);
	CHECK(info.PeakBytesUsed == 30 * (200));
	CHECK(info.PeakNumAlloc == 30);

	char *pE0 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE1 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE2 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE3 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE4 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE5 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE6 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE7 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE8 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pE9 = new(heap_A, __FILE__, __LINE__) char[200];

	CHECK(TEST_4_BYTE(pE0));
	CHECK(TEST_4_BYTE(pE1));
	CHECK(TEST_4_BYTE(pE2));
	CHECK(TEST_4_BYTE(pE3));
	CHECK(TEST_4_BYTE(pE4));
	CHECK(TEST_4_BYTE(pE5));
	CHECK(TEST_4_BYTE(pE6));
	CHECK(TEST_4_BYTE(pE7));
	CHECK(TEST_4_BYTE(pE8));
	CHECK(TEST_4_BYTE(pE9));

	// datum - pA0
	CHECK(pD0);

	heap_A->GetInfo(info);

	// Make sure they are next to each other
	CHECK((size_t)pE0 == ((size_t)pD0 + 18 * (200 + sizeof(Block))));
	CHECK((size_t)pE1 == ((size_t)pD0 + 28 * (200 + sizeof(Block))));
	CHECK((size_t)pE2 == ((size_t)pD0 + 21 * (200 + sizeof(Block))));
	CHECK((size_t)pE3 == ((size_t)pD0 + 11 * (200 + sizeof(Block))));
	CHECK((size_t)pE4 == ((size_t)pD0 + 1 * (200 + sizeof(Block))));
	CHECK((size_t)pE5 == ((size_t)pD0 + 30 * (200 + sizeof(Block))));
	CHECK((size_t)pE6 == ((size_t)pD0 + 31 * (200 + sizeof(Block))));
	CHECK((size_t)pE7 == ((size_t)pD0 + 32 * (200 + sizeof(Block))));
	CHECK((size_t)pE8 == ((size_t)pD0 + 33 * (200 + sizeof(Block))));
	CHECK((size_t)pE9 == ((size_t)pD0 + 34 * (200 + sizeof(Block))));

	heap_A->GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrBytesUsed == 35 * (200));
	CHECK(info.CurrNumAlloc == 35);
	CHECK(info.PeakBytesUsed == 35 * (200));
	CHECK(info.PeakNumAlloc == 35);

	Mem::Destroy();

#endif
} TEST_END

//--- End of File ---
