cmake_minimum_required(VERSION 4.0)

set(projectName 808s)
project(${projectName})
set(CMAKE_CXX_STANDARD 17)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
  src/808s.cpp
  src/GUI.cpp
  src/PieceTable.cpp
  src/FileHandler.cpp
  src/test.cpp
)

add_executable(808s ${SOURCES})

target_compile_options(808s PRIVATE -w)

target_include_directories(${projectName} PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

target_link_libraries(808s PRIVATE Qt6::Widgets)
