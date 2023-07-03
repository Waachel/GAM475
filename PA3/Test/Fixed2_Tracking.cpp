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

TEST(Fixed2_Tracking, TestConfig::VERSION_CHECK)
{
#if Fixed2_Tracking

	// Initialize the memory system
	Mem::Create();

	// Test the mem Info structures
	Mem::Info mem_Info;

	// Yes it works.
	Mem::GetInfo(mem_Info);

	// validate it
	CHECK(mem_Info.CurrBytesUsed == 0);
	CHECK(mem_Info.CurrHeapCount == 0);
	CHECK(mem_Info.CurrNumAlloc == 0);
	CHECK(mem_Info.PeakBytesUsed == 0);
	CHECK(mem_Info.PeakHeapCount == 0);
	CHECK(mem_Info.PeakNumAlloc == 0);

	// create heap
	Heap *heap_A;
	Mem::Code memResult;
	memResult = Mem::FixedHeap(heap_A, 100, sizeof(Dog), "HEAP_A_FIXBLOCK");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::FIXED);

	Mem::Info info;

	Dog *pA0 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA1 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA2 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA3 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA4 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA5 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA6 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA7 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA8 = new(heap_A, __FILE__, __LINE__) Dog();
	Dog *pA9 = new(heap_A, __FILE__, __LINE__) Dog();

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
	CHECK((size_t)pA1 == ((size_t)pA0 + (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA2 == ((size_t)pA0 + 2 * (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA3 == ((size_t)pA0 + 3 * (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA4 == ((size_t)pA0 + 4 * (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA5 == ((size_t)pA0 + 5 * (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA6 == ((size_t)pA0 + 6 * (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA7 == ((size_t)pA0 + 7 * (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA8 == ((size_t)pA0 + 8 * (sizeof(Dog) + sizeof(Block))));
	CHECK((size_t)pA9 == ((size_t)pA0 + 9 * (sizeof(Dog) + sizeof(Block))));

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 10);
	CHECK(info.CurrBytesUsed == 10 * sizeof(Dog));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 10);
	CHECK(info.PeakBytesUsed == 10 * sizeof(Dog));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 10);

	delete pA0;
	delete pA8;
	delete pA3;
	delete pA7;
	delete pA5;
	delete pA9;

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 10);
	CHECK(info.CurrBytesUsed == 4 * sizeof(Dog));
	CHECK(info.CurrHeapCount == 1);
	CHECK(info.CurrNumAlloc == 4);
	CHECK(info.PeakBytesUsed == 10 * sizeof(Dog));
	CHECK(info.PeakHeapCount == 1);
	CHECK(info.PeakNumAlloc == 10);

	// OK, now all 5 allocations are created, now look at track info from heap.
	Block *t0 = Mem::DebugGetGlobalTrackingHead();

	CHECK(t0 != nullptr);
	CHECK(t0->GetAllocIndex() == 7);
	CHECK(strcmp(t0->GetFileName(), "Fixed2_Tracking.cpp") == 0);
	CHECK(t0->GetLineNum() == 63);
	CHECK(t0->GetGlobalPrev() == nullptr);
	CHECK(t0->GetGlobalNext() != nullptr);

	Block *t1 = t0->GetGlobalNext();

	CHECK(t1 != nullptr);
	CHECK(t1->GetAllocIndex() == 5);
	CHECK(strcmp(t1->GetFileName(), "Fixed2_Tracking.cpp") == 0);
	CHECK(t1->GetLineNum() == 61);
	CHECK(t1->GetGlobalPrev() == t0);
	CHECK(t1->GetGlobalNext() != nullptr);
	CHECK(t0->GetGlobalNext() == t1);

	Block *t2 = t1->GetGlobalNext();

	CHECK(t2 != nullptr);
	CHECK(t2->GetAllocIndex() == 3);
	CHECK(strcmp(t2->GetFileName(), "Fixed2_Tracking.cpp") == 0);
	CHECK(t2->GetLineNum() == 59);
	CHECK(t2->GetGlobalPrev() == t1);
	CHECK(t2->GetGlobalNext() != nullptr);
	CHECK(t1->GetGlobalNext() == t2);

	Block *t3 = t2->GetGlobalNext();

	CHECK(t3 != nullptr);
	CHECK(t3->GetAllocIndex() == 2);
	CHECK(strcmp(t3->GetFileName(), "Fixed2_Tracking.cpp") == 0);
	CHECK(t3->GetLineNum() == 58);
	CHECK(t3->GetGlobalPrev() == t2);
	CHECK(t3->GetGlobalNext() == nullptr);
	CHECK(t2->GetGlobalNext() == t3);

	Mem::Destroy();

#endif
} TEST_END

// --- End of File ---
