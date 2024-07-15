cmake_minimum_required(VERSION 3.28)

project(Zaephus_Math
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 26)
set(MATH_LIB_NAME "Zaephus_Math")

add_library(${MATH_LIB_NAME} STATIC
    include/Matrices/Matrix4x4.cpp
    include/Matrices/Matrix4x4.h
    include/Math.h
    include/Quaternion.cpp
    include/Matrices/Matrix3x3.cpp
    include/Matrices/Matrix2x2.cpp
    include/Vectors/Vector2.cpp
    include/Vectors/Vector3.cpp
    include/Vectors/Vector4.cpp
    include/Vectors/Vector2Int.cpp
    include/Vectors/Vector2Int.h
    include/Vectors/Vector3Int.cpp
    include/Vectors/Vector3Int.h
    include/Vectors/Vector4Int.cpp
    include/Vectors/Vector4Int.h
)

target_include_directories(${MATH_LIB_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)

target_compile_features(${MATH_LIB_NAME}
    INTERFACE
        cxx_std_20
)

install(
    TARGETS ${MATH_LIB_NAME}
    EXPORT ${MATH_LIB_NAME}_Targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/ZaephusMath
    DESTINATION include
)

install(
    EXPORT ${MATH_LIB_NAME}_Targets
    FILE ZaephusMathTargets.cmake
    DESTINATION  ${CMAKE_INSTALL_LIBDIR}/cmake/ZaephusMath
    NAMESPACE ZMath::
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "ZaephusMathConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES
    ${PROJECT_BINARY_DIR}/utilsConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ZaephusMathConfigVersion.cmake
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/utils
)