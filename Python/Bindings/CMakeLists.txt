# CMakeLists.txt file for tettigoniidae/Python/Bindings
# Author: A. Ziegler
# Created on: Jun 14, 2022

message( "Building Python bindings")

include_directories( BEFORE 
    ${CMAKE_CURRENT_SOURCE_DIR}/Data
)

# Python binding headers
set( PYBINDING_HEADERFILES
    Data/IntDataPybind.hh
    Data/DoubleDataPybind.hh
)

# Python bindings
set( PYBINDING_SOURCEFILES
    tettigoniidaePybind.cc
)

set( PROJECT_LIBRARIES TTGDData )

pbuilder_add_pybind11_module( _tettigoniidae ${PROJECT_LIBRARIES} )

pbuilder_install_headers( ${PYBINDING_HEADERFILES} )

message( "Done with Python bindings" )