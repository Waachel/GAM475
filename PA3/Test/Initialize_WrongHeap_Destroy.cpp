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

TEST(Initialize_WrongHeap_Destroy, TestConfig::VERSION_CHECK)
{
#if Initialize_WrongHeap_Destroy

	// Initialize the memory system
	Mem::Create();

	// Create a heap pointer (someday make it a handle)
	Heap *heap_A = (Heap *)0x33; //  just for this test (bogus pointer)

	// create the heap by using the memory system
	Mem::Code memResult;
	memResult = Mem::RemoveHeap(heap_A);

	CHECK(memResult == Mem::Code::ERROR_Illegal_Heap);

	Mem::Destroy();

#endif
}TEST_END

// --- End of File ---
