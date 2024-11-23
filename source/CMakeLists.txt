
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
    DIRECTORY ${PROJECT_SOURCE_DIR}/source/ZaephusMath
    DESTINATION .
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