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

#ifndef __clang__
#  pragma GCC diagnostic ignored "-Wsuggest-override"
#else
#  pragma GCC diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#endif

template<typename T>
class tsize_test : public ::testing::Test {};

using MyTypes = ::testing::Types<int, long, float, double>;
TYPED_TEST_SUITE(tsize_test, MyTypes);

TYPED_TEST(tsize_test, construction)
{
  using size = tsize<TypeParam>;

  size value(123, 567);
  EXPECT_EQ(value, size(123, 567));
  EXPECT_EQ(value.width(), 123);
  EXPECT_EQ(value.height(), 567);
}

TYPED_TEST(tsize_test, construction2)
{
  using size = tsize<TypeParam>;

  size value;
  EXPECT_EQ(value, size(0, 0));
  EXPECT_EQ(value.width(), 0);
  EXPECT_EQ(value.height(), 0);
}

TYPED_TEST(tsize_test, conversion)
{
  using size = tsize<TypeParam>;

  EXPECT_EQ(size(isize(123, 567)), size(123, 567));
  EXPECT_EQ(size(fsize(123, 567)), size(123, 567));
}

TYPED_TEST(tsize_test, equality)
{
  using size = tsize<TypeParam>;

  EXPECT_TRUE(size(1, 2) == size(1, 2));
  EXPECT_FALSE(size(1, 2) == size(2, 1));
  EXPECT_TRUE(size(1, 2) != size(2, 1));
  EXPECT_FALSE(size(1, 2) != size(1, 2));
}

TYPED_TEST(tsize_test, area)
{
  using size = tsize<TypeParam>;

  EXPECT_EQ(area(size(123, 567)), 69741);
}

TYPED_TEST(tsize_test, multiplication)
{
  using size = tsize<TypeParam>;

  EXPECT_EQ(size(123, 567) * TypeParam(3), size(123*3, 567 * TypeParam(3)));
  EXPECT_EQ(TypeParam(3) * size(123, 567), size(123*3, 567 * TypeParam(3)));
}

TYPED_TEST(tsize_test, transpose)
{
  using size = tsize<TypeParam>;

  EXPECT_EQ(transpose(size(123, 567)), size(567, 123));
}

TYPED_TEST(tsize_test, aspect_ratio)
{
  using size = tsize<TypeParam>;

  EXPECT_FLOAT_EQ(aspect_ratio(size(400, 300)), 4.0f / 3.0f);
}

/* EOF */
