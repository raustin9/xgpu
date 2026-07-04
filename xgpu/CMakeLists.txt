cmake_minimum_required(VERSION 3.24)

# Assume metal is available if compiling on Apple
if (APPLE)
    set (METAL_SOURCES "")
endif ()

# Attempt to find vulkan
find_package(Vulkan REQUIRED)
if (Vulkan_FOUND)
    message("Found vulkan.")
    set (VULKAN_SOURCES "src/test.cpp")
endif ()

# Find the RTL dependency
FetchContent_Declare(
        rtl
        GIT_REPOSITORY https://github.com/raustin9/rtl.git
        GIT_TAG main
)
FetchContent_MakeAvailable(rtl)

add_library(xgpu ${METAL_SOURCES} ${VULKAN_SOURCES})
target_include_directories(xgpu
        PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/include"
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}"
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
)
target_link_libraries(xgpu PUBLIC rtl)

target_compile_definitions(xgpu PUBLIC "$<$<CONFIG:Debug>:XGPU_DEBUG>")

set_target_properties(xgpu PROPERTIES
        EXPORT_NAME XGPU::xgpu
        ALIAS_NAME XGPU::XGPU
)
add_library(XGPU::xgpu ALIAS xgpu)
set(XGPU_FOUND TRUE PARENT_SCOPE)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(CLANG_TIDY_EXE)
    message(STATUS "Clang-Tidy found: ${CLANG_TIDY_EXE}")
    
    # 3. Apply globally to all C++ targets
    # It is best practice to omit the "-checks" flag here and manage them via a .clang-tidy file.
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
else()
    message(WARNING "Clang-Tidy not found! Static analysis will be skipped.")
endif()