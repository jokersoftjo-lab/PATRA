cmake_minimum_required(VERSION 3.20)

project(PATRACompiler
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(patra_compiler STATIC
    src/lexer/lexer.cpp
)

target_include_directories(patra_compiler
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(patra_compiler PRIVATE /W4 /permissive-)
else()
    target_compile_options(patra_compiler PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(patra
    ../tools/patra/main.cpp
)

target_link_libraries(patra
    PRIVATE
        patra_compiler
)