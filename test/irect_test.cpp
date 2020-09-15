// geomcpp - Basic collection of point, size and rect classes
// Copyright (C) 2020 Ingo Ruhnke <grumbel@gmail.com>
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.

#include <gtest/gtest.h>

#include <geomcpp/io.hpp>
#include <geomcpp/point.hpp>
#include <geomcpp/size.hpp>
#include <geomcpp/rect.hpp>

using namespace geomcpp;

TEST(irect_test, construction1)
{
  irect value(ipoint(12, 34), isize(56, 78));
  EXPECT_EQ(value, irect(ipoint(12, 34), isize(56, 78)));
  EXPECT_EQ(value.x(), 12);
  EXPECT_EQ(value.y(), 34);
  EXPECT_EQ(value.width(), 56);
  EXPECT_EQ(value.height(), 78);
}

TEST(irect_test, construction2)
{
  irect value(12, 34, 56, 78);
  EXPECT_EQ(value, irect(ipoint(12, 34), isize(44, 44)));
  EXPECT_EQ(value.x(), 12);
  EXPECT_EQ(value.y(), 34);
  EXPECT_EQ(value.width(), 44);
  EXPECT_EQ(value.height(), 44);
}

TEST(irect_test, equality)
{
  EXPECT_TRUE(irect(1, 2, 3, 4) == irect(1, 2, 3, 4));
  EXPECT_FALSE(irect(1, 2, 3, 4) == irect(4, 3, 2, 1));
  EXPECT_TRUE(irect(1, 2, 3, 4) != irect(4, 3, 2, 1));
  EXPECT_FALSE(irect(1, 2, 3, 4) != irect(1, 2, 3, 4));
}

TEST(irect_test, grow)
{
  EXPECT_EQ(grow(irect(ipoint(0, 0), isize(123, 567)), 10),
            irect(ipoint(-10, -10), isize(143, 587)));
  EXPECT_EQ(grow(irect(ipoint(0, 0), isize(123, 567)), 10, 20),
            irect(ipoint(-10, -20), isize(143, 607)));
}

TEST(irect_test, intersection)
{
  EXPECT_EQ(intersection(irect(ipoint(0, 0), isize(123, 567)),
                         irect(ipoint(10, 20), isize(50, 60))),
            irect(ipoint(10, 20), isize(50, 60)));
}

TEST(irect_test, overlapping)
{
  EXPECT_TRUE(intersects(irect(0, 0, 123, 567),
                         irect(10, 20, 50, 60)));
  EXPECT_TRUE(intersects(irect(0, 0, 123, 567),
                         irect(0, 0, 50, 60)));
  EXPECT_FALSE(intersects(irect(0, 0, 123, 567),
                          irect(-500, -500, -50, -60)));
}

TEST(irect_test, contains)
{
  EXPECT_TRUE(contains(irect(10, 20, 30, 40), ipoint(15, 25)));
  EXPECT_FALSE(contains(irect(10, 20, 30, 40), ipoint(-15, -19)));
}

TEST(irect_test, normalize)
{
  EXPECT_EQ(normalize(irect(10, 20, -30, -40)),
            irect(-30, -40, 10, 20));
  EXPECT_EQ(normalize(irect(10, 20, 30, -40)),
            irect(10, -40, 30, 20));
}

TEST(irect_test, unite)
{
  EXPECT_EQ(unite(irect(0, 0, 10, 20),
                  irect(30, 40, 50, 70)),
            irect(0, 0, 50, 70));
  EXPECT_EQ(unite(irect(30, 40, 50, 70),
                  irect(0, 0, 10, 20)),
            irect(0, 0, 50, 70));
}

TEST(irect_test, transpose)
{
  EXPECT_EQ(transpose(irect(ipoint(0, 0), isize(10, 20))),
            irect(ipoint(0, 0), isize(20, 10)));
  EXPECT_EQ(transpose(irect(ipoint(35, 24), isize(10, 20))),
            irect(ipoint(35, 24), isize(20, 10)));
}

TEST(irect_test, aspect_ratio)
{
  EXPECT_FLOAT_EQ(aspect_ratio(irect(ipoint(0, 0), isize(400, 300))),
                  4.0f / 3.0f);
  EXPECT_FLOAT_EQ(aspect_ratio(irect(ipoint(50, 60), isize(1600, 900))),
                  16.0f / 9.0f);
}

/* EOF */
