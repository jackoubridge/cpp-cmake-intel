cmake_minimum_required(VERSION 3.10)

project(my_app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_app src/main.cpp)
target_include_directories(my_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)