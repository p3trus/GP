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
#ifndef GP_COMPATIBILITY_HPP_
#define GP_COMPATIBILITY_HPP_

/**
 * \def GP_VERSION
 * Describes the version number. The XXYYZZ format is used, that means 
 * the major version is (GP_VERSION / 100000), the minor version is
 * ((GP_VERSION / 100) % 1000), and the sub minor version is 
 * (GP_VERSION % 100).
 */
#define GP_VERSION 001000

#ifndef GP_GNUPLOT_VERSION
    #define GP_GNUPLOT_VERSION 4600 // Gnuplot version * 1000
#endif

#endif // GP_COMPATIBILITY_HPP_
