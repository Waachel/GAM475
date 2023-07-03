//-----------------------------------------------------------------------------
// Copyright 2022, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// --------------------------------
// ---      DO NOT MODIFY       ---
// --------------------------------

#include "_UnitTestConfiguration.h"
#include "PCSTree.h"
#include "PCSNode.h"

//---------------------------------------------------------------------------
// Test Files:
// Single step through, set break points, but do not modify it
//---------------------------------------------------------------------------

using namespace Azul;

#if constructor_Enable
TEST(constructor, PCSTree_group, constructor_Enable)
{
	// ------------------------------------------------
	// Check the compiler, tools, sdk
	// ------------------------------------------------
	#include "EnvirnomentCheck.h"

	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;

	tree.GetInfo(info);
	root = tree.GetRoot();

	CHECK(root == nullptr);
	CHECK(info.maxNumNodes == 0);
	CHECK(info.currNumLevels == 0);
	CHECK(info.currNumNodes == 0);

} TEST_END
#endif

#if addNodeRoot_Enable
TEST(addNodeRoot, PCSTree_group, addNodeRoot_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;
	PCSNode nodeRoot("Root");

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	tree.Insert(&nodeRoot, root);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	CHECK(root == &nodeRoot);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);
}TEST_END
#endif

#if addNodeRootA_Enable
TEST(addNodeRootA, PCSTree_group, addNodeRootA_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	tree.Insert(&nodeRoot, root);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	CHECK(root == &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	tree.Insert(&nodeA, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootAD_Enable
TEST(addNodeRootAD, PCSTree_group, addNodeRootAD_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeD("Node_D");

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	tree.Insert(&nodeRoot, root);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	CHECK(root == &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	tree.Insert(&nodeA, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	tree.Insert(&nodeD, &nodeA);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootADF_Enable
TEST(addNodeRootADF, PCSTree_group, addNodeRootADF_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeD("Node_D");
	PCSNode nodeF("Node_F");

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	tree.Insert(&nodeRoot, root);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	root = tree.GetRoot();
	CHECK(root == &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 1);
	CHECK(info.maxNumLevels == 1);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	tree.Insert(&nodeA, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	tree.Insert(&nodeD, &nodeA);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	tree.Insert(&nodeF, &nodeD);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 4);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 4);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == &nodeF);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootADFH_Enable
TEST(addNodeRootADFH, PCSTree_group, addNodeRootADFH_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeD("Node_D");
	PCSNode nodeF("Node_F");
	PCSNode nodeH("Node_H");

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeD, &nodeA);
	tree.Insert(&nodeF, &nodeD);
	tree.Insert(&nodeH, &nodeF);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 5);
	CHECK(info.maxNumLevels == 5);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 5);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == &nodeF);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == &nodeH);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootAB_Enable
TEST(addNodeRootAB, PCSTree_group, addNodeRootAB_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;
	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");

	root = tree.GetRoot();
	tree.Insert(&nodeRoot, root);
	tree.Insert(&nodeB, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.GetChild() == &nodeB);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	tree.Insert(&nodeA, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootABC_Enable
TEST(addNodeRootABC, PCSTree_group, addNodeRootABC_Enable)
{
	PCSTree::Info info;
	PCSTree tree;
	PCSNode  *root;

	PCSNode nodeRoot("Root");
	PCSNode nodeA("Node_A");
	PCSNode nodeB("Node_B");
	PCSNode nodeC("Node_C");

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);
	tree.Insert(&nodeC, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 2);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.GetChild() == &nodeC);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	tree.Insert(&nodeB, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 3);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.GetChild() == &nodeB);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	tree.Insert(&nodeA, &nodeRoot);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 4);
	CHECK(info.maxNumLevels == 2);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 4);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);
}TEST_END
#endif

#if addNodeRootABCDEI_Enable
TEST(addNodeRootABCDEI, PCSTree_group, addNodeRootABCDEI_Enable)
{
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

	root = tree.GetRoot();

	tree.Insert(&nodeRoot, root);
	tree.Insert(&nodeC, &nodeRoot);
	tree.Insert(&nodeB, &nodeRoot);
	tree.Insert(&nodeA, &nodeRoot);
	tree.Insert(&nodeI, &nodeA);
	tree.Insert(&nodeE, &nodeA);
	tree.Insert(&nodeD, &nodeA);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 7);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 7);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr)
		CHECK(nodeI.GetPrevSibling() == &nodeE);
}TEST_END
#endif

