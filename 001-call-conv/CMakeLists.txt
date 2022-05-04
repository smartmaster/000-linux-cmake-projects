cmake_minimum_required(VERSION 3.22)

set(SML_PROJECT "001-call-conv")
project(${SML_PROJECT} LANGUAGES C CXX ASM Fortran)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}/install)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -no-pie -fvisibility=hidden")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -no-pie -fvisibility=hidden")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=hidden")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -x assembler-with-cpp -fvisibility=hidden")


file(GLOB SML_SRC
${CMAKE_CURRENT_LIST_DIR}/src/*.h

${CMAKE_CURRENT_LIST_DIR}/src/*.c
${CMAKE_CURRENT_LIST_DIR}/src/*.cpp

${CMAKE_CURRENT_LIST_DIR}/src/*.asm
${CMAKE_CURRENT_LIST_DIR}/src/*.S

${CMAKE_CURRENT_LIST_DIR}/src/*.f
${CMAKE_CURRENT_LIST_DIR}/src/*.f90

)

add_executable(${SML_PROJECT} ${SML_SRC})

install(TARGETS ${SML_PROJECT})




