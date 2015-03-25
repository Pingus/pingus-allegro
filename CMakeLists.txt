# Pingus Allegro Edition
# Copyright (C) 2015 Ingo Ruhnke <grumbel@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.0)
project(pingus-allegro VERSION 0.0.1)

include(FindPkgConfig)
pkg_search_module(ALLEGRO REQUIRED allegro)

file(GLOB PINGUS_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)

add_executable(pingus-allegro ${PINGUS_SOURCES})
target_compile_definitions(pingus-allegro PUBLIC -DVERSION="0.0.1")
target_link_libraries(pingus-allegro ${ALLEGRO_LIBRARIES})
target_include_directories(pingus-allegro PUBLIC ${ALLEGRO_INCLUDE_DIRS})

# EOF #
