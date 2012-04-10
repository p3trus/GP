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
#ifndef GP_FUNCTIONPLOT_HPP_
#define GP_FUNCTIONPLOT_HPP_

#include "BasicPlot.hpp"

namespace GP {
	
class FunctionPlot: public BasicPlot<FunctionPlot> 
{
public:
    FunctionPlot( std::string function );

    std::string function() const;

    derived_type& trange( double min, double max );
    boost::optional<Range> trange() const;
private:
    std::string function_;
    boost::optional<Range> trange_;
};

inline std::ostream& operator<<( std::ostream& out, const FunctionPlot& p );

inline FunctionPlot plotFunction( const std::string& function );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

FunctionPlot::FunctionPlot( std::string function )
    : BasicPlot<FunctionPlot>()
    , function_( function )
{

}

std::string FunctionPlot::function() const
{
    return function_;
}

FunctionPlot::derived_type& FunctionPlot::trange( double min, double max )
{
    trange_.reset( std::make_pair( min, max ) );
    return derived();
}

boost::optional<FunctionPlot::Range> FunctionPlot::trange() const
{
    return trange_;
}

inline std::ostream& operator<<( std::ostream& out, const FunctionPlot& p )
{
    out << "plot";
    if( p.trange() )
        out << " [" << p.trange()->first << ":" << p.trange()->second << "]";
    if( p.xrange() )
        out << " [" << p.xrange()->first << ":" << p.xrange()->second << "]";
    if( p.yrange() )
        out << " [" << p.yrange()->first << ":" << p.yrange()->second << "]";

    out << " " << p.function();

    if( p.axes() )
        out << " axes " << *p.axes();

    if( p.title() )
        out << " title \"" << *p.title() << "\"";
    else
        out << " notitle";

    if( p.style() )
        out << " with " << *p.style();
    return out << "\n";
}

inline FunctionPlot plotFunction( const std::string& function )
{
    return FunctionPlot( function );
}

} // GP

#endif // GP_FUNCTIONPLOT_HPP_
