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
#ifndef GP_FORMAT_HPP_
#define GP_FORMAT_HPP_

#include <boost/mpl/assert.hpp>
#include <iosfwd>
#include <string>

namespace GP {

/**
  * Helper function to convert a C++ type to a gnuplot format string
  * \todo support every gnuplot supported type
  * \todo use boost preprocessor for code generation
  */
template<class type>
std::string format()
{
    BOOST_MPL_ASSERT_MSG( (boost::mpl::bool_< false >::value), TYPE_UNKNOWN_UNABLE_TO_AUTOGENERATE_GNUPLOT_FORMAT_STRING, () );
    return "";
}

template<> std::string format<int>()         { return "%int"; }
template<> std::string format<const int>()   { return "%int"; }

template<> std::string format<float>()         { return "%float"; }
template<> std::string format<const float>()   { return "%float"; }

template<> std::string format<double>()         { return "%double"; }
template<> std::string format<const double>()   { return "%double"; }

} // GP

#endif // GP_FORMAT_HPP_
