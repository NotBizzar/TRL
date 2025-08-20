cmake_minimum_required(VERSION 3.27)
project(TRL)

file(GLOB_RECURSE TRL_SOURCES "./Src/*.c")

add_library(${PROJECT_NAME} STATIC ${TRL_SOURCES})

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>: -g -O0 -Wall -Wextra -Wpedantic -Wno-unused-parameter>
        $<$<CONFIG:Release>: -O2 -Wall -Wextra -Wpedantic -Wno-unused-parameter>
    )
elseif(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<CONFIG:Debug>: /Zi /Od /W4>
        $<$<CONFIG:Release>: /O2 /W4>
    )
    set_target_properties(${PROJECT_NAME} PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
    )
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Chonk)
endif()

target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Debug>:TRL_DEBUG>)
target_compile_definitions(${PROJECT_NAME} PUBLIC $<$<CONFIG:Release>:TRL_RELEASE>)


target_include_directories(${PROJECT_NAME} PUBLIC
  ./Src
  ./Include
)