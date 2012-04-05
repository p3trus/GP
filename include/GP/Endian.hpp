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
#ifndef GP_ENDIAN_HPP_
#define GP_ENDIAN_HPP_

#include <iosfwd>
#include <stdexcept>

namespace GP {
	
enum Endian
{
    little,
    big,
    swap
};

inline std::ostream& operator<<( std::ostream& out, Endian x );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

inline std::ostream& operator<<( std::ostream& out, Endian x )
{
    switch(x)
    {
        case little:    return out << "little";
        case big:       return out << "big";
        case swap:      return out << "swap";
        default:        throw std::runtime_error("invalid Endian enum");
    }
}

} // GP

#endif // GP_ENDIAN_HPP_
