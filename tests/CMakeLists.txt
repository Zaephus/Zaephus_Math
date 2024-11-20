
#project(${MATH_LIB_NAME}_TESTS)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(Test
    main.cpp
    Vectors/Vec3Test.h
    Time.h
    TestHelper.h
    QuaternionTest.h
)

target_link_libraries(Test PRIVATE ${MATH_LIB_NAME})

add_test(NAME MathTest COMMAND Test)