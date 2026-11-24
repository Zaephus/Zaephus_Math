
project("ZMath"
    VERSION 0.1.0
    LANGUAGES CXX
)

add_library("ZMath" STATIC
    Quaternion.cpp
    Quaternion.h

    Constants.h
    Matrices.h
    Operations.h
    Vectors.h
)

add_subdirectory(Vectors)
add_subdirectory(Matrices)