cmake_minimum_required(VERSION 3.10)

project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES 
    src/Universe.cpp
    src/GameOfLife.cpp
    src/main.cpp
)

add_library(GameOfLifeLibrary STATIC ${SOURCE_FILES})
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.7/build/native/include)
link_directories(${CMAKE_SOURCE_DIR}/packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.7/lib/native/v140/windesktop/msvcstl/static/rt-dyn/x64/Release)

enable_testing()
set(TEST_FILES 
    tests/Tests.cpp
)

add_executable(runTests ${TEST_FILES})
add_executable(GameOfLife src/main.cpp)

target_link_libraries(GameOfLife GameOfLifeLibrary)
target_link_libraries(runTests gtest gtest_main GameOfLifeLibrary)

add_test(NAME GameOfLifeTests COMMAND runTests)
