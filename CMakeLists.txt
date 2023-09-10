cmake_minimum_required(VERSION 3.14)

project("cpp-registry-playground")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(cpk-cmake/cpk.cmake)
find_package(WinReg 6.1.0 EXACT REQUIRED)

if(WinReg_FOUND)
    message(STATUS "WinReg_FOUND: YES")
else()
    message(STATUS "WinReg_FOUND: NO")
endif()


SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)
target_link_libraries(${PROJECT_NAME} WinReg::WinReg)

# cpk_add(${PROJECT_NAME} WinReg 6.1.0 WinReg::WinReg)
