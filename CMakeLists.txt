cmake_minimum_required(VERSION 3.27)
project(TotallyReliableLibrary)

set(C_STANDARD 23)
set(C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
  add_compile_definitions(TRL_WINDOWS)
elseif(UNIX)
  add_compile_definitions(TRL_UNIX)
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Choose A Build Type (Debug | Release)" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
  message("Build Type Was Not Selected! Defaulting To 'Debug'")
endif()

foreach(CONFIG Debug Release Export)
    string(TOUPPER ${CONFIG} CONFIG_UPPER)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_C_COMPILER_ID}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/bin-lib/${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_C_COMPILER_ID}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIG_UPPER}
        "${CMAKE_SOURCE_DIR}/bin-objs/${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}-${CMAKE_C_COMPILER_ID}")
endforeach()
set(CMAKE_BUILD_RPATH)

add_subdirectory(./TotallyReliableLibrary)
add_subdirectory(./Test)
