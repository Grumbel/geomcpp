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

TEST(frect_test, construction1)
{
  frect value(fpoint(12, 34), fsize(56, 78));
  EXPECT_EQ(value, frect(fpoint(12, 34), fsize(56, 78)));
  EXPECT_EQ(value.x(), 12);
  EXPECT_EQ(value.y(), 34);
  EXPECT_EQ(value.width(), 56);
  EXPECT_EQ(value.height(), 78);
}

TEST(frect_test, construction2)
{
  frect value(12, 34, 56, 78);
  EXPECT_EQ(value, frect(fpoint(12, 34), fsize(44, 44)));
  EXPECT_EQ(value.x(), 12);
  EXPECT_EQ(value.y(), 34);
  EXPECT_EQ(value.width(), 44);
  EXPECT_EQ(value.height(), 44);
}

TEST(frect_test, conversion)
{
  EXPECT_EQ(frect(irect(123, 567, 800, 900)), frect(123, 567, 800, 900));
}

TEST(frect_test, equality)
{
  EXPECT_TRUE(frect(1, 2, 3, 4) == frect(1, 2, 3, 4));
  EXPECT_FALSE(frect(1, 2, 3, 4) == frect(4, 3, 2, 1));
  EXPECT_TRUE(frect(1, 2, 3, 4) != frect(4, 3, 2, 1));
  EXPECT_FALSE(frect(1, 2, 3, 4) != frect(1, 2, 3, 4));
}

TEST(frect_test, grow)
{
  EXPECT_EQ(grow(frect(fpoint(0, 0), fsize(123, 567)), 10.0f),
            frect(fpoint(-10, -10), fsize(143, 587)));
  EXPECT_EQ(grow(frect(fpoint(0, 0), fsize(123, 567)), 10.0f, 20.0f),
            frect(fpoint(-10, -20), fsize(143, 607)));
}

TEST(frect_test, intersection)
{
  EXPECT_EQ(intersection(frect(fpoint(0, 0), fsize(123, 567)),
                         frect(fpoint(10, 20), fsize(50, 60))),
            frect(fpoint(10, 20), fsize(50, 60)));
}

TEST(frect_test, overlapping)
{
  EXPECT_TRUE(intersects(frect(0, 0, 123, 567),
                         frect(10, 20, 50, 60)));
  EXPECT_TRUE(intersects(frect(0, 0, 123, 567),
                         frect(0, 0, 50, 60)));
  EXPECT_FALSE(intersects(frect(0, 0, 123, 567),
                          frect(-500, -500, -50, -60)));
}

TEST(frect_test, contains)
{
  EXPECT_TRUE(contains(frect(10, 20, 30, 40), fpoint(15, 25)));
  EXPECT_FALSE(contains(frect(10, 20, 30, 40), fpoint(-15, -19)));
}

TEST(frect_test, normalize)
{
  EXPECT_EQ(normalize(frect(10, 20, -30, -40)),
            frect(-30, -40, 10, 20));
  EXPECT_EQ(normalize(frect(10, 20, 30, -40)),
            frect(10, -40, 30, 20));
}

TEST(frect_test, unite)
{
  EXPECT_EQ(unite(frect(0, 0, 10, 20),
                  frect(30, 40, 50, 70)),
            frect(0, 0, 50, 70));
  EXPECT_EQ(unite(frect(30, 40, 50, 70),
                  frect(0, 0, 10, 20)),
            frect(0, 0, 50, 70));
}

TEST(frect_test, transpose)
{
  EXPECT_EQ(transpose(frect(fpoint(0, 0), fsize(10, 20))),
            frect(fpoint(0, 0), fsize(20, 10)));
  EXPECT_EQ(transpose(frect(fpoint(35, 24), fsize(10, 20))),
            frect(fpoint(35, 24), fsize(20, 10)));
}

TEST(frect_test, aspect_ratio)
{
  EXPECT_FLOAT_EQ(aspect_ratio(frect(fpoint(0, 0), fsize(400, 300))),
                  4.0f / 3.0f);
  EXPECT_FLOAT_EQ(aspect_ratio(frect(fpoint(50, 60), fsize(1600, 900))),
                  16.0f / 9.0f);
}

/* EOF */
