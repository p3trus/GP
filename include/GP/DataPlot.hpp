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
#ifndef GP_DATAPLOT_HPP_
#define GP_DATAPLOT_HPP_

#include "Config.hpp"

#include "BasicPlot.hpp"
#include "Binary.hpp"
#include "Endian.hpp"
#include "Format.hpp"
#include "Smooth.hpp"
#include <iterator>
#include <vector>

namespace GP {

template<class Derived>
class BasicDataPlot: public BasicPlot<Derived>
{
public:
    typedef typename BasicPlot<Derived>::derived_type derived_type;

    BasicDataPlot( std::string path );

    /**
      * \brief set the sampling array dimension of the binary file.
      * \note this has no effect if not in binary mode
      *
      * @param size number of samples in binary file.
      */
    derived_type& array( unsigned size );

    /**
      * \brief set the sampling array dimension of the binary file.
      * \note this has no effect if not in binary mode
      *
      * @param rows rows of the 2D sampling array
      * @param cols columns of the 2D sampling array
      *
      * \todo check if colmajor or rowmajor
      */
    derived_type& array( unsigned rows, unsigned cols );

    std::vector<unsigned> array() const;

    /**
      * \brief enable binary mode
      *
      * The binary keyword indicates that the data is stored as a binary file.
      */
    derived_type& binary();

    /**
     * return binary flag
     */
    bool binary() const;

    /**
      * \brief Set endian of binary data
      * \note This has no effect if not in binary mode.
      *
      * If the endianess of the binary data differs from the one of the platform gnuplot is running,
      * you can change it with this function.
      */
    derived_type& endian( Endian x );

    /**
      * return endian mode
      */
    boost::optional<Endian> endian() const;

    /**
      * set format string
      */
    derived_type& format( std::string x );

    /**
      * get format string
      */
    boost::optional<std::string> format() const;

    /**
     * \brief set matrix keyword
     */
    derived_type& matrix();

    /**
     *  return matrix flag
     */
    bool matrix() const;

    /**
      * \brief disable autoscale
      *
      * The noautoscale keyword means that the points making up this plot will be ignored when automatically
      * determining axis range limits.
      */
    derived_type& noautoscale();

    bool noautoscale() const;

    /**
      * \brief skip specified number of bytes in binary file.
      * \note This has no effect if not in binary mode.
      *
      * @param bytes number of bytes to skip in the binary file.
      */
    derived_type& skip( unsigned bytes );

    boost::optional<unsigned> skip() const;

    std::string path() const;

    derived_type& smooth( Smooth x );
    boost::optional<Smooth> smooth() const;

    /**
      * \brief enable volatile file handling
      *
      * The volatile keyword indicates that the contents of the data file may be different if the file is re-read.
      * This tells the program to use refresh rather than replot commands whenever possible.
      */
    derived_type& Volatile();

    /**
      * \brief return volatile flag
      */
    bool Volatile() const;

private:
    std::vector<unsigned> array_;
    bool binary_;
    boost::optional<Endian> endian_;
    boost::optional<std::string> format_;
    bool matrix_;
    bool noautoscale_;
    std::string path_;
    boost::optional<unsigned> skip_;
    boost::optional<Smooth> smooth_;
    bool volatile_;
};

template<class Derived>
std::ostream& operator<<( std::ostream& out, const BasicDataPlot<Derived>& p );

class DataPlot: public BasicDataPlot<DataPlot>
{
public:
    inline DataPlot( const std::string& path );
};

inline std::ostream& operator<<( std::ostream& out, const DataPlot& p );

inline DataPlot plot( const std::string& path );

template<class Iterator>
class DirectDataPlot: public BasicDataPlot<DirectDataPlot<Iterator> >
{
public:
    DirectDataPlot( Iterator first, Iterator last, std::string format = format<typename std::iterator_traits<Iterator>::value_type>() );

