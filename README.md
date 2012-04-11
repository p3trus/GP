GP
==

What is it
----------

GP is a header only C++ library, created for easy and save communication with
gnuplot from within C++ code.

Version
-------

This directory contains the 0.1 release of GP. The latest version can be found 
on the GP project page under https://github.com/p3trus/GP.

Documentation
-------------

GP uses doxygen compatible in code documentation. A cmake target is available, to build the documentation.
To generate the documentation, follow the steps below. 

Inside the GP root directory, do
  * `mkdir bin`
  * `cd bin`
  * `cmake ..`
  * `make doc`
This creates a `doc/` directory inside the GP root directory.

Licensing
---------

You should have received a copy of the [GNU General Public License][] along with
GP; see the file COPYING.
  [GNU General Public License]: http://www.gnu.org/licenses/gpl.html
