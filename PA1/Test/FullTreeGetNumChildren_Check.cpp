//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "PCSTree.h"
#include "PCSNode.h"

using namespace Azul;

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------


TEST(FullTreeGetNumChildren_Check, TestConfig::ALL)
{
#if FullTreeGetNumChildren_Check

	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");
	PCSNode nodeD("Node_D");
	PCSNode nodeE("Node_E");
	PCSNode nodeI("Node_I");
	PCSNode nodeK("Node_K");
	PCSNode nodeL("Node_L");
	PCSNode nodeR("Node_R");
	PCSNode nodeF("Node_F");
	PCSNode nodeG("Node_G");
	PCSNode nodeJ("Node_J");
	PCSNode nodeM("Node_M");
	PCSNode nodeN("Node_N");
	PCSNode nodeO("Node_O");
	PCSNode nodeP("Node_P");
	PCSNode nodeQ("Node_Q");
	PCSNode nodeH("Node_H");
	PCSNode nodeS("Node_S");
	PCSNode nodeT("Node_T");
	PCSNode nodeU("Node_U");
	PCSNode nodeV("Node_V");
	PCSNode nodeW("Node_W");

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);

	tree.Insert(&nodeC, &nodeRoot);
	tree.Insert(&nodeB, &nodeRoot);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeI, &nodeA);
	tree.Insert(&nodeE, &nodeA);
	tree.Insert(&nodeD, &nodeA);
	tree.Insert(&nodeL, &nodeB);
	tree.Insert(&nodeK, &nodeB);
	tree.Insert(&nodeR, &nodeC);
	tree.Insert(&nodeF, &nodeD);
	tree.Insert(&nodeJ, &nodeI);
	tree.Insert(&nodeG, &nodeI);
	tree.Insert(&nodeN, &nodeL);
	tree.Insert(&nodeM, &nodeL);
	tree.Insert(&nodeQ, &nodeR);
	tree.Insert(&nodeP, &nodeR);
	tree.Insert(&nodeO, &nodeR);
	tree.Insert(&nodeH, &nodeF);
	tree.Insert(&nodeS, &nodeP);
	tree.Insert(&nodeW, &nodeS);
	tree.Insert(&nodeV, &nodeS);
	tree.Insert(&nodeU, &nodeS);
	tree.Insert(&nodeT, &nodeS);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 24);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == &nodeK);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == &nodeF);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == &nodeG);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == &nodeM);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == &nodeH);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == &nodeI);
	CHECK(nodeG.GetNextSibling() == &nodeJ);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == &nodeI);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == &nodeG);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == &nodeL);
	CHECK(nodeM.GetNextSibling() == &nodeN);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == &nodeL);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == &nodeM);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == &nodeR);
	CHECK(nodeO.GetNextSibling() == &nodeP);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == &nodeS);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeP);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == &nodeT);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == &nodeS);
	CHECK(nodeT.GetNextSibling() == &nodeU);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == &nodeS);
	CHECK(nodeU.GetNextSibling() == &nodeV);
	CHECK(nodeU.GetPrevSibling() == &nodeT);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == &nodeS);
	CHECK(nodeV.GetNextSibling() == &nodeW);
	CHECK(nodeV.GetPrevSibling() == &nodeU);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeV);

	CHECK(nodeH.GetNumChildren() == 0);
	CHECK(nodeF.GetNumChildren() == 1);
	CHECK(nodeD.GetNumChildren() == 1);
	CHECK(nodeA.GetNumChildren() == 3);
	CHECK(nodeE.GetNumChildren() == 0);
	CHECK(nodeI.GetNumChildren() == 2);
	CHECK(nodeG.GetNumChildren() == 0);
	CHECK(nodeJ.GetNumChildren() == 0);

	CHECK(nodeB.GetNumChildren() == 2);
	CHECK(nodeK.GetNumChildren() == 0);
	CHECK(nodeL.GetNumChildren() == 2);
	CHECK(nodeM.GetNumChildren() == 0);
	CHECK(nodeN.GetNumChildren() == 0);

	CHECK(nodeC.GetNumChildren() == 1);
	CHECK(nodeR.GetNumChildren() == 3);
	CHECK(nodeO.GetNumChildren() == 0);
	CHECK(nodeP.GetNumChildren() == 1);
	CHECK(nodeQ.GetNumChildren() == 0);
	CHECK(nodeS.GetNumChildren() == 4);
	CHECK(nodeT.GetNumChildren() == 0);
	CHECK(nodeU.GetNumChildren() == 0);
	CHECK(nodeV.GetNumChildren() == 0);
	CHECK(nodeW.GetNumChildren() == 0);

	CHECK(nodeRoot.GetNumChildren() == 3);

#endif
} TEST_END


// ---  End of File ---
