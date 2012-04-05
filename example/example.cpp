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
#include <iostream>
#include <vector>
#include <cmath>
#include <GP.hpp>


using namespace GP;

/**
 * pipe command strings directly to gnuplot
 */
void example1()
{
    Gnuplot plt;
    plt << "plot sin(x) title \"example 1\" with points" << std::endl; 
}

/**
 * equivalent to example1 but avoids several spelling errors.
 */
void example2()
{
    Gnuplot plt;
    plt << plotFunction("sin(x)").title("example 2").style(points) << std::endl; 
}

void example3()
{
    Gnuplot plt;
    plt << plot("../example/sine.bin").binary().title("example 3").format("%double").array(201) << std::endl; 
}

void example4()
{
    //generate data
    std::vector<double> data;
    for( unsigned i(0); i < 100; ++i)
        data.push_back( sin( double(i)/20. ) );

    Gnuplot plt;
    plt << plot( data.begin(), data.end() ).title("example 4") << std::endl;
}

int main()
{
    example1();    
    example2();
    example3();
    example4();

    return 0;
}
