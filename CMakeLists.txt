cmake_minimum_required(VERSION 3.22)

set(SML_SLN  "000-linux-cmake-projects")
project(${SML_SLN})

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)

add_subdirectory(001-call-conv)
add_subdirectory(001-call-conv-so)