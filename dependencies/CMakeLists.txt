# fetch dependencies
include(FetchContent)

# do not build tests or examples for subprojects
set(BUILD_TESTING OFF)
set(BUILD_EXAMPLES OFF)

set(STDEXEC_BUILD_TESTS OFF CACHE BOOL "Build stdexec tests" FORCE)
set(STDEXEC_BUILD_EXAMPLES OFF CACHE BOOL "Build stdexec examples" FORCE)

Include(FetchContent)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        11.0.2 # July 20, 2024
)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.0 # August, 2024
)

FetchContent_Declare(
  stdexec
  GIT_REPOSITORY https://github.com/NVIDIA/stdexec
  GIT_TAG        51af7f56b85c09bf827f14b41358cfc28aa0392a # September 2024
)

FetchContent_MakeAvailable(Catch2 fmt stdexec)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
