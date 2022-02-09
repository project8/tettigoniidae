# CMakeLists for tettigoniidae/Library/Processors
# Author: N.S. Oblath

include_directories( BEFORE 
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set( TTGD_LIBS 
    TTGDData
)

set( TTGDProcs_HEADERFILES
    Adder.hh
)

set( TTGDProcs_SOURCEFILES
    Adder.cc
)


##################################################

pbuilder_library( 
    TARGET TTGDProcs 
    SOURCES ${TTGDProcs_SOURCEFILES}
    PUBLIC_EXTERNAL_LIBRARIES ${PUBLIC_EXT_LIBS}
    PROJECT_LIBRARIES ${TTGD_LIBS}
)

pbuilder_component_install_and_export( 
    COMPONENT Library
    LIBTARGETS TTGDProcs
)

pbuilder_install_headers( ${TTGDProcs_HEADERFILES} )
