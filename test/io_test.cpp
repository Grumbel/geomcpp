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
#include <sstream>

#include <geom/geom.hpp>

using namespace geom;

TEST(io_test, ipoint)
{
  std::ostringstream out;
  out << ipoint(1, 2);
  EXPECT_EQ(out.str(), "ipoint(1, 2)");
}

TEST(io_test, isize)
{
  std::ostringstream out;
  out << isize(1, 2);
  EXPECT_EQ(out.str(), "isize(1, 2)");
}

TEST(io_test, irect)
{
  std::ostringstream out;
  out << irect(1, 2, 3, 4);
  EXPECT_EQ(out.str(), "irect(1, 2, 3, 4)");
}

TEST(io_test, fpoint)
{
  std::ostringstream out;
  out << fpoint(1, 2);
  EXPECT_EQ(out.str(), "fpoint(1, 2)");
}

TEST(io_test, fsize)
{
  std::ostringstream out;
  out << fsize(1, 2);
  EXPECT_EQ(out.str(), "fsize(1, 2)");
}

TEST(io_test, frect)
{
  std::ostringstream out;
  out << frect(1, 2, 3, 4);
  EXPECT_EQ(out.str(), "frect(1, 2, 3, 4)");
}

TEST(io_test, origin)
{
  std::ostringstream out;
  out << origin::TOP_LEFT;
  EXPECT_EQ(out.str(), "top-left");
}

/* EOF */
