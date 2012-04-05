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
#ifndef GP_STYLE_HPP_
#define GP_STYLE_HPP_

#include <iosfwd>
#include <stdexcept>

namespace GP {

enum Style
{
    lines,
    dots,
    steps,
    errorbars,
    xerrorbar,
    xyerrorlines,
    points,
    impulses,
    fsteps,
    errorlines,
    xerrorlines,
    yerrorbars,
    linespoints,
    labels,
    histeps,
    financebars,
    xyerrorbars,
    yerrorlines,
    vectors
};
inline std::ostream& operator<<( std::ostream& out, Style x );

enum FillableStyle
{
    boxes,
    candlesticks,
    image,
    circles,
    boxerrorbars,
    filledcurves,
    rgbimage,
    boxxyerrorbars,
    histograms,
    rgbalpha,
    pm3d
};
inline std::ostream& operator<<( std::ostream& out, FillableStyle x );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

inline std::ostream& operator<<( std::ostream& out, Style x )
{
    switch(x)
    {
        case lines:        return out << "lines";
        case dots:         return out << "dots";
        case steps:        return out << "steps";
        case errorbars:    return out << "errorbars";
        case xerrorbar:    return out << "xerrorbar";
        case xyerrorlines: return out << "xyerrorlines";
        case points:       return out << "points";
        case impulses:     return out << "impulses";
        case fsteps:       return out << "fsteps";
        case errorlines:   return out << "errorlines";
        case xerrorlines:  return out << "xerrorlines";
        case yerrorbars:   return out << "yerrorbars";
        case linespoints:  return out << "linespoints";
        case labels:       return out << "labels";
        case histeps:      return out << "histeps";
        case financebars:  return out << "financebars";
        case xyerrorbars:  return out << "xyerrorbars";
        case yerrorlines:  return out << "yerrorlines";
        case vectors:      return out << "vectors";
        default:    throw std::runtime_error("invalid Style enum");
    }
}

inline std::ostream& operator<<( std::ostream& out, FillableStyle x )
{
    switch(x)
    {
        case boxes:          return out << "boxes";
        case candlesticks:   return out << "candlesticks";
        case image:          return out << "image";
        case circles:        return out << "circles";
        case boxerrorbars:   return out << "boxerrorbars";
        case filledcurves:   return out << "filledcurves";
        case rgbimage:       return out << "rgbimage";
        case boxxyerrorbars: return out << "boxxyerrorbars";
        case histograms:     return out << "histograms";
        case rgbalpha:       return out << "rgbalpha";
        case pm3d:           return out << "pm3d";
        default:    throw std::runtime_error("invalid FilledStyle enum");
    }
}

} // GP

#endif // GP_STYLE_HPP_