#if addNodeRootABCDEIKL_Enable
TEST(addNodeRootABCDEIKL, PCSTree_group, addNodeRootABCDEIKL_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 9);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 9);

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

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);
}TEST_END
#endif

#if addNodeRootABCDEIKLR_Enable
TEST(addNodeRootABCDEIKLR, PCSTree_group, addNodeRootABCDEIKLR_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 10);
	CHECK(info.maxNumLevels == 3);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 10);

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

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == &nodeA);
	CHECK(nodeD.GetNextSibling() == &nodeE);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootABCDEIKLRF_Enable
TEST(addNodeRootABCDEIKLRF, PCSTree_group, addNodeRootABCDEIKLRF_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 11);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 11);

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

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeE);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == &nodeB);
	CHECK(nodeK.GetNextSibling() == &nodeL);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == &nodeD);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootABCDEIKLRFGJ_Enable
TEST(addNodeRootABCDEIKLRFGJ, PCSTree_group, addNodeRootABCDEIKLRFGJ_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 13);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 13);

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

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == &nodeK);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
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
}TEST_END
#endif

#if addNodeRootABCDEIKLRFGJMN_Enable
TEST(addNodeRootABCDEIKLRFGJMN, PCSTree_group, addNodeRootABCDEIKLRFGJMN_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 15);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 15);

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

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
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
}TEST_END
#endif

#if addNodeRootABCDEIKLRFGJMNOPQ_Enable
TEST(addNodeRootABCDEIKLRFGJMNOPQ, PCSTree_group, addNodeRootABCDEIKLRFGJMNOPQ_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 18);
	CHECK(info.maxNumLevels == 4);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 18);

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

	CHECK(nodeF.GetChild() == nullptr);
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

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeP);
}TEST_END
#endif

#if addNodeRootABCDEIKLRFGJMNOPQH_Enable
TEST(addNodeRootABCDEIKLRFGJMNOPQH, PCSTree_group, addNodeRootABCDEIKLRFGJMNOPQH_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 19);
	CHECK(info.maxNumLevels == 5);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 19);

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

	CHECK(nodeP.GetChild() == nullptr);
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
}TEST_END
#endif

#if addNodeRootABCDEIKLRFGJMNOPQHS_Enable
TEST(addNodeRootABCDEIKLRFGJMNOPQHS, PCSTree_group, addNodeRootABCDEIKLRFGJMNOPQHS_Enable)
{
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

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 20);
	CHECK(info.maxNumLevels == 5);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 20);

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

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if addNodeRootABCDEIKLRFGJMNOPQHSTUVW_Enable
TEST(addNodeRootABCDEIKLRFGJMNOPQHSTUVW, PCSTree_group, addNodeRootABCDEIKLRFGJMNOPQHSTUVW_Enable)
{
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
}TEST_END
#endif

#if fullTree_RemoveW_Enable
TEST(fullTree_RemoveW, PCSTree_group, fullTree_RemoveW_Enable)
{
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

	// Remove W
	tree.Remove(&nodeW);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == &nodeU);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if fullTree_RemoveV_Enable
TEST(fullTree_RemoveV, PCSTree_group, fullTree_RemoveV_Enable)
{
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

	// Remove V
	tree.Remove(&nodeV);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeU.GetNextSibling() == &nodeW);
	CHECK(nodeU.GetPrevSibling() == &nodeT);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeU);
}TEST_END
#endif

#if fullTree_RemoveU_Enable
TEST(fullTree_RemoveU, PCSTree_group, fullTree_RemoveU_Enable)
{
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

	// Remove U
	tree.Remove(&nodeU);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeT.GetNextSibling() == &nodeV);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == &nodeS);
	CHECK(nodeV.GetNextSibling() == &nodeW);
	CHECK(nodeV.GetPrevSibling() == &nodeT);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeV);
}TEST_END
#endif

#if fullTree_RemoveT_Enable
TEST(fullTree_RemoveT, PCSTree_group, fullTree_RemoveT_Enable)
{
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

	// Remove T
	tree.Remove(&nodeT);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeS.GetChild() == &nodeU);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == &nodeS);
	CHECK(nodeU.GetNextSibling() == &nodeV);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == &nodeS);
	CHECK(nodeV.GetNextSibling() == &nodeW);
	CHECK(nodeV.GetPrevSibling() == &nodeU);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == &nodeS);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == &nodeV);
}TEST_END
#endif

