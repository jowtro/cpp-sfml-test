include(FetchContent)

cmake_minimum_required(VERSION 3.21)
project(myProgram VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
    )
    FetchContent_MakeAvailable(SFML)
    
add_executable(
    myProgram
 classes/Field.cc
 classes/Grid.cc
 main.cc
)

target_link_libraries(
    myProgram
 sfml-graphics
)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
set(EXECUTABLE_OUTPUT_PATH "../bin")
