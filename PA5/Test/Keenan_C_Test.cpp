//----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "_UnitTestConfiguration.h"

#include "PCSTree.h"
#include "PCSNode.h"
#include "PCSTreeForwardIterator.h"
#include "PCSTreeReverseIterator.h"

using namespace Azul;

//---------------------------------------------------------------------------
// Modifying any Unit Test to alter the outcome results 
//       is also an Academic Integrity Violation       
//---------------------------------------------------------------------------
// Stubbed out
TEST(Keenan_C_Enable, TestConfig::ALL)
{
#if Keenan_C_Enable
    PCSTree::Info info;
    PCSTree tree;
    PCSNode* root;

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


    tree.Remove(&nodeC);
    tree.Remove(&nodeB);
    tree.Remove(&nodeA);

    PCSTreeForwardIterator pForIterCount(tree.GetRoot());
    //int count = 0;


    for (pForIterCount.First(); !pForIterCount.IsDone(); pForIterCount.Next())
    {
        pForIterCount.Current()->PrintNode();

    }

#endif
} TEST_END


// --- End of File ---
