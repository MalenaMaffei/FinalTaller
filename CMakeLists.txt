cmake_minimum_required(VERSION 3.6)
project(TPFinal)

set(CMAKE_CXX_STANDARD 11)
file(GLOB SOURCES
        *.h
        *.cpp
        )
#set(SOURCE_FILES
#        )

add_executable(TPFinal  ${SOURCES})
