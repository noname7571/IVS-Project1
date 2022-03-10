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

        std::vector< double > rside1 = {1};
        std::vector< double > rside2 = {2, 4};
        std::vector< double > rside3 = {1, 3, 5};
        std::vector< double > rside4 = {2, 4, 6, 8};
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
    Matrix m1{2, 2};
    m1.set({{1, 2}, {3, 4}});

    EXPECT_ANY_THROW(m.operator==(m2x2));
    EXPECT_ANY_THROW(m3x2.operator==(m2x3));

    EXPECT_FALSE(m2x2.operator==(m1));
    EXPECT_TRUE(m2x2.operator==(m2x2));
    EXPECT_TRUE(m3x1.operator==(m3x1));
}

TEST_F(TestMatrix, MatrixSum) {
    EXPECT_ANY_THROW(m.operator+(m2x2));
    EXPECT_ANY_THROW(m3x2.operator+(m2x3));

    EXPECT_NO_THROW(m2x2.operator+(m2x2));
    EXPECT_NO_THROW(m3x1.operator+(m3x1));
}

TEST_F(TestMatrix, MatrixMultiply) {
    EXPECT_NO_THROW(m1x2.operator*(m2x1));
    EXPECT_NO_THROW(m3x3.operator*(m3x3));

    EXPECT_ANY_THROW(m2x3.operator*(m2x3));
    EXPECT_ANY_THROW(m1x2.operator*(m4x4));

    EXPECT_NO_THROW(m3x3.operator*(5));
    EXPECT_NO_THROW(m3x2.operator*(-12));
}

TEST_F(TestMatrix, MatrixSolveEq) {
    EXPECT_ANY_THROW(m.solveEquation(rside2));
    EXPECT_ANY_THROW(m2x2.solveEquation(rside3));

    m1x2.set({{1, 2}});
    EXPECT_ANY_THROW(m1x2.solveEquation(rside2));

    EXPECT_ANY_THROW(m3x3.solveEquation(rside3));
    EXPECT_ANY_THROW(m4x4.solveEquation(rside4));

    std::vector< double > matrixM;
    m.set({{1}});
    EXPECT_NO_THROW(matrixM = m.solveEquation(rside1));
    EXPECT_EQ(matrixM[0], 1);

    Matrix m1{2, 2};
    m1.set({{1, 2}, {3, 4}});
    EXPECT_NO_THROW(m1.solveEquation(rside2));
}

TEST_F(TestMatrix, MatrixTranspose) {
    EXPECT_NO_THROW(m2x2.transpose());
    EXPECT_NO_THROW(m3x1.transpose());
    EXPECT_NO_THROW(m4x4.transpose());
}

TEST_F(TestMatrix, MatrixInverse) {
    EXPECT_ANY_THROW(m2x3.inverse());

    EXPECT_ANY_THROW(m3x3.inverse());
    
    Matrix m1{2, 2};
    m1.set({{1, 2}, {3, 4}});
    EXPECT_NO_THROW(m1.inverse());

    // TODO: Finish a couple of lines at the end
}

/*** Konec souboru white_box_tests.cpp ***/
