# CMakeLists for tettigoniidae/Library/Data
# Author: N.S. Oblath

include_directories( BEFORE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set( TTGDData_HEADERFILES
    DoubleData.hh
    IntData.hh
)

set( TTGDData_SOURCEFILES
    DoubleData.cc
    IntData.cc
)


##################################################

pbuilder_library( 
    TARGET TTGDData 
    SOURCES ${TTGDData_SOURCEFILES}
    PUBLIC_EXTERNAL_LIBRARIES ${PUBLIC_EXT_LIBS}
)

pbuilder_component_install_and_export( 
    COMPONENT Library
    LIBTARGETS TTGDData
)

pbuilder_install_headers( ${TTGDData_HEADERFILES} )