#if fullTree_RemoveH_Enable
TEST(fullTree_RemoveH, PCSTree_group, fullTree_RemoveH_Enable)
{
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

	// Remove H
	tree.Remove(&nodeH);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeF.GetChild() == nullptr);
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
	CHECK(nodeH.GetParent() == nullptr);
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
}TEST_END
#endif

#if fullTree_RemoveQ_Enable
TEST(fullTree_RemoveQ, PCSTree_group, fullTree_RemoveQ_Enable)
{
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

	// Remove Q
	tree.Remove(&nodeQ);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveO_Enable
TEST(fullTree_RemoveO, PCSTree_group, fullTree_RemoveO_Enable)
{
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

	// Remove O
	tree.Remove(&nodeO);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeR.GetChild() == &nodeP);
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
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == &nodeS);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveK_Enable
TEST(fullTree_RemoveK, PCSTree_group, fullTree_RemoveK_Enable)
{
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

	// Remove K
	tree.Remove(&nodeK);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeB);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == &nodeL);
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
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == &nodeM);
	CHECK(nodeL.GetParent() == &nodeB);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveM_Enable
TEST(fullTree_RemoveM, PCSTree_group, fullTree_RemoveM_Enable)
{
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

	// Remove M
	tree.Remove(&nodeM);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeL.GetChild() == &nodeN);
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
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == &nodeL);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveN_Enable
TEST(fullTree_RemoveN, PCSTree_group, fullTree_RemoveN_Enable)
{
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

	// Remove N
	tree.Remove(&nodeN);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveJ_Enable
TEST(fullTree_RemoveJ, PCSTree_group, fullTree_RemoveJ_Enable)
{
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

	// Remove J
	tree.Remove(&nodeJ);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveG_Enable
TEST(fullTree_RemoveG, PCSTree_group, fullTree_RemoveG_Enable)
{
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

	// Remove G
	tree.Remove(&nodeG);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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

	CHECK(nodeI.GetChild() == &nodeJ);
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
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == &nodeI);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveE_Enable
TEST(fullTree_RemoveE, PCSTree_group, fullTree_RemoveE_Enable)
{
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

	// Remove E
	tree.Remove(&nodeE);

	tree.GetInfo(info);
	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 23);

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
	CHECK(nodeD.GetNextSibling() == &nodeI);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == &nodeG);
	CHECK(nodeI.GetParent() == &nodeA);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == &nodeD);

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
}TEST_END
#endif

#if fullTree_RemoveF_Enable
TEST(fullTree_RemoveF, PCSTree_group, fullTree_RemoveF_Enable)
{
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

	// Remove F
	tree.Remove(&nodeF);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 22);

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

	CHECK(nodeD.GetChild() == nullptr);
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

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
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
	CHECK(nodeH.GetParent() == nullptr);
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
}TEST_END
#endif

#if fullTree_RemoveD_Enable
TEST(fullTree_RemoveD, PCSTree_group, fullTree_RemoveD_Enable)
{
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

	// Remove D
	tree.Remove(&nodeD);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 21);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeE);
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

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == &nodeA);
	CHECK(nodeE.GetNextSibling() == &nodeI);
	CHECK(nodeE.GetPrevSibling() == nullptr);

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

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
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
	CHECK(nodeH.GetParent() == nullptr);
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
}TEST_END
#endif

#if fullTree_RemoveI_Enable
TEST(fullTree_RemoveI, PCSTree_group, fullTree_RemoveI_Enable)
{
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

	// Remove I
	tree.Remove(&nodeI);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 21);
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
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == &nodeD);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

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
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveL_Enable
TEST(fullTree_RemoveL, PCSTree_group, fullTree_RemoveL_Enable)
{
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

	// Remove L
	tree.Remove(&nodeL);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 21);

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
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

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
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveS_Enable
TEST(fullTree_RemoveS, PCSTree_group, fullTree_RemoveS_Enable)
{
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
	// Remove S
	tree.Remove(&nodeS);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 19);

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

	CHECK(nodeP.GetChild() == nullptr);
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

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if fullTree_RemoveP_Enable
TEST(fullTree_RemoveP, PCSTree_group, fullTree_RemoveP_Enable)
{
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

	// Remove P
	tree.Remove(&nodeP);

	tree.GetInfo(info);

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
	CHECK(nodeO.GetNextSibling() == &nodeQ);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeO);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if fullTree_RemoveR_Enable
