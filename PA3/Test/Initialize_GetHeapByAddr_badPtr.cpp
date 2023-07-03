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

TEST(Initialize_GetHeapByAddr_badPtr, TestConfig::VERSION_CHECK)
{
#if Initialize_GetHeapByAddr_badPtr

	// Initialize the memory system
	Mem::Create();

	// Create a heap pointer (someday make it a handle)
	Heap *heap_A = nullptr;

	// create the heap by using the memory system
	Mem::Code memResult;
	memResult = Mem::GetHeapByAddr(heap_A, (void *)0x1);

	CHECK(memResult == Mem::Code::ERROR_Invalid_Addr);

	Mem::Destroy();

#endif
}TEST_END

// --- End of File ---
