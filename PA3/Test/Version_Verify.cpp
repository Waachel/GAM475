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

TEST(Version_verify, TestConfig::VERSION_CHECK)
{
#if Version_verify	

	CHECK(Mem::MAJOR_VERSION == 6);
	CHECK(Mem::MINOR_VERSION == 0);

#endif
} TEST_END

// ---  End of File ---------------
