# Minimum cmake verison 3.12 required for Scarab
cmake_minimum_required (VERSION 3.12)

# Define the project
cmake_policy( SET CMP0048 NEW ) # version in project()
project( tettigoniidae VERSION 0.0.0 )

list( APPEND CMAKE_MODULE_PATH 
    ${PROJECT_SOURCE_DIR}/nymph/Scarab/cmake
    ${PROJECT_SOURCE_DIR}/nymph/cmake 
)
include( PackageBuilder )
include( Nymph )

#########
# flags #
#########

set( CMAKE_CXX_STANDARD 17 )


################
# dependencies #
################

set( PUBLIC_EXT_LIBS )
set( PRIVATE_EXT_LIBS )




#####################
# prepare for build #
#####################

pbuilder_prepare_project()


##############
# submodules #
##############

# Nymph
pbuilder_add_submodule( Nymph nymph )

pbuilder_use_sm_library( Nymph Nymph )

###########
# psyllid #
###########

# add include directories
include_directories( BEFORE
    Library/Processors
    Library/Data
)

# build this project
add_subdirectory( Library )

if( tettigoniidae_ENABLE_EXECUTABLES )
    #add_subdirectory( Executables )
endif()

if( tettigoniidae_ENABLE_TESTING )
    #add_subdirectory( Testing )
endif()


##################
# package config #
##################

#configure_file( ${PROJECT_SOURCE_DIR}/tettigoniidaeConfig.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/tettigoniidaeConfig.cmake @ONLY )

#pbuilder_do_package_config()
