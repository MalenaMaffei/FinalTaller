cmake_minimum_required(VERSION 3.6)
project(TPFinal)

set(CMAKE_CXX_STANDARD 11)

#cada uno tiene que agregar su file(GLOB MIPARTE_SRC wildcardsDeLosArchivos) y
#add_executable() con sus sources y el nombre del exe y tambien agregar las
#librerias que usen.
#Para usarlo propongo la carpeta build asi no quedan los execs por ahi.
#cd build; cmake ..; make
#y ahi quedan los execs de cada uno dentro de build.
#tuve que hardcodear sdl2 porque no pude hacerlo de la manera correcta.

file(GLOB VISTA_SRC
        "client/VistasSDL/*.h"
        "client/VistasSDL/*.cpp"
        )


set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY /usr/lib64/libSDL2.so)

set(SDL2_IMG_LIBRARY /usr/lib64/libSDL2_image.so)


set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

add_definitions(${GTK3_CFLAGS_OTHER})


include_directories(${SDL2_INCLUDE_DIR} ${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})


add_executable(vista  ${VISTA_SRC})
target_link_libraries(vista ${SDL2_LIBRARY} ${SDL2_IMG_LIBRARY} Threads::Threads ${GTK3_LIBRARIES})
