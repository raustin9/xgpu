include(FetchContent)
cmake_minimum_required(VERSION 3.24)

project (XGPU VERSION 0.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(xgpu)

# Determine if this is a subproject or not. Useful for not building
# examples/tests when used as a dependency
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(XGPU_SUBPROJECT ON)
endif ()

if (NOT XGPU_SUBPROJECT)
    add_subdirectory(tests)
endif ()