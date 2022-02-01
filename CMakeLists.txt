cmake_minimum_required(VERSION 3.14)

project(cpp-registry-playground)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(winreg STATIC IMPORTED)

set_property(
  TARGET winreg APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG
)

set_target_properties(winreg PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${WINREG_ROOT}/build/Release/clip.lib"
)

set_property(
  TARGET winreg APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(winreg PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${WINREG_ROOT}/WinReg.lib"
)
  
set_target_properties(winreg PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_include_directories(winreg INTERFACE "${WINREG_ROOT}")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

target_link_libraries(${PROJECT_NAME} winreg)