//---------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//---------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MemEngine.h"

using namespace Azul;

//---------------------------------------------------------------------------
// Test Files:
// Single step, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(Add4Heaps_RemoveMiddleHeap, TestConfig::VERSION_CHECK)
{
#if Add4Heaps_RemoveMiddleHeap

	// Initialize the memory system
	Mem::Create();

	// Test the mem Info structures
	Mem::Info mem_Info;

	// Yes it works.
	Mem::GetInfo(mem_Info);

	Mem::Code memResult;
	// create the heap by using the memory system
	Heap *heap_A;
	memResult = Mem::NormalHeap(heap_A, 1 * 1024 * 1024, "HEAP_A");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_A);
	CHECK(heap_A->GetHeapType() == Heap::Type::NORMAL);

	// create the heap by using the memory system
	Heap *heap_B;
	memResult = Mem::NormalHeap(heap_B, 2 * 1024 * 1024, "HEAP_B");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_B);
	CHECK(heap_B->GetHeapType() == Heap::Type::NORMAL);

	// create the heap by using the memory system
	Heap *heap_C;
	memResult = Mem::NormalHeap(heap_C, 3 * 1024 * 1024, "HEAP_C");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_C);
	CHECK(heap_C->GetHeapType() == Heap::Type::NORMAL);

	// create the heap by using the memory system
	Heap *heap_D;
	memResult = Mem::NormalHeap(heap_D, 4 * 1024 * 1024, "HEAP_D");
	CHECK(memResult == Mem::Code::OK);

	CHECK(heap_D);
	CHECK(heap_D->GetHeapType() == Heap::Type::NORMAL);

	// Get the stats
	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 0);
	CHECK(mem_Info.CurrHeapCount == 4);
	CHECK(mem_Info.CurrNumAlloc == 0);
	CHECK(mem_Info.PeakBytesUsed == 0);
	CHECK(mem_Info.PeakHeapCount == 4);
	CHECK(mem_Info.PeakNumAlloc == 0);

	// Now walk through the heaps, make sure there is 4 of them
	Heap *hTmp;

	// get the head
	hTmp = Mem::DebugGetHeapHead();

	CHECK(hTmp != nullptr);

	CHECK(hTmp == heap_D);
	CHECK(hTmp->DebugGetNext() == heap_C);
	CHECK(hTmp->DebugGetPrev() == nullptr);

	hTmp = hTmp->DebugGetNext();

	CHECK(hTmp == heap_C);
	CHECK(hTmp->DebugGetNext() == heap_B);
	CHECK(hTmp->DebugGetPrev() == heap_D);

	hTmp = hTmp->DebugGetNext();

	CHECK(hTmp == heap_B);
	CHECK(hTmp->DebugGetNext() == heap_A);
	CHECK(hTmp->DebugGetPrev() == heap_C);

	hTmp = hTmp->DebugGetNext();

	CHECK(hTmp == heap_A);
	CHECK(hTmp->DebugGetNext() == nullptr);
	CHECK(hTmp->DebugGetPrev() == heap_B);

	// Now remove middle
	Mem::RemoveHeap(heap_B);

	// Get the stats
	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 0);
	CHECK(mem_Info.CurrHeapCount == 3);
	CHECK(mem_Info.CurrNumAlloc == 0);
	CHECK(mem_Info.PeakBytesUsed == 0);
	CHECK(mem_Info.PeakHeapCount == 4);
	CHECK(mem_Info.PeakNumAlloc == 0);

	// Now walk through the heaps, make sure there is 3 of them

	// get the head
	hTmp = Mem::DebugGetHeapHead();

	CHECK(hTmp != nullptr);

	CHECK(hTmp == heap_D);
	CHECK(hTmp->DebugGetNext() == heap_C);
	CHECK(hTmp->DebugGetPrev() == nullptr);

	hTmp = hTmp->DebugGetNext();

	CHECK(hTmp == heap_C);
	CHECK(hTmp->DebugGetNext() == heap_A);
	CHECK(hTmp->DebugGetPrev() == heap_D);

	hTmp = hTmp->DebugGetNext();

	CHECK(hTmp == heap_A);
	CHECK(hTmp->DebugGetNext() == nullptr);
	CHECK(hTmp->DebugGetPrev() == heap_C);

	Mem::Destroy();

#endif
}TEST_END

// --- End of File ---
