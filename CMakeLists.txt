cmake_minimum_required(VERSION 3.20)
project(test)

aux_source_directory(./src SRC)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_HOME_DIRECTORY}/bin")

#dubug 模式------------------这个非常重要，否则无法进入断点
#set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")


add_executable(${PROJECT_NAME} ${SRC})