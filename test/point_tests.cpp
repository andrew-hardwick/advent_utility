#include "utility/point.h"
#include <gtest/gtest.h>

namespace point = advent::utility::point;

TEST(Constructor, nominal) {
  // ARRANGE / ACT
  point::Point zero{0, 0};
  point::Point q1{1, 1};
  point::Point q2{-2, 3};
  point::Point q3{-5, -8};
  point::Point q4{13, -21};

  // ASSERT
  EXPECT_EQ(0, zero.x);
  EXPECT_EQ(0, zero.y);

  EXPECT_EQ(1, q1.x);
  EXPECT_EQ(1, q1.y);

  EXPECT_EQ(-2, q2.x);
  EXPECT_EQ(3, q2.y);

  EXPECT_EQ(-5, q3.x);
  EXPECT_EQ(-8, q3.y);

  EXPECT_EQ(13, q4.x);
  EXPECT_EQ(-21, q4.y);
}

TEST(From, nominal) {
  // ARRANGE / ACT
  auto zero = point::from("0,0");
  auto q1 = point::from("1, 1");
  auto q2 = point::from("-2, 3");
  auto q3 = point::from("-5, -8");
  auto q4 = point::from("13, -21");

  // ASSERT
  EXPECT_EQ(0, zero.x);
  EXPECT_EQ(0, zero.y);

  EXPECT_EQ(1, q1.x);
  EXPECT_EQ(1, q1.y);

  EXPECT_EQ(-2, q2.x);
  EXPECT_EQ(3, q2.y);

  EXPECT_EQ(-5, q3.x);
  EXPECT_EQ(-8, q3.y);

  EXPECT_EQ(13, q4.x);
  EXPECT_EQ(-21, q4.y);
}

TEST(rotateRight, nominal) {
  // ARRANGE
  auto zero = point::from("0,0");
  auto q1 = point::from("1, 1");
  auto q2 = point::from("-2, 3");
  auto q3 = point::from("-5, -8");
  auto q4 = point::from("13, -21");

  // ACT
  zero = point::rotateRight(zero);
  q1 = point::rotateRight(q1);
  q2 = point::rotateRight(q2);
  q3 = point::rotateRight(q3);
  q4 = point::rotateRight(q4);

  // ASSERT
  EXPECT_EQ(0, zero.x);
  EXPECT_EQ(0, zero.y);

  EXPECT_EQ(-1, q1.x);
  EXPECT_EQ(1, q1.y);

  EXPECT_EQ(-3, q2.x);
  EXPECT_EQ(-2, q2.y);

  EXPECT_EQ(8, q3.x);
  EXPECT_EQ(-5, q3.y);

  EXPECT_EQ(21, q4.x);
  EXPECT_EQ(13, q4.y);
}

TEST(Operator, equals) {
  // ARRANGE
  auto p1 = point::from("1, 2");
  auto p2 = point::from("1, 2");

  auto p3 = point::from("-3, -4");
  auto p4 = point::from("-3, -4");

  // ACT and ASSERT
  EXPECT_TRUE(p1 == p2);
  EXPECT_TRUE(p3 == p4);
  EXPECT_FALSE(p1 == p3);
  EXPECT_FALSE(p4 == p2);
}

TEST(Operator, notequals) {

  // ARRANGE
  auto p1 = point::from("1, 2");
  auto p2 = point::from("1, 2");

  auto p3 = point::from("-3, -4");
  auto p4 = point::from("-3, -4");

  // ACT and ASSERT
  EXPECT_TRUE(p1 != p3);
  EXPECT_TRUE(p4 != p2);
  EXPECT_FALSE(p1 != p2);
  EXPECT_FALSE(p3 != p4);
}

