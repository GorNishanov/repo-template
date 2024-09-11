cmake_minimum_required(VERSION 3.22.1)
project(conqueue CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Integrate with LLVM/clang tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fetch required dependencies
add_subdirectory(dependencies)

# Detect the compiler and set compiler-specific options
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
endif()

# Define the main library
add_library(conqueue STATIC src/conqueue.cpp)

# Declare the public include directories
include(GNUInstallDirs)
target_include_directories(conqueue PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           )

target_link_libraries(conqueue PUBLIC stdexec)

# Use C++20 standard
target_compile_features(conqueue INTERFACE cxx_std_23)

enable_testing()

add_subdirectory(test)
