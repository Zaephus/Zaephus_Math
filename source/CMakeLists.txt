
add_library(${MATH_LIB_NAME} STATIC
    Matrices/Matrix4x4.cpp
    Matrices/Matrix3x3.cpp
    Matrices/Matrix2x2.cpp

    Vectors/Vector2.cpp
    Vectors/Vector3.cpp
    Vectors/Vector4.cpp
    Vectors/Vector2Int.cpp
    Vectors/Vector3Int.cpp
    Vectors/Vector4Int.cpp

    Quaternion.cpp
    ZMath.h
)