TEST(Operator, lessthan) {
  // operator< is lexicographical
  // ARRANGE
  auto p1 = point::from("1, 2");
  auto p2 = point::from("2, 1");

  auto p3 = point::from("-3, -4");
  auto p4 = point::from("-4, -3");

  auto p5 = point::from("1, 1");
  auto p6 = point::from("1, 3");

  auto p7 = point::from("-3, -5");
  auto p8 = point::from("-3, -3");

  // ACT and ASSERT
  EXPECT_TRUE(p1 < p2);
  EXPECT_FALSE(p2 < p1);

  EXPECT_TRUE(p4 < p3);
  EXPECT_FALSE(p3 < p4);

  EXPECT_FALSE(p1 < p5);
  EXPECT_TRUE(p1 < p6);

  EXPECT_FALSE(p3 < p7);
  EXPECT_TRUE(p3 < p8);
}

TEST(operator, addition) {
  // ARRANGE
  auto p1 = point::from("1, 2");
  auto p2 = point::from("2, 1");

  auto p3 = point::from("-3, -4");
  auto p4 = point::from("-4, -3");

  auto p5 = point::from("1, 1");
  auto p6 = point::from("1, 3");

  auto p7 = point::from("-3, -5");
  auto p8 = point::from("-3, -3");

  // ACT
  auto r1 = p1 + p3;
  auto r2 = p2 + p4;
  auto r3 = p1 + p5;
  auto r4 = p1 + p6;
  auto r5 = p3 + p7;
  auto r6 = p3 + p8;

  EXPECT_EQ(-2, r1.x);
  EXPECT_EQ(-2, r1.y);

  EXPECT_EQ(-2, r2.x);
  EXPECT_EQ(-2, r2.y);

  EXPECT_EQ(2, r3.x);
  EXPECT_EQ(3, r3.y);

  EXPECT_EQ(2, r4.x);
  EXPECT_EQ(5, r4.y);

  EXPECT_EQ(-6, r5.x);
  EXPECT_EQ(-9, r5.y);

  EXPECT_EQ(-6, r6.x);
  EXPECT_EQ(-7, r6.y);
}

TEST(operator, accumulation) {
  // ARRANGE
  auto p1 = point::from("1, 2");
  auto p2 = point::from("2, 1");

  auto p3 = point::from("-3, -4");
  auto p4 = point::from("-4, -3");

  auto p5 = point::from("1, 1");
  auto p6 = point::from("1, 3");

  auto p7 = point::from("-3, -5");
  auto p8 = point::from("-3, -3");

  auto r1 = p1;
  auto r2 = p2;
  auto r3 = p1;
  auto r4 = p1;
  auto r5 = p3;
  auto r6 = p3;

  // ACT
  r1 += p3;
  r2 += p4;
  r3 += p5;
  r4 += p6;
  r5 += p7;
  r6 += p8;

  EXPECT_EQ(-2, r1.x);
  EXPECT_EQ(-2, r1.y);

  EXPECT_EQ(-2, r2.x);
  EXPECT_EQ(-2, r2.y);

  EXPECT_EQ(2, r3.x);
  EXPECT_EQ(3, r3.y);

  EXPECT_EQ(2, r4.x);
  EXPECT_EQ(5, r4.y);

  EXPECT_EQ(-6, r5.x);
  EXPECT_EQ(-9, r5.y);

  EXPECT_EQ(-6, r6.x);
  EXPECT_EQ(-7, r6.y);
}

TEST(operator, scalarMultiplication) {
  // ARRANGE
  auto p1 = point::from("1, 2");
  auto p2 = point::from("2, 1");

  auto p3 = point::from("-3, -4");
  auto p4 = point::from("-4, -3");

  int m1 = 0;
  int m2 = 1;
  int m3 = -2;
  int m4 = 3;

  // ACT
  auto r1 = p1 * m1;
  auto r2 = p2 * m2;
  auto r3 = p3 * m3;
  auto r4 = p4 * m4;

  // ASSERT
  EXPECT_EQ(0, r1.x);
  EXPECT_EQ(0, r1.y);

  EXPECT_EQ(2, r2.x);
  EXPECT_EQ(1, r2.y);

  EXPECT_EQ(6, r3.x);
  EXPECT_EQ(8, r3.y);

  EXPECT_EQ(-12, r4.x);
  EXPECT_EQ(-9, r4.y);
}
