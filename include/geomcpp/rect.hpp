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

#ifndef HEADER_GEOMCPP_IRECT_HPP
#define HEADER_GEOMCPP_IRECT_HPP

#include <algorithm>
#include <math.h>
#include <glm/glm.hpp>

#include "origin.hpp"

namespace geomcpp {

template<typename T>
class trect
{
public:
  constexpr trect(tpoint<T> const& p, tsize<T> const& size) :
    m_point(p), m_size(size) {}
  constexpr trect(tpoint<T> const& lt, tpoint<T> const& rb) :
    m_point(lt), m_size(rb.x() - lt.x(), rb.y() - lt.y()) {}
  constexpr trect(T left, T top, T right, T bottom) :
    m_point(left, top), m_size(right - left, bottom - top) {}
  constexpr trect(trect<T> const& rect) = default;

  constexpr tpoint<T> lt() const { return m_point; }
  constexpr tpoint<T> rb() const { return tpoint<T>(right(), bottom()); }
  constexpr tpoint<T> rt() const { return tpoint<T>(right(), top()); }
  constexpr tpoint<T> lb() const { return tpoint<T>(left(), bottom()); }

  constexpr tpoint<T> point() const { return m_point; }
  constexpr tsize<T> size() const { return m_size; }

  constexpr T left() const { return m_point.x(); }
  constexpr T right() const { return m_point.x() + m_size.width(); }
  constexpr T top() const { return m_point.y(); }
  constexpr T bottom() const { return m_point.y() + m_size.height(); }

  constexpr T x() const { return m_point.x(); }
  constexpr T y() const { return m_point.y(); }
  constexpr T w() const { return m_size.width(); }
  constexpr T h() const { return m_size.height(); }

  constexpr T width() const { return m_size.width(); }
  constexpr T height() const { return m_size.height(); }

  constexpr bool operator==(const trect<T>& other) const {
    return (m_point == other.m_point &&
            m_size == other.m_size);
  }

  constexpr bool operator!=(const trect<T>& other) const {
    return !((*this) == other);
  }

  constexpr explicit operator bool() const {
    return (m_size.width() >=0 &&
            m_size.height() >=0);
  }

private:
  tpoint<T> m_point;
  tsize<T> m_size;
};

template<typename T> inline
int area(trect<T> const& rect) {
  return area(rect.size());
}

template<typename T> inline
trect<T> grow(trect<T> const& rect, T v) {
  return trect<T>(rect.left() - v,
                  rect.top() - v,
                  rect.right() + v,
                  rect.bottom() + v);
}

template<typename T> inline
trect<T> grow(trect<T> const& rect, T x, T y) {
  return trect<T>(rect.left() - x,
                  rect.top() - y,
                  rect.right() + x,
                  rect.bottom() + y);
}

template<typename T> inline
trect<T> intersection(trect<T> const& lhs, trect<T> const& rhs) {
  return trect<T>(std::max(lhs.left(), rhs.left()),
                  std::max(lhs.top(), rhs.top()),
                  std::min(lhs.right(), rhs.right()),
                  std::min(lhs.bottom(), rhs.bottom()));
}

template<typename T> inline
bool intersects(trect<T> const& lhs, trect<T> const& rhs) {
  return static_cast<bool>(intersection(lhs, rhs));
}

template<typename T> inline
bool contains(trect<T> const& rect, tpoint<T> const& point) {
  return (rect.left() <= point.x() &&
          rect.top() <= point.y() &&
          point.x() < rect.right() &&
          point.y() < rect.bottom());
}

template<typename T> inline
trect<T> normalize(trect<T> const& rect) {
  return trect<T>(std::min(rect.left(), rect.right()),
                  std::min(rect.top(), rect.bottom()),
                  std::max(rect.left(), rect.right()),
                  std::max(rect.top(), rect.bottom()));
}

template<typename T> inline
tpoint<T> center(trect<T> const& rect) {
  return tpoint<T>(rect.left() + rect.width() / 2,
                   rect.top() + rect.height() / 2);
}

template<typename T> inline
tpoint<T> anchor_point(trect<T> const& rect, origin origin) {
  tpoint<T> const p = anchor_point(rect.size(), origin);
  return tpoint<T>(p.x() + rect.x(),
                   p.y() + rect.y());
}

template<typename T> inline
trect<T> anchored_rect(tsize<T> const& size, origin origin) {
  return trect<T>(anchor_point(size, origin),
                  size);
}

template<typename T> inline
trect<T> anchored(trect<T> const& rect, origin origin) {
  return trect<T>(anchor_point(rect.size(), origin),
                  rect.size());
}

/** Create a rectangle that contain boths lhs and rhs */
template<typename T> inline
trect<T> unite(trect<T> const& lhs, trect<T> const& rhs)
{
  return trect<T>(std::min(lhs.left(), rhs.left()),
                  std::min(lhs.top(), rhs.top()),
                  std::max(lhs.right(), rhs.right()),
                  std::max(lhs.bottom(), rhs.bottom()));
}

template<typename T> inline
trect<T> transpose(trect<T> const& rect)
{
  return trect<T>(rect.point(), transpose(rect.size()));
}

template<typename T> inline
float aspect_ratio(trect<T> const& rect)
{
  return static_cast<float>(rect.size().width()) / static_cast<float>(rect.size().height());
}

using irect = trect<int>;
using frect = trect<float>;

} // namespace geomcpp

#endif

/* EOF */
