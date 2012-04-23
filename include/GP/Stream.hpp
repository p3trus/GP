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
#ifndef GP_STREAM_HPP_
#define GP_STREAM_HPP_

#include <boost/iostreams/device/file_descriptor.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/utility/base_from_member.hpp>
#include <boost/noncopyable.hpp>
//std
#include <cerrno>
#include <cstdio>
#include <stdexcept>
#include <iostream>

namespace GP {

/**\class OStreamPipe
 * \ingroup Utility
 * \brief <a href="http://www.boost.org/doc/libs/release/libs/iostreams/doc/index.html">
 * boost::iostream</a> wrapper around C style pipe
 *
 * OStreamPipe wraps a C style pipe inside a <a href="http://www.boost.org/doc/libs/release/libs/iostreams/doc/index.html">
 * boost::iostream</a> class. This allows std::iostream like reading and writing
 * with the << and >> operators.
 *
 * \par Example:
 * \code
 * // open gnuplot pipe
 * OStreamPipe pipe( "gnuplot -persist" );
 *
 * //create variables and the function and plot it
 * pipe	<< "a = 1" << "\n"
 * 	<< "b = 3.1" << "\n"
 * 	<< "f(x) = a*x +b" << "\n"
 * 	<< "plot f(x)" << std::endl;
 * \endcode
 *
 * \note OStreamPipe is not compatible with boost versions < 1.44.0.
 * \todo add support for MSVC compiler.( replace popen, fileno  with _popen, _fileno,...)
 */
class OStreamPipe
    : private boost::base_from_member<FILE *>,
      public  boost::iostreams::stream<boost::iostreams::file_descriptor_sink>,
              boost::noncopyable
{

private:
    typedef boost::base_from_member<FILE *> pipe_base;
    typedef boost::iostreams::stream<boost::iostreams::file_descriptor_sink> stream_base;

public:

    explicit OStreamPipe( const char* cmd )
        : pipe_base(popen(cmd, "w")),
          stream_base( fileno(this->pipe_base::member), boost::iostreams::never_close_handle)
    {
        if (!this->pipe_base::member)
            throw std::runtime_error(strerror(errno));
        if (!this->is_open())
            throw std::runtime_error("unable to open pipe");
    }

    ~OStreamPipe()
    {
    	close();
        pclose(this->pipe_base::member);
    }
};

/**
  * \brief Gnuplot is a small wrapper around a posix pipe to a gnuplot
  * instance.
  *
  * Gnuplot is a small wrapper around a posix pipe to a gnuplot instance.
  *
  * \note If you want to specify the location of the gnuplot binary or execute
  * it with different command line arguments, use OStreamPipe instead.
  *
  * \note The behaviour of the persistent mode (--persist) in windows differs
  * from the *nix behaviour. Since Windows has no \c fork() function, the
  * plotting windows are closed immediately after the destruction of the
  * Gnuplot instance. A solution to that is to use OStreamPipe to call
  * \a pgnuplot.exe instead.
  *
  */
class Gnuplot: public OStreamPipe
{
public:
    inline Gnuplot( bool persist=true )
        : OStreamPipe( persist ? "gnuplot -p" : "gnuplot" )
    {

    }
};

} // GP

#endif // GP_STREAM_HPP_
