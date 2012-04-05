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
#ifndef GP_HISTORY_HPP_
#define GP_HISTORY_HPP_

#include <boost/optional.hpp>
#include <iosfwd>
#include <string>

namespace GP {
class History
{
    friend std::ostream& operator<<( std::ostream& out, const History& h );
public:
    inline History();

    /**
     * \brief display the last n entries
     */
    inline History& entries( unsigned n );

    /**
     * \brief hide/show the entry numbers
     */
    inline History& quiet( bool mode=false );

    /**
     * \brief write history to file
     * @param path save path
     * @param append if true append to file, if false overwrite file
     */
    inline History& toFile( const std::string& path, bool append=false );

private:
    bool append_;
    unsigned entries_;
    boost::optional<std::string> path_;
    bool quiet_;
};

inline std::ostream& operator<<( std::ostream& out, const History& h );

inline History history();

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

inline History::History()
    : append_(false)
    , entries_(0)
    , path_()
    , quiet_(false)
{

}

inline History& History::entries( unsigned n )
{
    entries_ = n;
    return *this;
}

inline History& History::quiet( bool mode )
{
    quiet_ = mode;
    return *this;
}

inline History& History::toFile( const std::string& path, bool append )
{
    path_.reset( path );
    append_ = append;
    return *this;
}

inline std::ostream& operator<<( std::ostream& out, const History& h )
{
    out << "history";
    if( h.quiet_ )
        out << " quiet";

    if( h.entries_ )
        out << " " << h.entries_;
    if( h.path_ )
    {
        out << " " << h.path_;
        if( h.append_ )
            out << " " << h.append_;
    }
    return out << "\n";
}

inline History history()
{
    return History();
}

} // GP
#endif // GP_HISTORY_HPP_