    Iterator first() const;
    Iterator last() const;
private:
    Iterator first_;
    Iterator last_;
};

template<class Iterator>
std::ostream& operator<<( std::ostream& out, const DirectDataPlot<Iterator>& p );

template<class Iterator>
DirectDataPlot<Iterator> plot( Iterator first, Iterator last );

template<class Iterator>
DirectDataPlot<Iterator> plot( Iterator first, Iterator last, std::string format );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

//------------BasicDataPlot---------------------------------
template<class Derived>
BasicDataPlot<Derived>::BasicDataPlot( std::string path )
    : BasicPlot<Derived>()
    , array_()
    , binary_( false )
    , endian_()
    , format_()
    , matrix_( false )
    , noautoscale_( false )
    , path_( path )
    , skip_()
    , smooth_()
    , volatile_( false )
{

}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::array( unsigned size )
{
    array_ = std::vector<unsigned> (1, size );
    return this->derived();
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::array( unsigned rows, unsigned cols )
{
    std::vector<unsigned> array(2);
    array[0] = rows;
    array[1] = cols;

    array_ = array;
    return this->derived();
}

template<class Derived>
std::vector<unsigned> BasicDataPlot<Derived>::array() const
{
    return array_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::binary()
{
    binary_ = true;
    return this->derived();
}

template<class Derived>
bool BasicDataPlot<Derived>::binary() const
{
    return binary_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::endian( Endian x )
{
    endian_.reset( x );
    return this->derived();
}

template<class Derived>
boost::optional<Endian> BasicDataPlot<Derived>::endian() const
{
    return endian_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::format( std::string x )
{
    format_.reset( x );
    return this->derived();
}

template<class Derived>
boost::optional<std::string> BasicDataPlot<Derived>::format() const
{
    return format_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::matrix()
{
    matrix_ = true;
    return this->derived();
}

template<class Derived>
bool BasicDataPlot<Derived>::matrix() const
{
    return matrix_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::noautoscale()
{
    noautoscale_ = true;
    return this->derived();
}

template<class Derived>
bool BasicDataPlot<Derived>::noautoscale() const
{
    return noautoscale_;
}

template<class Derived>
std::string BasicDataPlot<Derived>::path() const
{
    return path_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::skip( unsigned bytes )
{
    skip_.reset( bytes );
    return this->derived();
}

template<class Derived>
boost::optional<unsigned> BasicDataPlot<Derived>::skip() const
{
    return skip_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::smooth( Smooth x )
{
    smooth_.reset( x );
    return this->derived();
}

template<class Derived>
boost::optional<Smooth> BasicDataPlot<Derived>::smooth() const
{
    return smooth_;
}

template<class Derived>
typename BasicDataPlot<Derived>::derived_type& BasicDataPlot<Derived>::Volatile()
{
    volatile_ = true;
    return this->derived();
}

template<class Derived>
bool BasicDataPlot<Derived>::Volatile() const
{
    return volatile_;
}

template<class Derived>
std::ostream& operator<<( std::ostream& out, const BasicDataPlot<Derived>& p )
{

    out << "plot";
    
    if( p.xrange() )
        out << " [" << p.xrange()->first << ":" << p.xrange()->second << "]";
    if( p.yrange() )
        out << " [" << p.yrange()->first << ":" << p.yrange()->second << "]";

    out << " \"" << p.path() << "\"";
    if( p.binary() )
    {
        out << " binary";
        if( p.array().size() ==1 )
            out << " array=" << p.array()[0];
        else if( p.array().size() == 2 )
#if GP_GNUPLOT_VERSION > 4200
            out << " array=("<< p.array()[0]<<","<<p.array()[1]<<")";
#else
            out << " array=" << p.array()[0]<<"x"<<p.array()[1];            
#endif
        if( p.format() )
            out << " format=\"" << *p.format() << "\"";

        if( p.endian() )
            out << " endian=" << *p.endian();
        if( p.skip() )
            out << " skip=" << *p.skip();
    }
    if( p.matrix() )
        out << " matrix";
    if( p.smooth() )
        out << " smooth" << *p.smooth();
    if( p.Volatile() )
        out << " volatile";
    if( p.noautoscale() )
        out << " noautoscale";

    //general options
    if( p.axes() )
        out << " axes " << *p.axes();

    if( p.title() )
        out << " title \"" << *p.title() << "\"";
    else
        out << " notitle";

    if( p.style() )
        out << " with " << *p.style();
    return out;
}

//------------DataPlot--------------------------------------
inline DataPlot::DataPlot( const std::string& path )
    : BasicDataPlot<DataPlot>( path )
{

}

inline std::ostream& operator<<( std::ostream& out, const DataPlot& p )
{
    return out << static_cast<const BasicDataPlot<DataPlot>&>( p ) << "\n";
}

inline DataPlot plot( const std::string& path )
{
    return DataPlot( path );
}

//------------DirectDataPlot--------------------------------
template<class Iterator>
DirectDataPlot<Iterator>::DirectDataPlot( Iterator first, Iterator last, std::string format )
    : BasicDataPlot<DirectDataPlot<Iterator> >( "-" )
    , first_( first )
    , last_( last )
{
    this->array( std::distance( first_, last_ ) );
    this->binary(); // enable binary mode
    this->format( format );
}

template<class Iterator>
Iterator DirectDataPlot<Iterator>::first() const
{
    return first_;
}

template<class Iterator>
Iterator DirectDataPlot<Iterator>::last() const
{
    return last_;
}

template<class Iterator>
inline std::ostream& operator<<( std::ostream& out, const DirectDataPlot<Iterator>& p )
{
    return out  << static_cast<const BasicDataPlot<DirectDataPlot<Iterator> >&>( p ) 
                << "\n" << binary( p.first(), p.last() );
}

template<class Iterator>
DirectDataPlot<Iterator> plot( Iterator first, Iterator last)
{
    return DirectDataPlot<Iterator>( first, last);
}

template<class Iterator>
DirectDataPlot<Iterator> plot( Iterator first, Iterator last, std::string format )
{
    return DirectDataPlot<Iterator>( first, last, format );
}

} // GP

#endif // GP_DATAPLOT_HPP_
