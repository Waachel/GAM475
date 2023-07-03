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

#define TEST_4_BYTE(ptr)      ( ((size_t)ptr & 0x03) == 0 )
#define TEST_8_BYTE(ptr)      ( ((size_t)ptr & 0x07) == 0 )
#define TEST_16_BYTE(ptr)     ( ((size_t)ptr & 0x0F) == 0 )
#define TEST_32_BYTE(ptr)     ( ((size_t)ptr & 0x1F) == 0 )
#define TEST_64_BYTE(ptr)     ( ((size_t)ptr & 0x3F) == 0 )
#define TEST_128_BYTE(ptr)    ( ((size_t)ptr & 0x7F) == 0 )
#define TEST_256_BYTE(ptr)    ( ((size_t)ptr & 0xFF) == 0 )

//---------------------------------------------------------------------------
// Test Files:
// Single step, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(test1_heapcCheck3, TestConfig::VERSION_CHECK)
{
#if test1_heapcCheck3

	// Initialize the memory system
	Mem::Create();

	// create heap
	Mem::Code memResult;

	Heap *heap_A;
	memResult = Mem::NormalHeap(heap_A, 100 * 1024, "HEAP_A");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::NORMAL);

	Heap *heap_B;
	memResult = Mem::NormalHeap(heap_B, 50 * 1024, "HEAP_B");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_B);
	CHECK(heap_B->GetHeapType() == Heap::Type::NORMAL);

	Heap *heap_C;
	memResult = Mem::NormalHeap(heap_C, 500 * 1024, "HEAP_C");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_C);
	CHECK(heap_C->GetHeapType() == Heap::Type::NORMAL);

	char *p0 = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) char[300];
	char *p1 = new(heap_B, Mem::Align::Byte_4, __FILE__, __LINE__) char[200];
	char *p2 = new(heap_B, Mem::Align::Byte_4, __FILE__, __LINE__) char[5 * 1024];
	char *p3 = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) char[60 * 1024];
	char *p4 = new(heap_C, Mem::Align::Byte_4, __FILE__, __LINE__) char[200 * 1024];
	char *p5 = new(heap_C, Mem::Align::Byte_4, __FILE__, __LINE__) char[8 * 1024];
	char *p6 = new(heap_B, Mem::Align::Byte_4, __FILE__, __LINE__) char[15 * 1024];
	char *p7 = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) char[10 * 1024];

	CHECK(TEST_4_BYTE(p0));
	CHECK(TEST_4_BYTE(p1));
	CHECK(TEST_4_BYTE(p2));
	CHECK(TEST_4_BYTE(p3));
	CHECK(TEST_4_BYTE(p4));
	CHECK(TEST_4_BYTE(p5));
	CHECK(TEST_4_BYTE(p6));
	CHECK(TEST_4_BYTE(p7));

	Mem::Info info;
	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 8);
	CHECK(info.CurrBytesUsed == (5 + 60 + 200 + 8 + 15 + 10) * 1024 + (200 + 300));
	CHECK(info.CurrHeapCount == 3);
	CHECK(info.CurrNumAlloc == 8);
	CHECK(info.PeakBytesUsed == (5 + 60 + 200 + 8 + 15 + 10) * 1024 + (200 + 300));
	CHECK(info.PeakHeapCount == 3);
	CHECK(info.PeakNumAlloc == 8);

	// CHECK the memory of each HEAP
	Heap::Info HeapInfo;

	heap_A->GetInfo(HeapInfo);
	CHECK(HeapInfo.CurrBytesUsed == (60 + 10) * 1024 + 300);
	CHECK(HeapInfo.CurrNumAlloc == 3);
	CHECK(strcmp(HeapInfo.Name, "HEAP_A") == 0);
	CHECK(HeapInfo.PeakBytesUsed == (60 + 10) * 1024 + 300);
	CHECK(HeapInfo.PeakNumAlloc == 3);
	CHECK(HeapInfo.TotalSize == 100 * 1024);

	heap_B->GetInfo(HeapInfo);
	CHECK(HeapInfo.CurrBytesUsed == (5 + 15) * 1024 + 200);
	CHECK(HeapInfo.CurrNumAlloc == 3);
	CHECK(strcmp(HeapInfo.Name, "HEAP_B") == 0);
	CHECK(HeapInfo.PeakBytesUsed == (5 + 15) * 1024 + 200);
	CHECK(HeapInfo.PeakNumAlloc == 3);
	CHECK(HeapInfo.TotalSize == 50 * 1024);

	heap_C->GetInfo(HeapInfo);
	CHECK(HeapInfo.CurrBytesUsed == (200 + 8) * 1024);
	CHECK(HeapInfo.CurrNumAlloc == 2);
	CHECK(strcmp(HeapInfo.Name, "HEAP_C") == 0);
	CHECK(HeapInfo.PeakBytesUsed == (200 + 8) * 1024);
	CHECK(HeapInfo.PeakNumAlloc == 2);
	CHECK(HeapInfo.TotalSize == 500 * 1024);

	delete p0;
	delete p3;
	delete p7;
	delete p1;
	delete p4;

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 8);
	CHECK(info.CurrBytesUsed == (15 + 5 + 8) * 1024);
	CHECK(info.CurrHeapCount == 3);
	CHECK(info.CurrNumAlloc == 3);
	CHECK(info.PeakBytesUsed == (5 + 60 + 200 + 8 + 15 + 10) * 1024 + (200 + 300));
	CHECK(info.PeakHeapCount == 3);
	CHECK(info.PeakNumAlloc == 8);

	heap_A->GetInfo(HeapInfo);
	CHECK(HeapInfo.CurrBytesUsed == 0);
	CHECK(HeapInfo.CurrNumAlloc == 0);
	CHECK(strcmp(HeapInfo.Name, "HEAP_A") == 0);
	CHECK(HeapInfo.PeakBytesUsed == (60 + 10) * 1024 + 300);
	CHECK(HeapInfo.PeakNumAlloc == 3);
	CHECK(HeapInfo.TotalSize == 100 * 1024);

	heap_B->GetInfo(HeapInfo);
	CHECK(HeapInfo.CurrBytesUsed == (15 + 5) * 1024);
	CHECK(HeapInfo.CurrNumAlloc == 2);
	CHECK(strcmp(HeapInfo.Name, "HEAP_B") == 0);
	CHECK(HeapInfo.PeakBytesUsed == (5 + 15) * 1024 + 200);
	CHECK(HeapInfo.PeakNumAlloc == 3);
	CHECK(HeapInfo.TotalSize == 50 * 1024);

	heap_C->GetInfo(HeapInfo);
	CHECK(HeapInfo.CurrBytesUsed == 8 * 1024);
	CHECK(HeapInfo.CurrNumAlloc == 1);
	CHECK(strcmp(HeapInfo.Name, "HEAP_C") == 0);
	CHECK(HeapInfo.PeakBytesUsed == (200 + 8) * 1024);
	CHECK(HeapInfo.PeakNumAlloc == 2);
	CHECK(HeapInfo.TotalSize == 500 * 1024);

	Mem::RemoveHeap(heap_A);
	Mem::RemoveHeap(heap_B);
	Mem::RemoveHeap(heap_C);

	Mem::GetInfo(info);

	// CHECK the global memory
	CHECK(info.CurrAllocIndex == 8);
	CHECK(info.CurrBytesUsed == 0);
	CHECK(info.CurrHeapCount == 0);
	CHECK(info.CurrNumAlloc == 0);
	CHECK(info.PeakBytesUsed == (5 + 60 + 200 + 8 + 15 + 10) * 1024 + (200 + 300));
	CHECK(info.PeakHeapCount == 3);
	CHECK(info.PeakNumAlloc == 8);

	Mem::Destroy();

#endif
} TEST_END

// --- End of File ---
