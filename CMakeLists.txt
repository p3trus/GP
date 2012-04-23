#version check
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

project( GP )

#FIND_PACKAGE(Boost)
FIND_PACKAGE( Boost COMPONENTS filesystem iostreams REQUIRED )
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR}, include)
add_executable( example example/example.cpp )
target_link_libraries( example boost_filesystem boost_iostreams )

add_subdirectory( dox )