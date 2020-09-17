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

#ifndef HEADER_GEOMCPP_POINT_HPP
#define HEADER_GEOMCPP_POINT_HPP

#include <math.h>
#define GLM_FORCE_CTOR_INIT
#include <glm/glm.hpp>

#include "fwd.hpp"
#include "size.hpp"

namespace geom {

template<typename T>
class tpoint
{
public:
  constexpr tpoint() : m_x(), m_y() {}
  constexpr tpoint(T x, T y) :
    m_x(x), m_y(y) {}
  constexpr tpoint(glm::tvec2<T> const& v) :
    m_x(v.x), m_y(v.y) {}
  constexpr tpoint(tpoint const& p) = default;

  template<typename From>
  constexpr explicit tpoint<T>(tpoint<From> const& point) :
    m_x(static_cast<T>(point.x())),
    m_y(static_cast<T>(point.y()))
  {}

  constexpr T x() const { return m_x; }
  constexpr T y() const { return m_y; }

  constexpr bool operator==(const tpoint& other) const {
    return (m_x == other.m_x &&
            m_y == other.m_y);
  }

  constexpr bool operator!=(const tpoint& other) const {
    return !(*this == other);
  }

  glm::vec<2, T> as_vec() const { return glm::vec<2, T>(m_x, m_y); }

private:
  T m_x;
  T m_y;
};

template<typename T> inline
tpoint<T> operator+(tpoint<T> const& point, tsize<T> const& size)
{
  return tpoint<T>(point.x() + size.width(),
                   point.y() + size.height());
}

template<typename T> inline
tpoint<T> operator-(tpoint<T> const& point, tsize<T> const& size)
{
  return tpoint<T>(point.x() - size.width(),
                   point.y() - size.height());
}

template<typename T> inline
float distance(tpoint<T> const& lhs, tpoint<T> const& rhs)
{
  float const a = static_cast<float>(rhs.x() - lhs.x());
  float const b = static_cast<float>(rhs.y() - lhs.y());
  return sqrtf(a * a + b * b);
}

template<typename T> inline
tpoint<T> transpose(tpoint<T> const point)
{
  return tpoint<T>(point.y(), point.x());
}

using ipoint = tpoint<int>;
using fpoint = tpoint<float>;

} // namespace geom

#endif

/* EOF */