TEST(fullTree_RemoveR, PCSTree_group, fullTree_RemoveR_Enable)
{
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

	// Remove R
	tree.Remove(&nodeR);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 15);
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

	CHECK(nodeC.GetChild() == nullptr);
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

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == nullptr);
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
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if fullTree_RemoveC_Enable
TEST(fullTree_RemoveC, PCSTree_group, fullTree_RemoveC_Enable)
{
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

	// Remove C
	tree.Remove(&nodeC);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 14);

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
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == &nodeA);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == nullptr);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

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

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == nullptr);
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
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == &nodeF);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if fullTree_RemoveB_Enable
TEST(fullTree_RemoveB, PCSTree_group, fullTree_RemoveB_Enable)
{
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

	// Remove B
	tree.Remove(&nodeB);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 19);

	CHECK(nodeRoot.GetChild() == &nodeA);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == &nodeD);
	CHECK(nodeA.GetParent() == &nodeRoot);
	CHECK(nodeA.GetNextSibling() == &nodeC);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeA);

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
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

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
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

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
}TEST_END
#endif

#if fullTree_RemoveA_Enable
TEST(fullTree_RemoveA, PCSTree_group, fullTree_RemoveA_Enable)
{
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

	// Remove A
	tree.Remove(&nodeA);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 16);

	CHECK(nodeRoot.GetChild() == &nodeB);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == &nodeK);
	CHECK(nodeB.GetParent() == &nodeRoot);
	CHECK(nodeB.GetNextSibling() == &nodeC);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == &nodeB);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

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

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

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
	CHECK(nodeH.GetParent() == nullptr);
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
}TEST_END
#endif

#if fullTree_RemoveRoot_Enable
TEST(fullTree_RemoveRoot, PCSTree_group, fullTree_RemoveRoot_Enable)
{
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

	// RemoveROOT
	tree.Remove(&nodeRoot);
	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 0);
	CHECK(info.currNumNodes == 0);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == nullptr);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == nullptr);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == nullptr);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
}TEST_END
#endif

#if fullTree_printTree_Enable
TEST(fullTree_printTree, PCSNode_group, fullTree_printTree_Enable)
{
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

	// print the entire tree
	tree.Print();

}TEST_END
#endif

#if fullTree_CheckLevels_C_children_Enable
TEST(fullTree_CheckLevels_C_children, PCSNode_group, fullTree_CheckLevels_C_children_Enable)
{
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

	tree.Remove(&nodeA);
	tree.Remove(&nodeB);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 6);
	CHECK(info.currNumNodes == 11);

	CHECK(nodeRoot.GetChild() == &nodeC);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

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
	CHECK(nodeH.GetParent() == nullptr);
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

}TEST_END
#endif

#if fullTree_CheckLevels_C_children_remove_TUVW_Enable
TEST(fullTree_CheckLevels_C_children_remove_TUVW, PCSNode_group, fullTree_CheckLevels_C_children_remove_TUVW_Enable)
{
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


	tree.Remove(&nodeA);
	tree.Remove(&nodeB);
	tree.Remove(&nodeT);
	tree.Remove(&nodeU);
	tree.Remove(&nodeV);
	tree.Remove(&nodeW);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 5);
	CHECK(info.currNumNodes == 7);

	CHECK(nodeRoot.GetChild() == &nodeC);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

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
	CHECK(nodeH.GetParent() == nullptr);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == &nodeP);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);

}TEST_END
#endif

#if fullTree_CheckLevels_C_children_remove_S_Enable
TEST(fullTree_CheckLevels_C_children_remove_S, PCSNode_group, fullTree_CheckLevels_C_children_remove_S_Enable)
{
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

	tree.Remove(&nodeA);
	tree.Remove(&nodeB);
	tree.Remove(&nodeS);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 4);
	CHECK(info.currNumNodes == 6);

	CHECK(nodeRoot.GetChild() == &nodeC);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == &nodeO);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == &nodeR);
	CHECK(nodeO.GetNextSibling() == &nodeP);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == &nodeR);
	CHECK(nodeP.GetNextSibling() == &nodeQ);
	CHECK(nodeP.GetPrevSibling() == &nodeO);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == &nodeR);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == &nodeP);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == nullptr);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);


}TEST_END
#endif

