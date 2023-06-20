cmake_minimum_required(VERSION 3.20)
project(teststr)

aux_source_directory(./src SRC)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/bin")

add_executable(${PROJECT_NAME} ${SRC})
# 寻找GTest和Threads库，两个库必需
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
# 包含GTest的头文件目录
include_directories(${GTEST_INCLUDE_DIRS})
# 生成测试可执行文件encrypt_and_decrypt_test需要链接encrypt_and_decrypt、gtest、pthread库
target_link_libraries(${PROJECT_NAME}  ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )
# Enable CMake's testing runner to discover the test executable file.
# If CMake's version is greater than 3.10, use the "gtest_discover_tests" statement, otherwise use the "add_test" statement.
# 让CMake能够发现encrypt_and_decrypt_test文件，以便使用ctest命令时能够自动运行测试文件。
gtest_discover_tests(${PROJECT_NAME})
# add_test(StringOperationTest ${PROJECT_NAME}_test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
