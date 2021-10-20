cmake_minimum_required(VERSION 3.20)
project(PongLion)

set(CMAKE_CXX_STANDARD 20)

add_executable(PongLion main.cpp Game.cpp Game.hpp Paddle.cpp Paddle.hpp Ball.cpp Ball.hpp)

include(cmake_modules/CompilerWarnings.cmake)
include(cmake_modules/Sanitizers.cmake)
include(cmake_modules/StaticAnalyzers.cmake)


enable_sanitizers(PongLion)
set_project_warnings(PongLion)

include_directories(headers F:/Libraries/C++/spdlog/spdlog/include)
#include_directories(headers F:/Libraries/C++/SFML/include)

set(SFML_ROOT F:/Libraries/C++/SFML/)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics REQUIRED)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(PongLion ${SFML_LIBRARIES})
endif()

file(GLOB BINARY_DEP_DLLS "F:/Libraries/C++/SFML/bin/*.dll")
file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})