#if fullTree_CheckLevels_C_children_remove_OPQ_Enable
TEST(fullTree_CheckLevels_C_children_remove_OPQ, PCSNode_group, fullTree_CheckLevels_C_children_remove_OPQ_Enable)
{
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

	tree.Remove(&nodeA);
	tree.Remove(&nodeB);
	tree.Remove(&nodeO);
	tree.Remove(&nodeP);
	tree.Remove(&nodeQ);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 3);
	CHECK(info.currNumNodes == 3);

	CHECK(nodeRoot.GetChild() == &nodeC);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == &nodeR);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == &nodeC);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == nullptr);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);

}TEST_END
#endif

#if fullTree_CheckLevels_C_children_remove_R_Enable
TEST(fullTree_CheckLevels_C_children_remove_R, PCSNode_group, fullTree_CheckLevels_C_children_remove_R_Enable)
{
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

	tree.Remove(&nodeA);
	tree.Remove(&nodeB);
	tree.Remove(&nodeR);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 2);
	CHECK(info.currNumNodes == 2);

	CHECK(nodeRoot.GetChild() == &nodeC);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == &nodeRoot);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == nullptr);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == nullptr);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);

} TEST_END
#endif

#if fullTree_CheckLevels_C_children_remove_C_Enable
TEST(fullTree_CheckLevels_C_children_remove_C, PCSNode_group, fullTree_CheckLevels_C_children_remove_C_Enable)
{
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


	tree.Remove(&nodeA);
	tree.Remove(&nodeB);
	tree.Remove(&nodeC);

	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 1);
	CHECK(info.currNumNodes == 1);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == nullptr);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == nullptr);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == nullptr);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
} TEST_END
#endif

