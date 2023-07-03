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
TEST(Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global, TestConfig::VERSION_CHECK)
{
#if Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global

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
	Mem::Code memResult;
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

	Dog *p0 = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) Dog();
	Dog *p1 = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) Dog();
	Dog *p2 = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) Dog();
	Dog *p3 = new(heap_A, Mem::Align::Byte_4, __FILE__, __LINE__) Dog();

	// Yes it works.
	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 4 * sizeof(Dog));
	CHECK(mem_Info.CurrHeapCount == 1);
	CHECK(mem_Info.CurrNumAlloc == 4);
	CHECK(mem_Info.PeakBytesUsed == 4 * sizeof(Dog));
	CHECK(mem_Info.PeakHeapCount == 1);
	CHECK(mem_Info.PeakNumAlloc == 4);

	// OK, now all 4 allocations are created, now look at track info from heap.
	Block *t0 = Mem::DebugGetGlobalTrackingHead();

	CHECK(t0 != nullptr);
	CHECK(t0->GetAllocIndex() == 4);
	CHECK(strcmp(t0->GetFileName(), "Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global.cpp") == 0);
	CHECK(t0->GetLineNum() == 73);
	CHECK(t0->GetGlobalPrev() == nullptr);
	CHECK(t0->GetGlobalNext() != nullptr);

	Block *t1 = t0->GetGlobalNext();

	CHECK(t1 != nullptr);
	CHECK(t1->GetAllocIndex() == 3);
	CHECK(strcmp(t1->GetFileName(), "Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global.cpp") == 0);
	CHECK(t1->GetLineNum() == 72);
	CHECK(t1->GetGlobalPrev() == t0);
	CHECK(t1->GetGlobalNext() != nullptr);
	CHECK(t0->GetGlobalNext() == t1);

	Block *t2 = t1->GetGlobalNext();

	CHECK(t2 != nullptr);
	CHECK(t2->GetAllocIndex() == 2);
	CHECK(strcmp(t2->GetFileName(), "Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global.cpp") == 0);
	CHECK(t2->GetLineNum() == 71);
	CHECK(t2->GetGlobalPrev() == t1);
	CHECK(t2->GetGlobalNext() != nullptr);
	CHECK(t1->GetGlobalNext() == t2);

	Block *t3 = t2->GetGlobalNext();

	CHECK(t3 != nullptr);
	CHECK(t3->GetAllocIndex() == 1);
	CHECK(strcmp(t3->GetFileName(), "Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global.cpp") == 0);
	CHECK(t3->GetLineNum() == 70);
	CHECK(t3->GetGlobalPrev() == t2);
	CHECK(t3->GetGlobalNext() == nullptr);
	CHECK(t2->GetGlobalNext() == t3);

	// Now remove the last one --------------------------------------------

	delete p2;

	// Yes it works.
	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 3 * sizeof(Dog));
	CHECK(mem_Info.CurrHeapCount == 1);
	CHECK(mem_Info.CurrNumAlloc == 3);
	CHECK(mem_Info.PeakBytesUsed == 4 * sizeof(Dog));
	CHECK(mem_Info.PeakHeapCount == 1);
	CHECK(mem_Info.PeakNumAlloc == 4);

	// OK, now all 4 allocations are created 1 deleted, now look at track info from heap.
	t0 = Mem::DebugGetGlobalTrackingHead();

	CHECK(t0 != 0);
	CHECK(t0->GetAllocIndex() == 4);
	CHECK(strcmp(t0->GetFileName(), "Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global.cpp") == 0);
	CHECK(t0->GetLineNum() == 73);
	CHECK(t0->GetGlobalPrev() == 0);
	CHECK(t0->GetGlobalNext() != 0);

	t1 = t0->GetGlobalNext();

	CHECK(t1 != nullptr);
	CHECK(t1->GetAllocIndex() == 2);
	CHECK(strcmp(t1->GetFileName(), "Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global.cpp") == 0);
	CHECK(t1->GetLineNum() == 71);
	CHECK(t1->GetGlobalPrev() == t0);
	CHECK(t1->GetGlobalNext() != nullptr);
	CHECK(t0->GetGlobalNext() == t1);

	t2 = t1->GetGlobalNext();

	CHECK(t2 != nullptr);
	CHECK(t2->GetAllocIndex() == 1);
	CHECK(strcmp(t2->GetFileName(), "Add4Allocs_RemoveMiddle_TrackingThroughHeap_Global.cpp") == 0);
	CHECK(t2->GetLineNum() == 70);
	CHECK(t2->GetGlobalPrev() == t1);
	CHECK(t2->GetGlobalNext() == nullptr);
	CHECK(t1->GetGlobalNext() == t2);

	t3 = t2->GetGlobalNext();

	CHECK(t3 == nullptr);

	delete p0;
	delete p1;
	delete p3;

	Mem::Destroy();

#endif
} TEST_END

// --- End of File ---
