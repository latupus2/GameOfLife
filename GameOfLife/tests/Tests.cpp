#include <gtest/gtest.h>
#include "Universe.h"
#include <vector>

// Тесты для класса Universe
class UniverseTest : public ::testing::Test {
protected:
    Universe* universe;

    void SetUp() override {
        universe = new Universe(5, 5);
        universe->setName("Test Universe");
        universe->setTransitionRule("B3/S23");

        universe->setCell(1, 1, 'O');
        universe->setCell(1, 2, 'O');
        universe->setCell(1, 3, 'O');
    }

    void TearDown() override {
        delete universe;
    }
};


TEST_F(UniverseTest, CountNeighbors) {
    EXPECT_EQ(universe->countNeighbors(1, 1), 1);
    EXPECT_EQ(universe->countNeighbors(1, 2), 2);
    EXPECT_EQ(universe->countNeighbors(1, 3), 1);
    EXPECT_EQ(universe->countNeighbors(2, 2), 3);
}


TEST_F(UniverseTest, ShouldSurvive) {
    EXPECT_TRUE(universe->shouldSurvive(2));
    EXPECT_TRUE(universe->shouldSurvive(3));
    EXPECT_FALSE(universe->shouldSurvive(0));
    EXPECT_FALSE(universe->shouldSurvive(1));
    EXPECT_FALSE(universe->shouldSurvive(4));
}

TEST_F(UniverseTest, ShouldBirth) {
    EXPECT_TRUE(universe->shouldBirth(3));
    EXPECT_FALSE(universe->shouldBirth(0));
    EXPECT_FALSE(universe->shouldBirth(1));
    EXPECT_FALSE(universe->shouldBirth(2));
    EXPECT_FALSE(universe->shouldBirth(4));
}


TEST_F(UniverseTest, ApplyRules) {
    universe->applyRules();

    EXPECT_EQ(universe->getCell(1, 2), 'O');
    EXPECT_EQ(universe->getCell(1, 1), '.');
    EXPECT_EQ(universe->getCell(1, 3), '.');
    EXPECT_EQ(universe->getCell(2, 2), 'O');
}