#if fullTree_CheckLevels_C_children_remove_root_Enable
TEST(fullTree_CheckLevels_C_children_remove_root, PCSNode_group, fullTree_CheckLevels_C_children_remove_root_Enable)
{
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

	tree.Remove(&nodeRoot);
	tree.GetInfo(info);

	CHECK(info.maxNumNodes == 24);
	CHECK(info.maxNumLevels == 6);
	CHECK(info.currNumLevels == 0);
	CHECK(info.currNumNodes == 0);

	CHECK(nodeRoot.GetChild() == nullptr);
	CHECK(nodeRoot.GetParent() == nullptr);
	CHECK(nodeRoot.GetNextSibling() == nullptr);
	CHECK(nodeRoot.GetPrevSibling() == nullptr);

	CHECK(nodeA.GetChild() == nullptr);
	CHECK(nodeA.GetParent() == nullptr);
	CHECK(nodeA.GetNextSibling() == nullptr);
	CHECK(nodeA.GetPrevSibling() == nullptr);

	CHECK(nodeB.GetChild() == nullptr);
	CHECK(nodeB.GetParent() == nullptr);
	CHECK(nodeB.GetNextSibling() == nullptr);
	CHECK(nodeB.GetPrevSibling() == nullptr);

	CHECK(nodeC.GetChild() == nullptr);
	CHECK(nodeC.GetParent() == nullptr);
	CHECK(nodeC.GetNextSibling() == nullptr);
	CHECK(nodeC.GetPrevSibling() == nullptr);

	CHECK(nodeD.GetChild() == nullptr);
	CHECK(nodeD.GetParent() == nullptr);
	CHECK(nodeD.GetNextSibling() == nullptr);
	CHECK(nodeD.GetPrevSibling() == nullptr);

	CHECK(nodeE.GetChild() == nullptr);
	CHECK(nodeE.GetParent() == nullptr);
	CHECK(nodeE.GetNextSibling() == nullptr);
	CHECK(nodeE.GetPrevSibling() == nullptr);

	CHECK(nodeI.GetChild() == nullptr);
	CHECK(nodeI.GetParent() == nullptr);
	CHECK(nodeI.GetNextSibling() == nullptr);
	CHECK(nodeI.GetPrevSibling() == nullptr);

	CHECK(nodeK.GetChild() == nullptr);
	CHECK(nodeK.GetParent() == nullptr);
	CHECK(nodeK.GetNextSibling() == nullptr);
	CHECK(nodeK.GetPrevSibling() == nullptr);

	CHECK(nodeL.GetChild() == nullptr);
	CHECK(nodeL.GetParent() == nullptr);
	CHECK(nodeL.GetNextSibling() == nullptr);
	CHECK(nodeL.GetPrevSibling() == nullptr);

	CHECK(nodeR.GetChild() == nullptr);
	CHECK(nodeR.GetParent() == nullptr);
	CHECK(nodeR.GetNextSibling() == nullptr);
	CHECK(nodeR.GetPrevSibling() == nullptr);

	CHECK(nodeF.GetChild() == nullptr);
	CHECK(nodeF.GetParent() == nullptr);
	CHECK(nodeF.GetNextSibling() == nullptr);
	CHECK(nodeF.GetPrevSibling() == nullptr);

	CHECK(nodeG.GetChild() == nullptr);
	CHECK(nodeG.GetParent() == nullptr);
	CHECK(nodeG.GetNextSibling() == nullptr);
	CHECK(nodeG.GetPrevSibling() == nullptr);

	CHECK(nodeJ.GetChild() == nullptr);
	CHECK(nodeJ.GetParent() == nullptr);
	CHECK(nodeJ.GetNextSibling() == nullptr);
	CHECK(nodeJ.GetPrevSibling() == nullptr);

	CHECK(nodeM.GetChild() == nullptr);
	CHECK(nodeM.GetParent() == nullptr);
	CHECK(nodeM.GetNextSibling() == nullptr);
	CHECK(nodeM.GetPrevSibling() == nullptr);

	CHECK(nodeN.GetChild() == nullptr);
	CHECK(nodeN.GetParent() == nullptr);
	CHECK(nodeN.GetNextSibling() == nullptr);
	CHECK(nodeN.GetPrevSibling() == nullptr);

	CHECK(nodeO.GetChild() == nullptr);
	CHECK(nodeO.GetParent() == nullptr);
	CHECK(nodeO.GetNextSibling() == nullptr);
	CHECK(nodeO.GetPrevSibling() == nullptr);

	CHECK(nodeP.GetChild() == nullptr);
	CHECK(nodeP.GetParent() == nullptr);
	CHECK(nodeP.GetNextSibling() == nullptr);
	CHECK(nodeP.GetPrevSibling() == nullptr);

	CHECK(nodeQ.GetChild() == nullptr);
	CHECK(nodeQ.GetParent() == nullptr);
	CHECK(nodeQ.GetNextSibling() == nullptr);
	CHECK(nodeQ.GetPrevSibling() == nullptr);

	CHECK(nodeH.GetChild() == nullptr);
	CHECK(nodeH.GetParent() == nullptr);
	CHECK(nodeH.GetNextSibling() == nullptr);
	CHECK(nodeH.GetPrevSibling() == nullptr);

	CHECK(nodeS.GetChild() == nullptr);
	CHECK(nodeS.GetParent() == nullptr);
	CHECK(nodeS.GetNextSibling() == nullptr);
	CHECK(nodeS.GetPrevSibling() == nullptr);

	CHECK(nodeT.GetChild() == nullptr);
	CHECK(nodeT.GetParent() == nullptr);
	CHECK(nodeT.GetNextSibling() == nullptr);
	CHECK(nodeT.GetPrevSibling() == nullptr);

	CHECK(nodeU.GetChild() == nullptr);
	CHECK(nodeU.GetParent() == nullptr);
	CHECK(nodeU.GetNextSibling() == nullptr);
	CHECK(nodeU.GetPrevSibling() == nullptr);

	CHECK(nodeV.GetChild() == nullptr);
	CHECK(nodeV.GetParent() == nullptr);
	CHECK(nodeV.GetNextSibling() == nullptr);
	CHECK(nodeV.GetPrevSibling() == nullptr);

	CHECK(nodeW.GetChild() == nullptr);
	CHECK(nodeW.GetParent() == nullptr);
	CHECK(nodeW.GetNextSibling() == nullptr);
	CHECK(nodeW.GetPrevSibling() == nullptr);
} TEST_END
#endif

// ---  End of File ---
