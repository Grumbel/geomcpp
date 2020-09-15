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

#include "point.hpp"
#include "origin.hpp"

namespace geom {

template<typename T>
class tsize
{
public:
  constexpr tsize() = default;
  constexpr tsize(T width, T height) : m_width(width), m_height(height) {}
  explicit constexpr tsize<T>(glm::vec<2, T> const& v) : m_width(v.x), m_height(v.y) {}
  constexpr tsize<T>(tsize<T> const& size) = default;

  template<typename From>
  constexpr explicit tsize<T>(tsize<From> const& size) :
    m_width(static_cast<T>(size.width())),
    m_height(static_cast<T>(size.height()))
  {}

  constexpr T width() const { return m_width; }
  constexpr T height() const { return m_height; }

  glm::tvec2<T> as_vec() const { return glm::tvec2<T>(m_width, m_height); }

  constexpr bool operator==(const tsize<T>& other) const {
    return (m_width == other.m_width &&
            m_height == other.m_height);
  }

  constexpr bool operator!=(const tsize<T>& other) const {
    return !(*this == other);
  }

  constexpr explicit operator bool() const {
    return (m_width >= 0 &&
            m_height >= 0);
  }

private:
  T m_width;
  T m_height;
};

template<typename T> inline
tsize<T> operator*(T s, tsize<T> const& size) {
  return tsize<T>(s * size.width(),
                  s * size.height());
}

template<typename T> inline
tsize<T> operator*(tsize<T> const& size, T s) {
  return s * size;
}

template<typename T> inline
tsize<T> operator/(tsize<T> const& size, T s) {
  return tsize<T>(size.width() / s,
                  size.height() / s);
}

template<typename T> inline
T area(tsize<T> const& size) {
  return size.width() * size.height();
}

template<typename T> inline
tpoint<T> anchor_point(tsize<T> const& size, origin origin) {
  switch(origin)
  {
    case origin::TOP_LEFT:
      return tpoint<T>(0, 0);

    case origin::TOP_CENTER:
      return tpoint<T>(size.width() / 2, 0);

    case origin::TOP_RIGHT:
      return tpoint<T>(size.width(), 0);

    case origin::CENTER_LEFT:
      return tpoint<T>(0, size.height() / 2);

    case origin::CENTER:
      return tpoint<T>(size.width() / 2, size.height() / 2);

    case origin::CENTER_RIGHT:
      return tpoint<T>(size.width(), size.height() / 2);

    case origin::BOTTOM_LEFT:
      return tpoint<T>(0, size.height());

    case origin::BOTTOM_CENTER:
      return tpoint<T>(size.width() / 2, size.height());

    case origin::BOTTOM_RIGHT:
      return tpoint<T>(size.width(), size.height());
  }
}

template<typename T> inline
tsize<T> transpose(tsize<T> const& size)
{
  return tsize<T>(size.height(), size.width());
}

template<typename T> inline
float aspect_ratio(tsize<T> const& size)
{
  return static_cast<float>(size.width()) / static_cast<float>(size.height());
}

using isize = tsize<int>;
using fsize = tsize<float>;

} // namespace geom

#endif

/* EOF */
