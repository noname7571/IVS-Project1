//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Matej Tomko <xtomko06@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Matej Tomko
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

class EmptyTree : public ::testing::Test {
    protected:
        BinaryTree tree;
};

class NonEmptyTree : public ::testing::Test {
    protected:
        virtual void SetUp() {
            int values[] = {10, 85, 15, 70, 20, 60, 30, 50, 65, 80, 90, 40, 5, 55};

            for(int i = 0; i < 14; ++i) {
                tree.InsertNode(values[i]);
            }
        }

        BinaryTree tree;
};

class TreeAxioms : public ::testing::Test {
    protected:
        virtual void SetUp() {
            int values[] = {10, 85, 15, 70, 20, 60, 30, 50, 65, 80, 90, 40, 5, 55};

            for(int i = 0; i < 14; ++i) {
                tree.InsertNode(values[i]);
            }
        }

        BinaryTree tree;
};

TEST_F(EmptyTree, InsertNode) {
    EXPECT_TRUE(tree.GetRoot() == NULL);

    std::pair<bool, Node_t *> x = tree.InsertNode(0);
    EXPECT_TRUE(x.first);
    EXPECT_EQ(x.second, tree.GetRoot());

    x = tree.InsertNode(0);
    EXPECT_FALSE(x.first);
    EXPECT_EQ(x.second, tree.GetRoot());
}

TEST_F(EmptyTree, DeleteNode) {
    EXPECT_FALSE(tree.DeleteNode(0));
    EXPECT_FALSE(tree.DeleteNode(25));

    std::pair<bool, Node_t *> x = tree.InsertNode(0);
    EXPECT_TRUE(tree.DeleteNode(0));
}

TEST_F(EmptyTree, FindNode) {
    EXPECT_EQ(tree.FindNode(0), nullptr);
    EXPECT_EQ(tree.FindNode(25), nullptr);

    std::pair<bool, Node_t *> x = tree.InsertNode(0);
    EXPECT_EQ(tree.FindNode(0)->key, 0);
}

TEST_F(NonEmptyTree, InsertNode) {
    EXPECT_FALSE(tree.GetRoot() == NULL);

    std::pair<bool, Node_t *> x = tree.InsertNode(0);
    EXPECT_TRUE(x.first);
    EXPECT_EQ(x.second, tree.FindNode(0));

    x = tree.InsertNode(30);
    EXPECT_FALSE(x.first);
    EXPECT_EQ(x.second, tree.FindNode(30));
}

TEST_F(NonEmptyTree, DeleteNode) {
    EXPECT_FALSE(tree.DeleteNode(0));
    EXPECT_FALSE(tree.DeleteNode(25));

    EXPECT_TRUE(tree.DeleteNode(70));
    EXPECT_TRUE(tree.DeleteNode(55));
}

TEST_F(NonEmptyTree, FindNode) {
    EXPECT_EQ(tree.FindNode(0), nullptr);
    EXPECT_EQ(tree.FindNode(25), nullptr);

    EXPECT_EQ(tree.FindNode(10)->key, 10);
    EXPECT_EQ(tree.FindNode(40)->key, 40);
}

TEST_F(TreeAxioms, Axiom1) {
    std::vector<BinaryTree::Node_t*> outLeafNodes;
    tree.GetLeafNodes(outLeafNodes);

    for (BinaryTree::Node_t* x : outLeafNodes) {
        EXPECT_EQ(x->color, BLACK);
    }
}

TEST_F(TreeAxioms, Axiom2) {
    std::vector<BinaryTree::Node_t*> outAllNodes;
    tree.GetAllNodes(outAllNodes);

    for (BinaryTree::Node_t* x : outAllNodes) {
        if (x->color == RED) {
            EXPECT_EQ(x->pLeft->color, BLACK);
            EXPECT_EQ(x->pRight->color, BLACK);
        }
    }
}

TEST_F(TreeAxioms, Axiom3) {
    
}

/*** Konec souboru black_box_tests.cpp ***/
