//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------

#include "_UnitTestConfiguration.h"
#include "MathEngine.h"
#define eq	Util::isEqual 
using namespace Azul;

//---------------------------------------------------------------------------
// TESTS:
//---------------------------------------------------------------------------

TEST(Vec3_Cross, TestConfig::ALL)
{
#if Vec3_Cross

	Vec3 v1(1.0f, 0.0f, 0.0f);
	Vec3 v2(0.0f, 1.0f, 0.0f);
	Vec3 out1;

	out1 = v1.cross(v2);

	CHECK((out1[x] == 0.0f));
	CHECK((out1[y] == 0.0f));
	CHECK((out1[z] == 1.0f));

#endif
} TEST_END

// ---  End of File ---------------
