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
#ifndef GP_BASICPLOT_HPP_
#define GP_BASICPLOT_HPP_

#include "Enum.hpp"
#include <boost/optional.hpp>
#include <iosfwd>
#include <string>
#include <utility>

namespace GP {
	
/**
 * Provides the basic functionality for both function and dataplots.
 *
 * \todo better member fn documentation
 */
template<class Derived>
class BasicPlot
{
public:
    typedef Derived derived_type;
    typedef std::pair<double,double> Range;

    /**
     * casts *this to derived_type& and returns it.
     */
    derived_type& derived();

    /**
     * casts *this to const derived_type& and returns it.
     */
    const derived_type& derived() const;

    derived_type& axes( Axes x);
    boost::optional<Axes> axes() const;

    derived_type& style( Style x );
    boost::optional<Style> style() const;

    derived_type& title( const std::string& title );
    boost::optional<std::string> title() const;

    derived_type& xrange( double min, double max );
    boost::optional<Range> xrange() const;

    derived_type& yrange( double min, double max );
    boost::optional<Range> yrange() const;

private:
    boost::optional<Axes> axes_;
    boost::optional<Style> style_;
    boost::optional<std::string> title_;
    boost::optional<Range> xrange_;
    boost::optional<Range> yrange_;
};

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

template<class Derived>
typename BasicPlot<Derived>::derived_type& BasicPlot<Derived>::derived()
{
    return static_cast<derived_type&>( *this );
}

template<class Derived>
const typename BasicPlot<Derived>::derived_type& BasicPlot<Derived>::derived() const
{
    return static_cast<const derived_type&>( *this );
}

template<class Derived>
typename BasicPlot<Derived>::derived_type& BasicPlot<Derived>::axes( Axes x )
{
    axes_.reset( x );
    return derived();
}

template<class Derived>
boost::optional<Axes> BasicPlot<Derived>::axes() const
{
    return axes_;
}

template<class Derived>
typename BasicPlot<Derived>::derived_type& BasicPlot<Derived>::style( Style x )
{
    style_.reset( x );
    return derived();
}

template<class Derived>
boost::optional<Style> BasicPlot<Derived>::style() const
{
    return style_;
}

template<class Derived>
typename BasicPlot<Derived>::derived_type& BasicPlot<Derived>::title( const std::string& x )
{
    title_.reset( x );
    return derived();
}

template<class Derived>
boost::optional<std::string> BasicPlot<Derived>::title() const
{
    return title_;
}

template<class Derived>
typename BasicPlot<Derived>::derived_type& BasicPlot<Derived>::xrange( double min, double max )
{
    xrange_.reset( std::make_pair( min, max ) );
    return derived();
}

template<class Derived>
boost::optional<typename BasicPlot<Derived>::Range> BasicPlot<Derived>::xrange() const
{
    return xrange_;
}

template<class Derived>
typename BasicPlot<Derived>::derived_type& BasicPlot<Derived>::yrange( double min, double max )
{
    yrange_.reset( std::make_pair( min, max ) );
    return derived();
}

template<class Derived>
boost::optional<typename BasicPlot<Derived>::Range> BasicPlot<Derived>::yrange() const
{
    return yrange_;
}

} // GP

#endif // GP_BASICPLOT_HPP_
