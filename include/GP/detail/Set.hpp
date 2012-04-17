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

#include "../Enum.hpp"
#include <string>

namespace GP {
namespace detail {

struct Angles
{
    GP::Angles angles;

    Angles( GP::Angles x ): angles(x) {}
};

std::ostream& operator <<(std::ostream& o, Angles x)
{
    return " set angles " << x->angles << "\n";
}

struct Output
{
    boost::optional<std::string> path;
    Output() {}
    Output( std::string x ): path(x){}
};

std::ostream& operator << ( std::ostream& o, Output x )
{
    o << " set output";
    if( x.path )
    {
        if( x->path.empty() )
            throw std::runtime_error("empty path string in set_output");
        o << " " << x->path;
    }
    return o << "\n";
}

struct Terminal
{
    boost::optional<GP::Terminal> terminal;

    Terminal(){}
    Terminal( GP::Terminal x ) : terminal(x) {}
};

inline std::ostream& operator<<( std::ostream& o, Terminal x )
{
    o << " set terminal";
    if( x.terminal )
        o << " " << x->terminal;
    return o << "\n";
}

} // detail
} // GP
#endif GP_SET_HPP_
