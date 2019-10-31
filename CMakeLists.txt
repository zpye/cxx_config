cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

project(cxx_config)

add_subdirectory(config)

add_executable(test_config test_config.cpp)
target_link_libraries(test_config PUBLIC config)
