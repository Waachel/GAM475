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


TEST(Initialize_MemorySystem, TestConfig::VERSION_CHECK)
{
#if Initialize_MemorySystem
	// Initialize the memory system
	Mem::Create();

	// Test the mem Info structures
	Mem::Info mem_Info;

	// Yes it works.
	Mem::GetInfo(mem_Info);

	CHECK(mem_Info.CurrBytesUsed == 0);
	CHECK(mem_Info.CurrHeapCount == 0);
	CHECK(mem_Info.CurrNumAlloc == 0);
	CHECK(mem_Info.PeakBytesUsed == 0);
	CHECK(mem_Info.PeakHeapCount == 0);
	CHECK(mem_Info.PeakNumAlloc == 0);

	Mem::Destroy();

#endif
}TEST_END


// ---  End of File ---------------
