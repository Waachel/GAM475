//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"

#include "PCSNode.h"
using namespace Azul;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

TEST(Version_Check, TestConfig::ALL)
{
#if Version_Check

	CHECK(PCSNode::MAJOR_VERSION == 4);
	CHECK(PCSNode::MINOR_VERSION == 0);

#endif
} TEST_END

// ---  End of File ---
