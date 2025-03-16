cmake_minimum_required(VERSION 3.10.0)
project(bank)

#设置C++版本
set(CMAKE_CXX_STANDARD 17)
#指定头文件路径
include_directories(inc)

#查找src目录下所有.cpp文件
file(GLOB SOURCES "src/*.cpp" "main.cpp")



add_executable(Bank ${SOURCES})