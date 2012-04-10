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
#ifndef GP_TERMINAL_HPP_
#define GP_TERMINAL_HPP_

#include <iosfwd>
#include <stdexcept>

namespace GP {

enum Terminal
{
    push,
    pop,
    canvas,         //HTML Canvas object
    cgm,            //Computer Graphics Metafile
    corel,          //EPS format for CorelDRAW
    dpu414,         //Seiko DPU-414 thermal printer [small medium large]
    dumb,           //ascii art for anything that prints text
    dxf,            //dxf-file for AutoCad (default size 120x80)
    eepic,          //EEPIC -- extended LaTeX picture environment
    emf,            //Enhanced Metafile format
    emtex,          //LaTeX picture environment with emTeX specials
    epslatex,       //LaTeX picture environment using graphicx package
    epson_180dpi,   //Epson LQ-style 180-dot per inch (24 pin) printers
    epson_60dpi,    //Epson-style 60-dot per inch printers
    epson_lx800,    //Epson LX-800, Star NL-10, NX-1000, PROPRINTER ...
    fig,            //FIG graphics language for XFIG graphics editor
    gif,            //GIF images using libgd and TrueType fonts
    hp2623A,        //HP2623A and maybe others
    hp2648,         //HP2648 and HP2647
    hp500c,         //HP DeskJet 500c, [75 100 150 300] [rle tiff]
    hpdj,           //HP DeskJet 500, [75 100 150 300]
    hpgl,           //HP7475 and relatives [number of pens] [eject]
    hpljii,         //HP Laserjet series II, [75 100 150 300]
    hppj,           //HP PaintJet and HP3630 [FNT5X9 FNT9X17 FNT13X25]
    imagen,         //Imagen laser printer
    jpeg,           //JPEG images using libgd and TrueType fonts
    latex,          //LaTeX picture environment
    mf,             //Metafont plotting standard
    mif,            //Frame maker MIF 3.00 format
    mp,             //MetaPost plotting standard
    nec_cp6,        //NEC printer CP6, Epson LQ-800 [monocrome color draft]
    okidata,        //OKIDATA 320/321 Standard
    pbm,            //Portable bitmap [small medium large] [monochrome gray color]
    pcl5,           //HP Designjet 750C, HP Laserjet III/IV, etc. (many options)
    png,            //PNG images using libgd and TrueType fonts
    postscript,     //PostScript graphics, including EPSF embedded files (*.eps)
    pslatex,        //LaTeX picture environment with PostScript \specials
    pstex,          //plain TeX with PostScript \specials
    pstricks,       //LaTeX picture environment with PSTricks macros
    qms,            //QMS/QUIC Laser printer (also Talaris 1200 and others)
    starc,          //Star Color Printer
    svg,            //W3C Scalable Vector Graphics driver
    tandy_60dpi,    //Tandy DMP-130 series 60-dot per inch graphics
    texdraw,        //LaTeX texdraw environment
    tgif,           //TGIF X11 [mode] [x,y] [dashed] ["font" [fontsize]]
    tkcanvas,       //Tk/Tcl canvas widget [perltk] [interactive]
    tpic,           //TPIC -- LaTeX picture environment with tpic \specials
    unknown,        //Unknown terminal type - not a plotting device
    windows         //Microsoft Windows
};
inline std::ostream& operator<<( std::ostream& out, Terminal x );

namespace detail {

struct _Terminal
{
    boost::optional<GP::Terminal> type;
};
inline std::ostream& operator<<( std::ostream& out, _Terminal x );
} // detail

/**
  * \brief display all available terminal types
  */
inline detail::_Terminal set_terminal();

/**
  * \brief set terminal to specified type
  * \note If both set terminal and set output are used together, it is safest to give set terminal first,
  * because some terminals set a flag which is needed in some operating systems.
  *
  * Use set terminal to tell gnuplot what kind of output to generate.
  * If x is push, gnuplot will remember the current terminal including its settings and restore it if it is pop.
  */
inline detail::_Terminal set_terminal( Terminal x );

/**
 * \brief display current terminal
 */
inline std::ostream& show_terminal( std::ostream& out );

} // GP

//------------IMPLEMENTATION--------------------------------
namespace GP {

//----------Terminal----------------------------------------
inline std::ostream& operator<<( std::ostream& out, Terminal x )
{
    switch(x)
    {
        case push:          return out << "push";
        case pop:           return out << "pop";
        case canvas:        return out << "canvas";
        case cgm:           return out << "cgm";
        case corel:         return out << "corel";
        case dpu414:        return out << "dpu414";
        case dumb:          return out << "dumb";
        case dxf:           return out << "dxf";
        case eepic:         return out << "eepic";
        case emf:           return out << "emf";
        case emtex:         return out << "emtex";
        case epslatex:      return out << "epslatex";
        case epson_180dpi:  return out << "epson_180dpi";
        case epson_60dpi:   return out << "epson_60dpi";
        case epson_lx800:   return out << "epson_lx800";
        case fig:           return out << "fig";
        case gif:           return out << "gif";
        case hp2623A:       return out << "hp2623A";
        case hp2648:        return out << "hp2648";
        case hp500c:        return out << "hp500c";
        case hpdj:          return out << "hpdj";
        case hpgl:          return out << "hpgl";
        case hpljii:        return out << "hpljii";
        case hppj:          return out << "hppj";
        case imagen:        return out << "imagen";
        case jpeg:          return out << "jpeg";
        case latex:         return out << "latex";
        case mf:            return out << "mf";
        case mif:           return out << "mif";
        case mp:            return out << "mp";
        case nec_cp6:       return out << "nec_cp6";
        case okidata:       return out << "okidata";
        case pbm:           return out << "pbm";
        case pcl5:          return out << "pcl5";
        case png:           return out << "png";
        case postscript:    return out << "postscript";
        case pslatex:       return out << "pslatex";
        case pstex:         return out << "pstex";
        case pstricks:      return out << "pstricks";
        case qms:           return out << "qms";
        case starc:         return out << "starc";
        case svg:           return out << "svg";
        case tandy_60dpi:   return out << "tandy_60dpi";
        case texdraw:       return out << "texdraw";
        case tgif:          return out << "tgif";
        case tkcanvas:      return out << "tkcanvas";
        case tpic:          return out << "tpic";
        case unknown:       return out << "unknown";
        case windows:       return out << "windows";
        default:    throw std::runtime_error("invalid Terminal enum");
    }
}

//----------set terminal------------------------------------
namespace detail {
    inline std::ostream& operator<<( std::ostream& out, _Terminal x )
    {
        out << "set terminal";
        if( x.type )
            out << " " << *x.type;
        return out << "\n";
    }
} // detail

inline detail::_Terminal set_terminal()
{
    return detail::_Terminal();
}

inline detail::_Terminal set_terminal( Terminal x )
{
    detail::_Terminal t;
    t.type.reset( x );
    return t;
}

//----------show terminal-----------------------------------
inline std::ostream& show_terminal( std::ostream& out )
{
    return out << "show terminal\n";
}

} // GP

#endif // GP_TERMINAL_HPP_
