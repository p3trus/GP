/* Copyright (C) 2012  Marco Halder
 *
 * This file is part of GP
 * GP is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GP_AXES_HPP_
#define GP_AXES_HPP_

#include <iosfwd>
#include <stdexcept>

namespace GP {
	
enum Axes
{
    x1y1, 
    x1y2,
    x2y1,
    x2y2
};

inline std::ostream& operator<<( std::ostream& out, Axes x );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

inline std::ostream& operator<<( std::ostream& out, Axes x )
{
    switch(x)
    {
        case x1y1:  return out << "x1y1";
        case x1y2:  return out << "x1y2";
        case x2y1:  return out << "x2y1";
        case x2y2:  return out << "x2y2";
        default:    throw std::runtime_error("invalid Axes enum");
    }
}

} // GP

#endif // GP_AXES_HPP_
