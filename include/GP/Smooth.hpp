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
#ifndef GP_SMOOTH_HPP_
#define GP_SMOOTH_HPP_

#include <iosfwd>
#include <stdexcept>

namespace GP {
	
enum Smooth
{
    unique,
    frequency,
    cumulative,
    kdensity,
    csplines,
    acsplines,
    bezier,
    sbezier,
};
inline std::ostream& operator<<( std::ostream& out, Smooth x );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

inline std::ostream& operator<<( std::ostream& out, Smooth x )
{
    switch(x)
    {
        case unique:        return out << "unique";
        case frequency:     return out << "frequency";
        case cumulative:    return out << "cumulative";
        case kdensity:      return out << "kdensity";
        case csplines:      return out << "csplines";
        case acsplines:     return out << "acsplines";
        case bezier:        return out << "bezier";
        case sbezier:       return out << "sbezier";
        default:    throw std::runtime_error("invalid Smooth enum");
    }
}

} // GP

#endif // GP_SMOOTH_HPP_
