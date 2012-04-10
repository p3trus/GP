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
#ifndef GP_BINARY_HPP_
#define GP_BINARY_HPP_

#include <boost/utility.hpp>
#include <iosfwd>

namespace GP {
namespace detail {

template<class ForwardIterator>
struct _Binary
{
    _Binary( ForwardIterator first, ForwardIterator last );

    ForwardIterator first_;
    ForwardIterator last_;
};

/**
  * \note This function is based on an answer at 
  * <a href="http://stackoverflow.com/a/9775089/639650" rel="nofollow">stackoverflow</a>
  * by 
  * <a href="http://stackoverflow.com/users/596781/kerrek-sb" rel="nofollow">Kerrek SB</a>.
  */
template<class ForwardIterator>
std::ostream& operator<<( std::ostream& out, _Binary<ForwardIterator> b );

} // detail

template<class ForwardIterator>
detail::_Binary<ForwardIterator> binary( ForwardIterator first, ForwardIterator last );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {
namespace detail {

template<class ForwardIterator>
_Binary<ForwardIterator>::_Binary( ForwardIterator first, ForwardIterator last )
        : first_( first )
        , last_( last )
    {

    }

template<class ForwardIterator>
std::ostream& operator<<( std::ostream& out, _Binary<ForwardIterator> b )
{
    typedef typename std::iterator_traits<ForwardIterator>::value_type type;

    for ( ForwardIterator i=b.first_; i != b.last_; ++i)
    {
        out.write( reinterpret_cast<char const *>(boost::addressof(*i)), sizeof(type) );
    }
    return out;
}

} // detail

template<class ForwardIterator>
detail::_Binary<ForwardIterator> binary( ForwardIterator first, ForwardIterator last )
{
    return detail::_Binary<ForwardIterator>(first, last);
}

} // GP

#endif // GP_BINARY_HPP_
