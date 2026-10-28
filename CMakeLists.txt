cmake_minimum_required(VERSION 4.4.5)

project(experiments_cpp VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

add_subdirectory(src/experiments/math)

if(BUILD_TESTS)
    add_subdirectory(test)
endif()
