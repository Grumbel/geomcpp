# geomcpp - Basic collection of point, size and rect classes
# Copyright (C) 2020 Ingo Ruhnke <grumbel@gmail.com>
#
# This software is provided 'as-is', without any express or implied
# warranty.  In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Permission is granted to anyone to use this software for any purpose,
# including commercial applications, and to alter it and redistribute it
# freely, subject to the following restrictions:
#
# 1. The origin of this software must not be misrepresented; you must not
#    claim that you wrote the original software. If you use this software
#    in a product, an acknowledgment in the product documentation would be
#    appreciated but is not required.
# 2. Altered source versions must be plainly marked as such, and must not be
#    misrepresented as being the original software.
# 3. This notice may not be removed or altered from any source distribution.

cmake_minimum_required(VERSION 3.6)
project(geomcpp VERSION 0.0.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/external/cmake-modules/)

include(GNUInstallDirs)
include(MaximumWarnings)
include(ClangTidy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT TARGET glm::glm)
  find_package(glm REQUIRED)
endif()

add_library(geomcpp INTERFACE)
target_include_directories(geomcpp INTERFACE include/)
target_link_libraries(geomcpp INTERFACE glm::glm)
set_target_properties(geomcpp PROPERTIES PUBLIC_HEADER
  "include/ipoint.hpp"
  "include/isize.hpp"
  "include/irect.hpp")

if(BUILD_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)

  # build automatic tests
  file(GLOB TEST_GEOMCPP_SOURCES test/*_test.cpp)
  add_executable(test_geomcpp ${TEST_GEOMCPP_SOURCES})
  target_compile_options(test_geomcpp PRIVATE ${WARNINGS_CXX_FLAGS})
  target_link_libraries(test_geomcpp
    GTest::GTest
    GTest::Main
    geomcpp)

  set(ARGV "-V")
  add_test(NAME test_geomcpp
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND test_geomcpp)
endif()

# EOF #
