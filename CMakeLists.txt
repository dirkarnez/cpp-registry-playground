cmake_minimum_required(VERSION 3.14)

project(cpp-registry-playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cpk-cmake/cpk.cmake)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

cpk_add(${PROJECT_NAME} WinReg 6.1.0 WinReg::WinReg)