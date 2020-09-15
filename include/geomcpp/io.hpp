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

#include "point.hpp"
#include "size.hpp"
#include "rect.hpp"

namespace geomcpp {

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

} // namespace geomcpp

#endif

/* EOF */
