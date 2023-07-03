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

TEST(No_Initialize_GetHeapByAddr, TestConfig::VERSION_CHECK)
{
#if No_Initialize_GetHeapByAddr

	// Initialize the memory system
	//Mem::Initialize();  <--- uninitialized on purpose

	// Create a heap pointer (someday make it a handle)
	Heap *heap_A = nullptr;

	// create the heap by using the memory system
	Mem::Code memResult;
	memResult = Mem::GetHeapByAddr(heap_A, (void *)0x1);

	CHECK(memResult == Mem::Code::ERROR_Mem_Not_Initialized);

#endif
}TEST_END

// --- End of File ---
