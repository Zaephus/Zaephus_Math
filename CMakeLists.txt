
cmake_minimum_required(VERSION 3.28)
#project(Zaephus_Math VERSION 0.1.0)

#set(CMAKE_CXX_STANDARD 26)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME}
        Math.h

        Matrices/Matrix2x2.h
        Matrices/Matrix3x3.h
        Matrices/Matrix4x4.h

        Misc/MathHelper.h
        Misc/Quaternion.h

        Vectors/Vector2.h
        Vectors/Vector2Int.h
        Vectors/Vector3.h
        Vectors/Vector3Int.h
        Vectors/Vector4.h
        Vectors/Vector4Int.h
)