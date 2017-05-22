project(alwb CXX)

cmake_minimum_required(VERSION 3.1)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    message(STATUS "${COMPILER_SUPPORTS_CXX11}")
else(COMPILER_SUPPORTS_CXX11)
    message(FATAL_ERROR "${COMPILER_SUPPORTS_CXX11}")
endif(COMPILER_SUPPORTS_CXX11)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(WEBKIT2GTK REQUIRED webkit2gtk-4.0) 

link_directories(${GTKMM_LIBRARY_DIRS} ${WEBKIT2GTK_LIBRARY_DIRS} src)
include_directories(${GTKMM_INCLUDE_DIRS} ${WEBKIT2GTK_INCLUDE_DIRS} src)

file(GLOB SOURCES "src/*.cc")

add_library(alwbLib ${SOURCES})
#add_library(tab src/tab.cc)
#add_library(tabmanager src/tabmanager.cc)

#target_include_directories(tab PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(tabmanager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(alwb ${SOURCES})

target_link_libraries(alwb 
    ${GTKMM_LIBRARIES}
    ${WEBKIT2GTK_LIBRARIES}
    alwbLib)
