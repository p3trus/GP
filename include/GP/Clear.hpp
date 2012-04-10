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
#ifndef GP_CLEAR_HPP_
#define GP_CLEAR_HPP_

#include <iosfwd>
#include <stdexcept>

namespace GP {

/**
  * \brief clear erases the current screen or output device.
  * \note clear will flush the stream and start a newline.
  */
inline std::ostream& clear( std::ostream& out );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

inline std::ostream& clear( std::ostream& out )
{
    return out << "clear\n" << std::endl;
}

} // GP

#endif // GP_CLEAR_HPP_
