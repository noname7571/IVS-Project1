//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Matej Tomko <xtomko06@stud.fit.vutbr.cz>
// $Date:       $2021-01-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Matej Tomko
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

class TestMatrix : public::testing::Test {
    protected:
        Matrix m{};
        Matrix m1x2{1, 2};
        Matrix m2x1{2, 1};
        Matrix m2x2{2, 2};
        Matrix m1x3{1, 3};
        Matrix m3x1{3, 1};
        Matrix m2x3{2, 3};
        Matrix m3x2{3, 2};
        Matrix m3x3{3, 3};
        Matrix m4x4{4, 4};

        std::vector< double > vector1 = {1};
        std::vector< double > vector2 = {1, 2};
        std::vector< double > vector3 = {1, 2, 3};
        std::vector< double > vector4 = {1, 2, 3, 4};
};

TEST_F(TestMatrix, Matrix1x1) {
    Matrix();
}

TEST_F(TestMatrix, MatrixConstructor) {
    EXPECT_ANY_THROW(Matrix(0, 1));
    EXPECT_ANY_THROW(Matrix(1, 0));

    EXPECT_NO_THROW(Matrix(1, 1));
}

TEST_F(TestMatrix, MatrixSetRC) {
    EXPECT_FALSE(m.set(0, 1, 5));
    EXPECT_FALSE(m.set(1, 0, 5));
    EXPECT_FALSE(m3x2.set(2, 4, 5));

    EXPECT_TRUE(m2x2.set(0, 0, 5));
    EXPECT_TRUE(m2x3.set(1, 2, 5));
}

TEST_F(TestMatrix, MatrixSetValues) {
    std::vector<std::vector< double > > values1 = {{1, 2}, {3, 4}};
    std::vector<std::vector< double > > values2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    EXPECT_FALSE(m.set(values1));
    EXPECT_FALSE(m3x1.set(values2));
    EXPECT_FALSE(m3x3.set(values1));

    EXPECT_TRUE(m2x2.set(values1));
    EXPECT_TRUE(m3x3.set(values2));
}

TEST_F(TestMatrix, MatrixGet) {
    EXPECT_ANY_THROW(m.get(1, 1));
    EXPECT_ANY_THROW(m4x4.get(0, 4));
    EXPECT_ANY_THROW(m3x3.get(3, 1));

    EXPECT_NO_THROW(m2x2.get(1, 1));
    EXPECT_NO_THROW(m3x2.get(2, 1));
}

TEST_F(TestMatrix, MatrixEquals) {
    
}

/*** Konec souboru white_box_tests.cpp ***/
