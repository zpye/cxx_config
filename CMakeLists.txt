cmake_minimum_required(VERSION 3.5)

project(cxx_config)

add_subdirectory(config)

add_executable(test_config test_config.cpp)
target_link_libraries(test_config PUBLIC config)