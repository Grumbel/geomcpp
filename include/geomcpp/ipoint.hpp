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

#ifndef HEADER_GEOMCPP_IPOINT_HPP
#define HEADER_GEOMCPP_IPOINT_HPP

#include <math.h>
#include <glm/glm.hpp>

namespace geomcpp {

class ipoint
{
public:
  constexpr ipoint(int x, int y) :
    m_x(x), m_y(y) {}
  constexpr ipoint(glm::ivec2 const& v) :
    m_x(v.x), m_y(v.y) {}
  constexpr ipoint(ipoint const& p) = default;

  constexpr int x() const { return m_x; }
  constexpr int y() const { return m_y; }

  constexpr bool operator==(const ipoint& other) const {
    return (m_x == other.m_x &&
            m_y == other.m_y);
  }

  constexpr bool operator!=(const ipoint& other) const {
    return !(*this == other);
  }

  glm::ivec2 as_vec() const { return glm::ivec2(m_x, m_y); }

private:
  int m_x;
  int m_y;
};

inline
float distance(ipoint const& lhs, ipoint const& rhs)
{
  float const a = static_cast<float>(rhs.x() - lhs.x());
  float const b = static_cast<float>(rhs.y() - lhs.y());
  return sqrtf(a * a + b * b);
}

inline
ipoint transpose(ipoint const point)
{
  return ipoint(point.y(), point.x());
}

} // namespace geomcpp

#endif

/* EOF */
