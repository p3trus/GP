# Copyright (C) 2012  Marco Halder
#
# This file is part of GP
# GP is free software: you can redistribute it and/or modify
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

# Add a target to compile example code.
set(Boost_ADDITIONAL_VERSIONS "1.49" "1.49.0")
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package( Boost 1.49.0 COMPONENTS iostreams filesystem REQUIRED )

if(Boost_FOUND)
   include_directories(${Boost_INCLUDE_DIRS})
   add_executable( example example.cpp )
   target_link_libraries(example ${Boost_LIBRARIES})
endif()