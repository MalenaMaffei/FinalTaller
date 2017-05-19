cmake_minimum_required(VERSION 3.6)
project(TPFinal)

set(CMAKE_CXX_STANDARD 11)
file(GLOB SOURCES
        "VistasSDL/*.h"
        "VistasSDL/*.cpp"
        )
#set(SOURCE_FILES
#        )
set (CMAKE_SHARED_LINKER_FLAGS "-Wl,-lSDL2 -lSDL2_image")

add_executable(TPFinal  ${SOURCES})
