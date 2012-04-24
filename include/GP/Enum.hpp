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
#include <iostream>

/**
  * \brief Creates an enum named \a name with \a enum_seq enumerators.
  *
  * This macro is used to create an enum definition.
  * This means
  * \code GP_ENUM_DEF( MyEnum, (first)(second) ) \endcode
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
#define GP_ENUM_DEF( name, enum_seq )                           \
enum name                                                       \
{                                                               \
    BOOST_PP_SEQ_ENUM( enum_seq )                               \
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
#define GP_ENUM_DETAIL_CASES( enum_seq )                        \
    BOOST_PP_SEQ_FOR_EACH(                                      \
        GP_ENUM_DETAIL_CASE,                                    \
        _,                                                      \
        enum_seq)

/**
  * \brief Creates a std::ostream insertion operator for the enum named \a name
  *
  * GP_ENUM_STREAM is a helper macro that creates a std::ostream insertion
  * operator for a enumeration named \a name. That means a code like this
  * \code GP_ENUM_STREAM( MyEnum, (first)(second)) \endcode
  * is equivalent to
  * \code
  * std::ostream& operator<<( std::ostream& o, MyEnum x )
  * {
  *     switch(x)
  *     {
  *         case( first ):  return o << "first";
  *         case( second ): return o << "second";
  *     }
  * }
  * \endcode
  * \sa GP_ENUM
  */
#define GP_ENUM_STREAM( name, enum_seq )                        \
inline std::ostream& operator<<(std::ostream& o, GP::name x )       \
{                                                               \
    switch( x )                                                 \
    {                                                           \
        GP_ENUM_DETAIL_CASES( enum_seq )                        \
    }                                                           \
}

/**
  * \brief GP_ENUM creates an enum definition with name \a name, \a enum_seq
  * enumerators and std::ostream& insertion operator.
  * \sa GP_ENUM_DEF,GP_ENUM_STREAM
  */
#define GP_ENUM( name, enum_seq )                               \
    GP_ENUM_DEF( name, enum_seq )                               \
    GP_ENUM_STREAM( name, enum_seq )

namespace GP {

/**
  * \enum Angles
  */
GP_ENUM( Angles, (degrees)(radians) )

/**
  * \enum Axes
  */
GP_ENUM( Axes, (x1y1)(x1y2)(x2y1)(x2y2) )

/**
  * \enum Endian
  */
GP_ENUM( Endian, (little)(big)(swap) )

/**
  * \enum Smooth
  */
GP_ENUM( Smooth,
            (unique)
            (frequency)
            (cumulative)
            (kdensity)
            (csplines)
            (acsplines)
            (bezier)
            (sbezier)
        )

/**
  * \enum Style
  */
GP_ENUM( Style,
            (lines)
            (dots)
            (steps)
            (errorbars)
            (xerrorbar)
            (xyerrorlines)
            (points)
            (impulses)
            (fsteps)
            (errorlines)
            (xerrorlines)
            (yerrorbars)
            (linespoints)
            (labels)
            (histeps)
            (financebars)
            (xyerrorbars)
            (yerrorlines)
            (vectors)
        )

/**
  * \enum FillableStyle
  */
GP_ENUM( FillableStyle,
            (boxes)
            (candlesticks)
            (image)
            (circles)
            (boxerrorbars)
            (filledcurves)
            (rgbimage)
            (boxxyerrorbars)
            (histograms)
            (rgbalpha)
            (pm3d)
        )

GP_ENUM( Terminal,
            (push)
            (pop)
            (canvas)         //HTML Canvas object
            (cgm)            //Computer Graphics Metafile
            (corel)          //EPS format for CorelDRAW
            (dpu414)         //Seiko DPU-414 thermal printer [small medium large]
            (dumb)           //ascii art for anything that prints text
            (dxf)            //dxf-file for AutoCad (default size 120x80)
            (eepic)          //EEPIC -- extended LaTeX picture environment
            (emf)            //Enhanced Metafile format
            (emtex)          //LaTeX picture environment with emTeX specials
            (epslatex)       //LaTeX picture environment using graphicx package
            (epson_180dpi)   //Epson LQ-style 180-dot per inch (24 pin) printers
            (epson_60dpi)    //Epson-style 60-dot per inch printers
            (epson_lx800)    //Epson LX-800, Star NL-10, NX-1000, PROPRINTER ...
            (fig)            //FIG graphics language for XFIG graphics editor
            (gif)            //GIF images using libgd and TrueType fonts
            (hp2623A)        //HP2623A and maybe others
            (hp2648)         //HP2648 and HP2647
            (hp500c)         //HP DeskJet 500c, [75 100 150 300] [rle tiff]
            (hpdj)           //HP DeskJet 500, [75 100 150 300]
            (hpgl)           //HP7475 and relatives [number of pens] [eject]
            (hpljii)         //HP Laserjet series II, [75 100 150 300]
            (hppj)           //HP PaintJet and HP3630 [FNT5X9 FNT9X17 FNT13X25]
            (imagen)         //Imagen laser printer
            (jpeg)           //JPEG images using libgd and TrueType fonts
            (latex)          //LaTeX picture environment
            (mf)             //Metafont plotting standard
            (mif)            //Frame maker MIF 3.00 format
            (mp)             //MetaPost plotting standard
            (nec_cp6)        //NEC printer CP6, Epson LQ-800 [monocrome color draft]
            (okidata)        //OKIDATA 320/321 Standard
            (pbm)            //Portable bitmap [small medium large] [monochrome gray color]
            (pcl5)           //HP Designjet 750C, HP Laserjet III/IV, etc. (many options)
            (png)            //PNG images using libgd and TrueType fonts
            (postscript)     //PostScript graphics, including EPSF embedded files (*.eps)
            (pslatex)        //LaTeX picture environment with PostScript \specials
            (pstex)          //plain TeX with PostScript \specials
            (pstricks)       //LaTeX picture environment with PSTricks macros
            (qms)            //QMS/QUIC Laser printer (also Talaris 1200 and others)
            (starc)          //Star Color Printer
            (svg)            //W3C Scalable Vector Graphics driver
            (tandy_60dpi)    //Tandy DMP-130 series 60-dot per inch graphics
            (texdraw)        //LaTeX texdraw environment
            (tgif)           //TGIF X11 [mode] [x,y] [dashed] ["font" [fontsize]]
            (tkcanvas)       //Tk/Tcl canvas widget [perltk] [interactive]
            (tpic)           //TPIC -- LaTeX picture environment with tpic \specials
            (unknown)        //Unknown terminal type - not a plotting device
            (windows)        //Microsoft Windows
        )

} // GP

#endif // GP_ENUM_HPP_
