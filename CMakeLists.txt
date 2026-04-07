cmake_minimum_required(VERSION 3.10)

project(my_app)

find_package(TBB REQUIRED)
find_package(IPP REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_app
    src/main.cpp
    src/file_reader_node.cpp
    src/file_writer_node.cpp
)

target_include_directories(my_app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(my_app PRIVATE TBB::tbb IPP::ipps)

add_custom_command(TARGET my_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/tone.raw
        $<TARGET_FILE_DIR:my_app>/tone.raw
)
