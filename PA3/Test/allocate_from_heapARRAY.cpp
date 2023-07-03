//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MemEngine.h"
#include "Dog.h"

using namespace Azul;

//---------------------------------------------------------------------------
// Test Files:
// Single step, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(allocate_from_heapARRAY, TestConfig::VERSION_CHECK)
{
#if allocate_from_heapARRAY

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

	// Create a heap pointer (someday make it a handle)
	Heap *heap_A;

	// create the heap by using the memory system
	Mem::Code  memResult;
	memResult = Mem::NormalHeap(heap_A, 2 * 1024 * 1024, "HEAP_A");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::NORMAL);

	// Test the heap Info structures
	Heap::Info heapA_Info;

	// Yes it works.
	heap_A->GetInfo(heapA_Info);

	CHECK(heapA_Info.CurrBytesUsed == 0);
	CHECK(heapA_Info.CurrNumAlloc == 0);
	CHECK(strcmp(heapA_Info.Name, "HEAP_A") == 0);
	CHECK(heapA_Info.PeakBytesUsed == 0);
	CHECK(heapA_Info.PeakNumAlloc == 0);
	CHECK(heapA_Info.TotalSize == 2 * 1024 * 1024);

	// Yes it works.
	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 0);
	CHECK(mem_Info.CurrHeapCount == 1);
	CHECK(mem_Info.CurrNumAlloc == 0);
	CHECK(mem_Info.PeakBytesUsed == 0);
	CHECK(mem_Info.PeakHeapCount == 1);
	CHECK(mem_Info.PeakNumAlloc == 0);

	// OK at this point, we have a heap create, so let's allocate from it.

	Dog *p = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) Dog[3];

	// Yes it works.
	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 3 * sizeof(Dog) + sizeof(size_t));
	CHECK(mem_Info.CurrHeapCount == 1);
	CHECK(mem_Info.CurrNumAlloc == 1);
	CHECK(mem_Info.PeakBytesUsed == 3 * sizeof(Dog) + sizeof(size_t));
	CHECK(mem_Info.PeakHeapCount == 1);
	CHECK(mem_Info.PeakNumAlloc == 1);

	delete[] p;

	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 0);
	CHECK(mem_Info.CurrHeapCount == 1);
	CHECK(mem_Info.CurrNumAlloc == 0);
	CHECK(mem_Info.PeakBytesUsed == 3 * sizeof(Dog) + sizeof(size_t));
	CHECK(mem_Info.PeakHeapCount == 1);
	CHECK(mem_Info.PeakNumAlloc == 1);

	Mem::Destroy();

#endif
} TEST_END

// --- End of File ---
