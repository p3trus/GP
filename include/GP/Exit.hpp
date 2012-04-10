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
#ifndef GP_EXIT_HPP_
#define GP_EXIT_HPP_

#include <iosfwd>
#include <stdexcept>

namespace GP {
/**
  * \brief exit gnuplot session
  */
inline std::ostream& exit( std::ostream& out );

/**
  * \brief quit gnuplot session
  */
inline std::ostream& quit( std::ostream& out );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

inline std::ostream& exit( std::ostream& out )
{
    return out << "exit\n";
}

inline std::ostream& quit( std::ostream& out )
{
    return out << "quit\n";
}

} // GP
#endif // GP_EXIT_HPP_
