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

#include <geomcpp/isize.hpp>

using namespace geomcpp;

TEST(isize_test, construction)
{
  isize value(123, 567);
  EXPECT_EQ(value, isize(123, 567));
  EXPECT_EQ(value.width(), 123);
  EXPECT_EQ(value.height(), 567);
}

TEST(isize_test, equality)
{
  EXPECT_TRUE(isize(1, 2) == isize(1, 2));
  EXPECT_FALSE(isize(1, 2) == isize(2, 1));
  EXPECT_TRUE(isize(1, 2) != isize(2, 1));
  EXPECT_FALSE(isize(1, 2) != isize(1, 2));
}

TEST(isize_test, area)
{
  EXPECT_EQ(area(isize(123, 567)), 69741);
}

TEST(isize_test, multiplication)
{
  EXPECT_EQ(isize(123, 567) * 3, isize(123*3, 567*3));
  EXPECT_EQ(3 * isize(123, 567), isize(123*3, 567*3));
}

/* EOF */
