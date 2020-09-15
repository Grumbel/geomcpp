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

#ifndef HEADER_GEOMCPP_ISIZE_HPP
#define HEADER_GEOMCPP_ISIZE_HPP

#include <glm/glm.hpp>

#include "ipoint.hpp"
#include "origin.hpp"

namespace geomcpp {

class isize
{
public:
  constexpr isize(int width, int height) : m_width(width), m_height(height) {}
  explicit constexpr isize(glm::ivec2 const& v) : m_width(v.x), m_height(v.y) {}
  constexpr isize(isize const& size) = default;

  constexpr int width() const { return m_width; }
  constexpr int height() const { return m_height; }

  glm::ivec2 as_vec() const { return glm::ivec2(m_width, m_height); }

  constexpr bool operator==(const isize& other) const {
    return (m_width == other.m_width &&
            m_height == other.m_height);
  }

  constexpr bool operator!=(const isize& other) const {
    return !(*this == other);
  }

  constexpr operator bool() const {
    return (m_width >= 0 &&
            m_height >= 0);
  }

private:
  int m_width;
  int m_height;
};

inline
isize operator*(int s, isize const& size) {
  return isize(s * size.width(),
               s * size.height());
}

inline
isize operator*(isize const& size, int s) {
  return s * size;
}

inline
int area(isize const& size) {
  return size.width() * size.height();
}

inline
ipoint anchor_point(isize const& size, Origin origin) {
  switch(origin)
  {
    case Origin::TOP_LEFT:
      return ipoint(0, 0);

    case Origin::TOP_CENTER:
      return ipoint(size.width() / 2, 0);

    case Origin::TOP_RIGHT:
      return ipoint(size.width(), 0);

    case Origin::CENTER_LEFT:
      return ipoint(0, size.height() / 2);

    case Origin::CENTER:
      return ipoint(size.width() / 2, size.height() / 2);

    case Origin::CENTER_RIGHT:
      return ipoint(size.width(), size.height() / 2);

    case Origin::BOTTOM_LEFT:
      return ipoint(0, size.height());

    case Origin::BOTTOM_CENTER:
      return ipoint(size.width() / 2, size.height());

    case Origin::BOTTOM_RIGHT:
      return ipoint(size.width(), size.height());
  }
}

inline
isize transpose(isize const& size)
{
  return isize(size.height(), size.width());
}

inline
float aspect_ratio(isize const& size)
{
  return static_cast<float>(size.width()) / static_cast<float>(size.height());
}

} // namespace geomcpp

#endif

/* EOF */
