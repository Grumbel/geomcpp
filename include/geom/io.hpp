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

#ifndef HEADER_GEOMCPP_IO_HPP
#define HEADER_GEOMCPP_IO_HPP

#include <ostream>
#include <stdexcept>

#include "origin.hpp"
#include "point.hpp"
#include "size.hpp"
#include "rect.hpp"

namespace geom {

inline
std::ostream& operator<<(std::ostream& os, ipoint const& point) {
  return os << "ipoint("
            << point.x() << ", "
            << point.y() << ")";
}

inline
std::ostream& operator<<(std::ostream& os, isize const& size) {
  return os << "isize("
            << size.width() << ", "
            << size.height() << ")";
}

inline
std::ostream& operator<<(std::ostream& os, irect const& rect) {
  return os << "irect("
            << rect.left() << ", "
            << rect.top() << ", "
            << rect.right() << ", "
            << rect.bottom() << ")";
}

inline
std::ostream& operator<<(std::ostream& os, fpoint const& point) {
  return os << "fpoint("
            << point.x() << ", "
            << point.y() << ")";
}

inline
std::ostream& operator<<(std::ostream& os, fsize const& size) {
  return os << "fsize("
            << size.width() << ", "
            << size.height() << ")";
}

inline
std::ostream& operator<<(std::ostream& os, frect const& rect) {
  return os << "frect("
            << rect.left() << ", "
            << rect.top() << ", "
            << rect.right() << ", "
            << rect.bottom() << ")";
}

inline
std::ostream& operator<<(std::ostream& os, origin origin)
{
  switch(origin)
  {
    case origin::TOP_LEFT: return os << "top-left";
    case origin::TOP_CENTER: return os << "top-center";
    case origin::TOP_RIGHT: return os << "top-right";
    case origin::CENTER_LEFT: return os << "center-left";
    case origin::CENTER: return os << "center";
    case origin::CENTER_RIGHT: return os << "center-right";
    case origin::BOTTOM_LEFT: return os << "bottom-left";
    case origin::BOTTOM_CENTER: return os << "bottom-center";
    case origin::BOTTOM_RIGHT: return os << "bottom-right";
    default: throw std::invalid_argument("invalid value for origin");
  }
}

} // namespace geom

#endif

/* EOF */
