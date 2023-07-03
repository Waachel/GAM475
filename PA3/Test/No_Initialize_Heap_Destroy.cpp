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

TEST(No_Initialize_Heap_Destroy, TestConfig::VERSION_CHECK)
{
#if No_Initialize_Heap_Destroy

	// Initialize the memory system
	//Mem::Initialize();  <--- commented out on purpose

	// Create a heap pointer (someday make it a handle)
	Heap *heap_A = (Heap *)0x1; //  just for this test (bogus pointer)

	// create the heap by using the memory system
	Mem::Code memResult;
	memResult = Mem::RemoveHeap(heap_A);

	CHECK(memResult == Mem::Code::ERROR_Mem_Not_Initialized);

#endif
}TEST_END


// ---  End of File ---------------
