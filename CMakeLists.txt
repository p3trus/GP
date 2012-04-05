#version check
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project( GP )
INCLUDE_DIRECTORIES( include )

FIND_PACKAGE( Boost COMPONENTS filesystem iostreams REQUIRED )

add_executable( example example/example.cpp )
target_link_libraries( example boost_filesystem boost_iostreams )

add_definitions(-DGP_GNUPLOT_VERSION=4200) #use gnuplot version 4.2 compatibility mode
