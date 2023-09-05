# Set minimum CMAKE
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)
project(git_basics)

# require C++14
set( CMAKE_CXX_STANDARD 14 )
set( CMAKE_CXX_EXTENSIONS OFF )
set( CMAKE_CXX_STANDARD_REQUIRED ON )


set( APP_EXECUTABLE StringLengthTest )

set( LIB_NAME classLibrary )

# Add the String Functions
add_library( ${LIB_NAME} STATIC
             inc/StringFunctions.h src/StringFunctions.cpp )
target_include_directories( ${LIB_NAME} PUBLIC inc )


ADD_EXECUTABLE( ${APP_EXECUTABLE} src/StringFunctionsTest.cpp )
TARGET_LINK_LIBRARIES( ${APP_EXECUTABLE} ${LIB_NAME} )

set_property( DIRECTORY PROPERTY VS_STARTUP_PROJECT ${APP_EXECUTABLE} )

include (CTest)

add_test(${APP_EXECUTABLE} ${APP_EXECUTABLE})

find_program(VALGRIND "valgrind")
if(VALGRIND)
	add_custom_target(valgrind
		COMMAND "${VALGRIND}" --tool=memcheck --leak-check=yes --show-reachable=yes --error-exitcode=1 $<TARGET_FILE:${APP_EXECUTABLE}>)
endif()
