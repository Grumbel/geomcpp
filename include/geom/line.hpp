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

#ifndef HEADER_GEOM_LINE_HPP
#define HEADER_GEOM_LINE_HPP

#include <glm/glm.hpp>

namespace geom {

class line
{
public:
  glm::vec2 p1;
  glm::vec2 p2;

  line() : p1(), p2() {}

  line(const glm::vec2& p1,
       const glm::vec2& p2);

  float length() const;

  /** Calculate if two lines intersec */
  bool intersect(const line& line_b) const;

  /** Calculate if and where two lines intersect */
  bool intersect(const line& line_b, float& ua, float& ub) const;

  /** Calculate if and where two lines intersect */
  bool intersect(const line& line, glm::vec2& colpos) const;

  /** Calculate the minimal distance between this line and the point p */
  float distance(const glm::vec2& p) const;
};

} // namespace geom

#endif

/* EOF */
