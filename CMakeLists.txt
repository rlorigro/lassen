cmake_minimum_required(VERSION 3.0)
project(lassen)

# Compiler options.
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++14")
add_definitions(-ggdb3)

# Definitions needed to eliminate runtime dependency
# on the boost system library.
add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)
add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)

# Include header files
include_directories("inc")

# Define our shared library.
set(SOURCES
        src/split.cpp
        src/FastqReader.cpp
        src/FastaReader.cpp
        src/callConsensusCpp.cpp
#        src/parse_fasta_windows.cpp
#        src/parse_grouped_amplicons.cpp
        )

add_library(lassen SHARED ${SOURCES})

# To make sure the library is named shasta.so,
# get rid of the "lib" prefix.
set_target_properties(lassen PROPERTIES PREFIX "")

# Eliminate an extraneous -D during compilation.
set_target_properties(lassen PROPERTIES DEFINE_SYMBOL "")


# ----------- Linking to polisher ----------------------------

# Need to explicitly enable ExternalProject functionality
include(ExternalProject)

# Download or update marginpolish as an external project
ExternalProject_Add(project_marginPolish
        GIT_REPOSITORY https://github.com/benedictpaten/marginPhase.git
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/external
        GIT_TAG polisher_shasta
        BUILD_COMMAND make MarginCore
        INSTALL_COMMAND ""
)

# Define INSTALL_DIR as the install directory for marginpolish
ExternalProject_Get_Property(project_marginPolish INSTALL_DIR)

# Create new library for external project (so it can be linked with lassen)
add_library(marginPolish STATIC IMPORTED)
set_property(TARGET marginPolish
        PROPERTY IMPORTED_LOCATION ${INSTALL_DIR}/src/project_marginPolish-build/libMarginCore.so)

# Define library as dependent on the downloaded project
add_dependencies(marginPolish project_marginPolish)

# Ensure that lassen has access to primary dependencies' and secondary dependencies' headers
include_directories(lassen
        ${INSTALL_DIR}/src/project_marginPolish/inc
        ${INSTALL_DIR}/src/project_marginPolish/externalTools/cPecan/inc
        ${INSTALL_DIR}/src/project_marginPolish/externalTools/sonLib/C/inc)

# Add runtime path for lassen so it can access external library
set_property(TARGET lassen PROPERTY INSTALL_RPATH "$ORIGIN" "${INSTALL_DIR}/src/project_marginPolish-build/")

#-------------------------------------------------------------

#include_directories(${INSTALL_DIR}/src/project_marginPolish-build/)

add_executable(test_consensus src/test/test_consensus.cpp)
set_property(TARGET test_consensus PROPERTY INSTALL_RPATH "$ORIGIN" "${INSTALL_DIR}/src/project_marginPolish-build/")
target_link_libraries(test_consensus lassen marginPolish)

add_executable(test_FastqReader src/test/test_FastqReader.cpp)
set_property(TARGET test_FastqReader PROPERTY INSTALL_RPATH "$ORIGIN" "${INSTALL_DIR}/src/project_marginPolish-build/")
target_link_libraries(test_FastqReader lassen marginPolish)

add_executable(test_split src/test/test_split.cpp)
set_property(TARGET test_split PROPERTY INSTALL_RPATH "$ORIGIN" "${INSTALL_DIR}/src/project_marginPolish-build/")
target_link_libraries(test_split lassen marginPolish)

#add_executable(parse_grouped_amplicons src/parse_grouped_amplicons.cpp)
#set_property(TARGET parse_grouped_amplicons PROPERTY INSTALL_RPATH "$ORIGIN" "${INSTALL_DIR}/src/project_marginPolish-build/")
#target_link_libraries(parse_grouped_amplicons lassen marginPolish)

add_executable(parse_fasta_windows src/parse_fasta_windows.cpp)
set_property(TARGET parse_fasta_windows PROPERTY INSTALL_RPATH "$ORIGIN" "${INSTALL_DIR}/src/project_marginPolish-build/")
target_link_libraries(parse_fasta_windows lassen marginPolish)

add_executable(stupidTest src/stupid_test.cpp)
target_link_libraries(stupidTest lassen MarginCore)


# Where to install
set(BINARY_INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin)

## The shared library goes to the bin directory.
install(TARGETS
        lassen
        test_consensus
        test_FastqReader
        test_split
#        parse_grouped_amplicons
        parse_fasta_windows
        DESTINATION ${BINARY_INSTALL_DIR})

message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
