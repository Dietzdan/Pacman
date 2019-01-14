project(ConanTest)
cmake_minimum_required(VERSION 3.0)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(conanTest main.cpp PInput.cpp _Update.cpp Render.cpp Sprite.cpp PInput.h Render.h Sprite.h _Update.h GameState.h GameState.cpp)
target_link_libraries(conanTest ${CONAN_LIBS})

set (CMAKE_CXX_STANDARD 11)
set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT "conanTest")

FILE(COPY assets/ DESTINATION assets)
FILE(COPY assets/ DESTINATION bin/assets)
