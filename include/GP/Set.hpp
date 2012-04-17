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
#ifndef GP_SET_HPP_
#define GP_SET_HPP_

#include "Enum.hpp"
#include "detail/Set.hpp"

namespace GP {

/**
  * \brief show all available terminal types.
  */
inline detail::Terminal set_terminal()
{
    return detail::Terminal();
}

/**
  * \brief set_terminal to the specified type.
  */
inline detail::Terminal set_terminal( Terminal x )
{
    return detail::Terminal(x);
}

/**
  * \brief Display the current terminal.
  */
inline std::ostream& show_terminal( std::ostream& out )
{
    return out << "show terminal\n";
}

} // GP
#endif GP_SET_HPP_
