//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "_UnitTestConfiguration.h"

TEST(CompilerVersion_Check, TestConfig::ALL)
{
	// dummy test 
	char  winSDK_ver[13]; 
	sprintf_s(winSDK_ver, 13, "%s", WINDOWS_TARGET_PLATFORM); 
	CHECK(strcmp(winSDK_ver, TEST_WINSDK_VER) >= 0);

} TEST_END

// --- End of File ---
