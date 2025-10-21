cmake_minimum_required(VERSION 4.0)

set(projectName 808s)
project(${projectName})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


set(SOURCES
  src/808s.cpp
  src/PieceTable.cpp
  src/FileHandler.cpp
  src/test.cpp
  src/MainWindow.cpp
  src/EditorWindow.cpp
)

set(HEADERS
  include/MainWindow.hpp
  include/EditorWindow.hpp
)

add_executable(808s ${SOURCES} ${HEADERS})

target_compile_options(808s PRIVATE -w)

target_include_directories(${projectName} PRIVATE ${CMAKE_SOURCE_DIR}/include)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

target_link_libraries(808s PRIVATE Qt6::Widgets)
