cmake_minimum_required(VERSION 3.6)
project(TPFinal)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${TPFinal_SOURCE_DIR}/cmakeFind")

#cada uno tiene que agregar su file(GLOB MIPARTE_SRC wildcardsDeLosArchivos) y
#add_executable() con sus sources y el nombre del exe y tambien agregar las
#librerias que usen.
#Para usarlo propongo la carpeta build asi no quedan los execs por ahi.
#cd build; cmake ..; make
#y ahi quedan los execs de cada uno dentro de build.
#tuve que hardcodear sdl2 porque no pude hacerlo de la manera correcta.

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(TinyXML2 REQUIRED)

#set(SDL2_INCLUDE_DIR /usr/include/SDL2)
#set(SDL2_LIBRARY /usr/lib64/libSDL2.so)
#set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so)

#set(SDL2_IMG_LIBRARY /usr/lib64/libSDL2_image.so)
#set(SDL2_IMG_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2_image.so)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(PkgConfig REQUIRED)

include(CheckCXXCompilerFlag)

function(enable_cxx_compiler_flag_if_supported flag)
    string(FIND "${CMAKE_CXX_FLAGS}" "${flag}" flag_already_set)
    if(flag_already_set EQUAL -1)
        check_cxx_compiler_flag("${flag}" flag_supported)
        if(flag_supported)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
        endif()
    endif()
endfunction()

enable_cxx_compiler_flag_if_supported("-Wall")
#enable_cxx_compiler_flag_if_supported("-Werror")

enable_cxx_compiler_flag_if_supported("-pedantic")
#enable_cxx_compiler_flag_if_supported("-pedantic-errors")

include_directories(${SDL2_INCLUDE_DIR} ${TINYXL2_INCLUDE_DIR} )
link_directories(${TINYXML2_LIBRARIES})

file(GLOB VISTA_SRC
        "client/Header Files/*.h"
        "client/*.cpp"
	"client/Vistas/*.cpp"
	"client/Elementos/*.cpp"
	"client/Elementos/Elementos Gui/*.cpp"
        )
add_executable(client ${VISTA_SRC})
set_target_properties(client PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../client/)
target_link_libraries(client ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES}  
					${SDL_TTF_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES} Threads::Threads)

file(GLOB SERVER_SRC
		"server/*.h"
		"server/*.cpp"
		)
add_executable(server ${SERVER_SRC})
set_target_properties(server PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../server/)
target_link_libraries(server ${TINYXML2_LIBRARIES} Threads::Threads)

file(GLOB MAP_SRC
		"generadorMapa/*.cpp"
		"generadorMapa/*.h"
		)
add_executable(generador ${MAP_SRC})
target_link_libraries(generador ${TINYXML2_LIBRARIES})
set_target_properties(generador PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../generadorMapa/)

