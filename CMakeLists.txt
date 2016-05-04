cmake_minimum_required(VERSION 3.5)
project(cpp_tesla)

# VERSIONING
set(cpp_tesla_VERSION_MAJOR 0)
set(cpp_tesla_VERSION_MINOR 1)
set(cpp_tesla_VERSION_STRING ${cpp_tesla_VERSION_MAJOR}.${cpp_tesla_VERSION_MINOR})

# BUILD VARIABLES
set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Statically specifies what build type (configuration) will be built in this build tree. Possible values are empty, Debug, Release, RelWithDebInfo and MinSizeRel..")
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Whether to build shared or static libraries.")

# BOOST BUILD VARIABLES
set(Boost_DEBUG OFF CACHE BOOL "Show boost debugging information.")
set(Boost_USE_STATIC_LIBS ON CACHE BOOL "Whether to use shared or static boost libraries when building.")
set(Boost_USE_STATIC_RUNTIME OFF CACHE BOOL "If enabled, searches for boost libraries linked against a static C++ standard library ('s' ABI tag). Defaults to OFF.")
set(Boost_USE_MULTITHREADED ON CACHE BOOL "Whether to link to multi-threaded boost libraries when building.")

# PLATFORM-SPECIFIC FLAGS
if(UNIX)
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -stdlib=libc++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(WIN32)
    add_definitions(-D_WIN32_WINNT=0x0501)
endif()

# LIBRARIES
find_package(Boost 1.58.0 REQUIRED system timer chrono)

# LIBRARY CHECKS
if (NOT Boost_FOUND)
    if(BUILD_SHARED_LIBS)
        message(FATAL_ERROR "Check to make sure you have built shared boost libraries.")
    else()
        message(FATAL_ERROR "Check to make sure you have built static boost libraries.")
    endif(BUILD_SHARED_LIBS)
endif(NOT Boost_FOUND)

# LIBRARY FLAGS
if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_VERBOSE_MAKEFILE true)
    add_definitions(-DBOOST_NETWORK_DEBUG)
endif(CMAKE_BUILD_TYPE MATCHES Debug)

# LIBRARY INCLUDES SO WE CAN INCLUDE THEM IN PROJECT.
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})

# ENABLE TESTING WITH CMAKE'S CTEST
enable_testing()
#INCLUDE(CTest)

# ADD OUR ROOT DIRECTORY FOR INCLUDE SEARCHES
include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR})

# ADD OUR EXECUTABLE'S DIRECTORY
add_subdirectory(src/)
add_subdirectory(test/)