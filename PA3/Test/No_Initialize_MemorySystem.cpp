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


TEST(No_Initialize_MemorySystem, TestConfig::VERSION_CHECK)
{
#if No_Initialize_MemorySystem
	// Initialize the memory system
	//Mem::Initialize(); --> commented out on purpose

	// Test the mem Info structures
	Mem::Info mem_Info;

	// get info
	Mem::Code memResult;
	memResult = Mem::GetInfo(mem_Info);

	CHECK(memResult == Mem::Code::ERROR_Mem_Not_Initialized);

#endif
}TEST_END



// ---  End of File ---------------
