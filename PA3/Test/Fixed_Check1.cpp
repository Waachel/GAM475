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

TEST(fixed_check1, TestConfig::VERSION_CHECK)
{
#if fixed_check1

	// Initialize the memory system
	Mem::Create();

	// create heap
	Heap *heap_A;
	Mem::Code memResult;
	memResult = Mem::FixedHeap(heap_A, 100, 200, "HEAP_A_FIXBLOCK");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::FIXED);

	Mem::Info info;

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


	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 10);
	CHECK(info.CurrBytesUsed == 10 * (200));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 10);
	CHECK(info.PeakBytesUsed == 10 * (200));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 10);

	delete pA2;
	delete pA4;
	delete pA5;
	delete pA7;

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 10);
	CHECK(info.CurrBytesUsed == 6 * (200));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 6);
	CHECK(info.PeakBytesUsed == 10 * (200));
	CHECK(info.PeakHeapCount == 1);
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
	CHECK((size_t)pB0 == ((size_t)pA0 + 7 * (200 + sizeof(Block))));
	CHECK((size_t)pB1 == ((size_t)pA0 + 5 * (200 + sizeof(Block))));
	CHECK((size_t)pB2 == ((size_t)pA0 + 4 * (200 + sizeof(Block))));
	CHECK((size_t)pB3 == ((size_t)pA0 + 2 * (200 + sizeof(Block))));
	CHECK((size_t)pB4 == ((size_t)pA0 + 10 * (200 + sizeof(Block))));
	CHECK((size_t)pB5 == ((size_t)pA0 + 11 * (200 + sizeof(Block))));
	CHECK((size_t)pB6 == ((size_t)pA0 + 12 * (200 + sizeof(Block))));
	CHECK((size_t)pB7 == ((size_t)pA0 + 13 * (200 + sizeof(Block))));
	CHECK((size_t)pB8 == ((size_t)pA0 + 14 * (200 + sizeof(Block))));
	CHECK((size_t)pB9 == ((size_t)pA0 + 15 * (200 + sizeof(Block))));

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 20);
	CHECK(info.CurrBytesUsed == 16 * (200));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 16);
	CHECK(info.PeakBytesUsed == 16 * (200));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 16);

	delete pB2;
	delete pB4;
	delete pB5;
	delete pB6;

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 20);
	CHECK(info.CurrBytesUsed == 12 * (200));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 12);
	CHECK(info.PeakBytesUsed == 16 * (200));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 16);

	char *pC0 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC1 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC2 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC3 = new(heap_A, __FILE__, __LINE__) char[200];
	char *pC4 = new(heap_A, __FILE__, __LINE__) char[200];

	CHECK(TEST_4_BYTE(pC0));
	CHECK(TEST_4_BYTE(pC1));
	CHECK(TEST_4_BYTE(pC2));
	CHECK(TEST_4_BYTE(pC3));
	CHECK(TEST_4_BYTE(pC4));

	// datum - pA0
	CHECK(pA0);

	// Make sure they are next to each other
	CHECK((size_t)pC0 == ((size_t)pA0 + 12 * (200 + sizeof(Block))));
	CHECK((size_t)pC1 == ((size_t)pA0 + 11 * (200 + sizeof(Block))));
	CHECK((size_t)pC2 == ((size_t)pA0 + 10 * (200 + sizeof(Block))));
	CHECK((size_t)pC3 == ((size_t)pA0 + 4 * (200 + sizeof(Block))));
	CHECK((size_t)pC4 == ((size_t)pA0 + 16 * (200 + sizeof(Block))));

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 25);
	CHECK(info.CurrBytesUsed == 17 * (200));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 17);
	CHECK(info.PeakBytesUsed == 17 * (200));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 17);

	Mem::Destroy();

#endif
} TEST_END

// --- End of File ---
