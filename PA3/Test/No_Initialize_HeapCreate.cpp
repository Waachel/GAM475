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

TEST(No_Initialize_HeapCreate, TestConfig::VERSION_CHECK)
{
#if No_Initialize_HeapCreate
	// Initialize the memory system
	//Mem::Initialize();  <--- commented out on purpose

	// Create a heap pointer (someday make it a handle)
	Heap *heap_A;

	// create the heap by using the memory system
	Mem::Code memResult;
	memResult = Mem::NormalHeap(heap_A, 2 * 1024 * 1024, "HEAP_A");

	CHECK(memResult == Mem::Code::ERROR_Mem_Not_Initialized);

	CHECK(heap_A == nullptr);

#endif
}TEST_END


// ---  End of File ---------------
