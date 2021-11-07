include(FetchContent)

cmake_minimum_required(VERSION 3.21)
project(cpp-basic-template VERSION 0.1.0)

include(CTest)
enable_testing()


set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
    )
    FetchContent_MakeAvailable(SFML)
    
add_executable(
 SfmlWithCMake
 main.cpp
 classes/GameState.cpp
)
target_link_libraries(
 SfmlWithCMake
 sfml-graphics
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
