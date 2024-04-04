
cmake_minimum_required(VERSION 3.28)
project(Zaephus_Math LANGUAGES CXX VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME} Math.h)

target_include_directories(${PROJECT_NAME} PUBLIC Matrices/ Misc/ Vectors/)
# A CMake pattern to have headers that are not seen by the client of this library.
# So headers which not have to be visible for client-code should be placed in src/
#target_include_directories(${PROJECT_NAME} PRIVATE src/)

if (MSVC)
    # PRIVATE specifies that the specified compile options are only for the ${PROJECT_NAME} itself,
    # and not for any targets that link to it.
    # warning level 4 and all warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /EHsc /std:c++20)
else ()
    # PRIVATE specifies that the specified compile options are only for the ${PROJECT_NAME} itself,
    # and not for any targets that link to it.
    # lots of warnings and all warnings as errors
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
endif ()