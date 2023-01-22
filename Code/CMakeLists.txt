cmake_minimum_required(VERSION 3.15)
project(Code)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD
add_executable(Code main.cpp Airport.h Airport.cpp Airline.cpp Airline.h Flight.cpp Flight.h Flight.cpp Graph.cpp Graph.h MenuController.cpp MenuController.h Helper.cpp Menu/Menu.cpp Menu/Menu.h Helpers/StringHelpers.cpp Helpers/StringHelpers.h Menu/Info/MenuInfo.cpp Menu/Info/MenuInfo.h Menu/Nav/Navigation.cpp Menu/Nav/Navigation.h)
=======
add_executable(Code main.cpp Airport.h Airport.cpp Airline.cpp Airline.h Flight.cpp Flight.h Flight.cpp Graph.cpp Graph.h MenuController.cpp MenuController.h)
>>>>>>> carlito

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)