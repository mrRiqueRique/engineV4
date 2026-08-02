cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(engineV4 LANGUAGES C CXX)
include(FetchContent)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

FetchContent_MakeAvailable(glfw)

add_library(glad STATIC
    ${PROJECT_SOURCE_DIR}/external/glad/src/gl.c
)

target_include_directories(glad PUBLIC
    ${PROJECT_SOURCE_DIR}/external/glad/include
)


add_library(engine STATIC
    src/Core/Core.cpp
)

target_include_directories(engine PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(engine PUBLIC
    OpenGL::GL
    glfw
    glad
)

add_subdirectory(src/IO)
add_subdirectory(src/Core)

add_executable(engineV4 src/main.cpp)

target_link_libraries(engineV4 PRIVATE engine)

if(WIN32)
    add_custom_command(TARGET engineV4 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:glfw>
        $<TARGET_FILE_DIR:engineV4>
    )
endif()