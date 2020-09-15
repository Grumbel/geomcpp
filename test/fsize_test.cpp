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

TEST(fsize_test, construction)
{
  fsize value(123, 567);
  EXPECT_EQ(value, fsize(123, 567));
  EXPECT_EQ(value.width(), 123);
  EXPECT_EQ(value.height(), 567);
}

TEST(fsize_test, construction2)
{
  fsize value;
  EXPECT_EQ(value, fsize(0, 0));
  EXPECT_EQ(value.width(), 0);
  EXPECT_EQ(value.height(), 0);
}

TEST(fsize_test, conversion)
{
  EXPECT_EQ(fsize(isize(123, 567)), fsize(123, 567));
}

TEST(fsize_test, equality)
{
  EXPECT_TRUE(fsize(1, 2) == fsize(1, 2));
  EXPECT_FALSE(fsize(1, 2) == fsize(2, 1));
  EXPECT_TRUE(fsize(1, 2) != fsize(2, 1));
  EXPECT_FALSE(fsize(1, 2) != fsize(1, 2));
}

TEST(fsize_test, area)
{
  EXPECT_EQ(area(fsize(123, 567)), 69741);
}

TEST(fsize_test, multiplication)
{
  EXPECT_EQ(fsize(123, 567) * 3.0f, fsize(123*3, 567 * 3.0f));
  EXPECT_EQ(3.0f * fsize(123, 567), fsize(123*3, 567 * 3.0f));
}

TEST(fsize_test, transpose)
{
  EXPECT_EQ(transpose(fsize(123, 567)), fsize(567, 123));
}

TEST(fsize_test, aspect_ratio)
{
  EXPECT_FLOAT_EQ(aspect_ratio(fsize(400, 300)), 4.0f / 3.0f);
}

/* EOF */
