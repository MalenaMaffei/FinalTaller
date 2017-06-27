# Trabajo Final de Taller 75.42
Integrantes:
* Cano, Matías
* Maffei, Malena

La documentación del trabajo se encuentra en la carpeta /doc, aquí abajo dejamos instrucciones para poder instalar el juego. Más información sobre la instalacion se puede encontrar en /doc/ManualDelUsuario.md

## Instalación
El trabajo funcionará solamente en computadoras con algún sabor de Linux como sistema operativo.
El trabajo fue probado en Ubuntu, Fedora y TrisquelMini, pero no descartamos que funcione en otros sistemas también. A continuación se detallará la instalación teniendo los sitemas mencionados anteriormente en mente.

__Software necesario__
* CMake versión 3.6 en adelante.
* Git para compilar la versión más reciente del repositorio.


__Hardware Necesario__
* Teclado, Mouse, pantalla que soporte una resolución de al menos 800*600
* Conexión a una red local.

* Instalar las librerías necesarias:
```
yum install SDL2-devel
yum install SDL2_image-devel
yum install SDL2_ttf-devel
yum install SDL2_mixer-devel
yum install tinyxml2-devel
```
O, Alternativamente:
```
apt-get install libsdl2-dev
apt-get install libsdl2-image-dev
apt-get install libsdl2-ttf-dev
apt-get install libsdl2-mixer-dev
apt-get install libtinyxml2-dev
```

* Si se quiere la versión más reciente:

```
git clone https://github.com/MalenaMaffei/FinalTaller.git ZGame
```

* Compilación
```
cd ZGame/build
cmake ..
make
```

* El ejecutable del servidor ```server``` aparecerá en la carpeta ZGame/server y el del cliente ```client``` en ZGame/client.
