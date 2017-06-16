# FinalTaller

##### SDL #####
Para correr el TP es necesario tener SDL2 instalado. 
```
yum install SDL2-devel
apt-get install libsdl2-dev
```
También SDL_Image
```
yum install SDL2_image-devel
apt-get install libsdl2-image-dev
```
Y por último SDL_ttf y SDL_Mixer
```
yum install SDL2_image-devel
yum install SDL2_mixer-devel

```

##### Make #####
Una vez instaladas las librerias
```
cd build
cmake ..
make
```

##### Ejecución #####
Esto generara el ejecutable **vista** dentro de la misma carpeta build y el ejecutable **server** dentro de la carpeta server.

Por ahora para correr el TP se debe correr primero al servidor y luego dos clientes ejecutando consecutivamente:
```
cd build
./vista 127.0.0.1 8080
```
