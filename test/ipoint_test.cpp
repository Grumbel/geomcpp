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

#include <geom/geom.hpp>

using namespace geom;

TEST(ipoint_test, construction)
{
  ipoint value(123, 567);
  EXPECT_EQ(value, ipoint(123, 567));
  EXPECT_EQ(value.x(), 123);
  EXPECT_EQ(value.y(), 567);
}

TEST(ipoint_test, construction2)
{
  ipoint value;
  EXPECT_EQ(value, ipoint(0, 0));
  EXPECT_EQ(value.x(), 0);
  EXPECT_EQ(value.y(), 0);
}

TEST(ipoint_test, conversion)
{
  EXPECT_EQ(ipoint(fpoint(123, 567)), ipoint(123, 567));
}

TEST(ipoint_test, equality)
{
  EXPECT_TRUE(ipoint(1, 2) == ipoint(1, 2));
  EXPECT_FALSE(ipoint(1, 2) == ipoint(2, 1));
  EXPECT_TRUE(ipoint(1, 2) != ipoint(2, 1));
  EXPECT_FALSE(ipoint(1, 2) != ipoint(1, 2));
}

TEST(ipoint_test, distance)
{
  EXPECT_FLOAT_EQ(distance(ipoint(0, 0), ipoint(10, 0)), 10.0f);
  EXPECT_FLOAT_EQ(distance(ipoint(10, 10), ipoint(20, 20)), 14.142135623730951f);
}

TEST(ipoint_test, transpose)
{
  EXPECT_EQ(transpose(ipoint(4, 3)), ipoint(3, 4));
  EXPECT_EQ(transpose(ipoint(123, 456)), ipoint(456, 123));
}

TEST(ipoint_test, addition)
{
  EXPECT_EQ(ipoint(1, 2) + isize(5, 6), ipoint(6, 8));
}

/* EOF */
