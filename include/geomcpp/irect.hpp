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

class irect
{
public:
  constexpr irect(ipoint const& p, isize const& size) :
    m_point(p), m_size(size) {}
  constexpr irect(ipoint const& lt, ipoint const& rb) :
    m_point(lt), m_size(rb.x() - lt.x(), rb.y() - lt.y()) {}
  constexpr irect(int left, int top, int right, int bottom) :
    m_point(left, top), m_size(right - left, bottom - top) {}
  constexpr irect(irect const& rect) = default;

  constexpr ipoint lt() const { return m_point; }
  constexpr ipoint rb() const { return ipoint(right(), bottom()); }
  constexpr ipoint rt() const { return ipoint(right(), top()); }
  constexpr ipoint lb() const { return ipoint(left(), bottom()); }

  constexpr isize size() const { return m_size; }

  constexpr int left() const { return m_point.x(); }
  constexpr int right() const { return m_point.x() + m_size.width(); }
  constexpr int top() const { return m_point.y(); }
  constexpr int bottom() const { return m_point.y() + m_size.height(); }

  constexpr int x() const { return m_point.x(); }
  constexpr int y() const { return m_point.y(); }
  constexpr int w() const { return m_size.width(); }
  constexpr int h() const { return m_size.height(); }

  constexpr int width() const { return m_size.width(); }
  constexpr int height() const { return m_size.height(); }

  constexpr bool operator==(const irect& other) const {
    return (m_point == other.m_point &&
            m_size == other.m_size);
  }

  constexpr bool operator!=(const irect& other) const {
    return !((*this) == other);
  }

  constexpr operator bool() const {
    return (m_size.width() >=0 &&
            m_size.height() >=0);
  }

private:
  ipoint m_point;
  isize m_size;
};

inline
int area(irect const& rect) {
  return area(rect.size());
}

inline
irect grow(irect const& rect, int v) {
  return irect(rect.left() - v,
               rect.top() - v,
               rect.right() + v,
               rect.bottom() + v);
}

inline
irect grow(irect const& rect, int x, int y) {
  return irect(rect.left() - x,
               rect.top() - y,
               rect.right() + x,
               rect.bottom() + y);
}

inline
irect intersection(irect const& lhs, irect const& rhs) {
  return irect(std::max(lhs.left(), rhs.left()),
               std::max(lhs.top(), rhs.top()),
               std::min(lhs.right(), rhs.right()),
               std::min(lhs.bottom(), rhs.bottom()));
}

inline
bool overlapping(irect const& lhs, irect const& rhs) {
  return static_cast<bool>(intersection(lhs, rhs));
}

inline
bool contains(irect const& rect, ipoint const& point) {
  return (rect.left() <= point.x() &&
          rect.top() <= point.y() &&
          point.x() < rect.right() &&
          point.y() < rect.bottom());
}

inline
irect normalized(irect const& rect) {
  return irect(std::min(rect.left(), rect.right()),
               std::min(rect.top(), rect.bottom()),
               std::max(rect.left(), rect.right()),
               std::max(rect.top(), rect.bottom()));
}

inline
ipoint center(irect const& rect) {
  return ipoint(rect.left() + rect.width() / 2,
                rect.top() + rect.height() / 2);
}

inline
ipoint anchor_point(irect const& rect, Origin origin) {
  ipoint const p = anchor_point(rect.size(), origin);
  return ipoint(p.x() + rect.x(),
                p.y() + rect.y());
}

inline
irect anchored_rect(isize const& size, Origin origin) {
  return irect(anchor_point(size, origin),
               size);
}

inline
irect anchored(irect const& rect, Origin origin) {
  return irect(anchor_point(rect.size(), origin),
               rect.size());
}

} // namespace geomcpp

#endif

/* EOF */
