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
#ifndef GP_ENUM_HPP_
#define GP_ENUM_HPP_

#include <boost/preprocessor.hpp>

/**
  * \brief Creates an enum named \a name with \a enum_tuple enumerators.
  *
  * This macro is used to create an enum definition.
  * This means
  * \code GP_ENUM_DEF( MyEnum, (first,second) ) \endcode
  * is equivalent to
  * \code
  * enum MyEnum
  * {
  *     first,
  *     second
  * };
  * \endcode
  * \sa GP_ENUM
  */
#define GP_ENUM_DEF( name, enum_tuple )                         \
enum name                                                       \
{                                                               \
    BOOST_PP_TUPLE_ENUM( enum_tuple )                           \
};

/**
  * \brief helper macro used in GP_ENUM_STREAM.
  * \sa GP_ENUM_STREAM,GP_ENUM
  */
#define GP_ENUM_DETAIL_CASE( r, data, enumerator )              \
case( enumerator ):return o << BOOST_PP_STRINGIZE( enumerator );

/**
  * \brief helper macro used in GP_ENUM_STREAM.
  * \sa GP_ENUM_STREAM,GP_ENUM
  */
#define GP_ENUM_DETAIL_CASES( enum_tuple )                      \
    BOOST_PP_SEQ_FOR_EACH(                                      \
        GP_ENUM_DETAIL_CASE,                                    \
        _,                                                      \
        BOOST_PP_TUPLE_TO_SEQ( enum_tuple ) )

/**
  * \brief Creates a std::ostream insertion operator for the enum named \a name
  *
  * GP_ENUM_STREAM is a helper macro that creates a std::ostream insertion
  * operator for a enumeration named \a name. That means a code like this
  * \code GP_ENUM_STREAM( MyEnum, (first, second)) \endcode
  * is equivalent to
  * \code
  * std::ostream& operator<<( std::ostream& o, MyEnum x )
  * {
  *     switch(x)
  *     {
  *         case( first ):  return o << "first";
  *         case( second ): return o << "second";
  *         default:    throw std::runtime_error("invalid enum");
  *     }
  * }
  * \endcode
  * \sa GP_ENUM
  */
#define GP_ENUM_STREAM( name, enum_tuple )                      \
inline std::ostream& operator<<(std::ostream& o, name x )       \
{                                                               \
    switch( x )                                                 \
    {                                                           \
        GP_ENUM_DETAIL_CASES( enum_tuple )                      \
        default:    throw std::runtime_error("invalid enum");   \
    }                                                           \
}

/**
  * \brief GP_ENUM creates an enum definition with name \a name, \a enum_tuple
  * enumerators and std::ostream& insertion operator.
  * \sa GP_ENUM_DEF,GP_ENUM_STREAM
  */
#define GP_ENUM( name, enum_tuple )                             \
    GP_ENUM_DEF( name, enum_tuple )                             \
    GP_ENUM_STREAM( name, enum_tuple )


namespace GP {

} // GP

#endif // GP_ENUM_HPP_
