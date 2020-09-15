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

TEST(fpoint_test, construction)
{
  fpoint value(123, 567);
  EXPECT_EQ(value, fpoint(123, 567));
  EXPECT_EQ(value.x(), 123);
  EXPECT_EQ(value.y(), 567);
}

TEST(fpoint_test, construction2)
{
  fpoint value;
  EXPECT_EQ(value, fpoint(0, 0));
  EXPECT_EQ(value.x(), 0);
  EXPECT_EQ(value.y(), 0);
}

TEST(fpoint_test, conversion)
{
  EXPECT_EQ(fpoint(ipoint(123, 567)), fpoint(123, 567));
}

TEST(fpoint_test, equality)
{
  EXPECT_TRUE(fpoint(1, 2) == fpoint(1, 2));
  EXPECT_FALSE(fpoint(1, 2) == fpoint(2, 1));
  EXPECT_TRUE(fpoint(1, 2) != fpoint(2, 1));
  EXPECT_FALSE(fpoint(1, 2) != fpoint(1, 2));
}

TEST(fpoint_test, distance)
{
  EXPECT_FLOAT_EQ(distance(fpoint(0, 0), fpoint(10, 0)), 10.0f);
  EXPECT_FLOAT_EQ(distance(fpoint(10, 10), fpoint(20, 20)), 14.142135623730951f);
}

TEST(fpoint_test, transpose)
{
  EXPECT_EQ(transpose(fpoint(4, 3)), fpoint(3, 4));
  EXPECT_EQ(transpose(fpoint(123, 456)), fpoint(456, 123));
}

/* EOF */
