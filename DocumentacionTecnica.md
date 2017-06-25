# Documentación Técnica

## Requerimientos de software
### SDL
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
yum install SDL2_ttf-devel
yum install SDL2_mixer-devel

```

### tinyXML2
También es necesario tener TinyXML2 instalado.

```
apt-get install libtinyxml2-dev
```

### Make
Una vez instaladas las librerias
```
cd build
cmake ..
make
```

### Ejecución
Esto generara el ejecutable **vista** dentro de la misma carpeta client, el ejecutable **server** dentro de la carpeta server y el ejecutable **generador** dentro de la carpeta generadorMapa.

Principalmente se debe generar un mapa mediante:
```
cd generadorMapa
./generador
```
Este generara un archivo ```mapa.map``` y un archivo ```configuracion.xml```. El primero contiene los territorios del mapa, y el segundo las posiciones de los objetos iniciales en el mapa. Ambos deben ser movidos a la carpeta server.

Para correr el tp se debe correr primero el servidor especificando:
```
cd server
./server <puerto> <#jugadores>
```

y luego la cantidad de clientes necesarios, ejecutando consecutivamente:
```
cd client
./vista <ip> <puerto>
```

## Descripción general

Como se mencionó anteriormente el trabajo consta de tres partes principales, un servidor, un cliente y un generador.
El servidor contiene al modelo del Juego y se encarga de la lógica del mismo. El cliente, se comunica constantemente con el servidor y se encarga de reflejar lo que sucede en el modelo de forma visual. Por último, el generador de mapas es el encargado de generar las configuraciones iniciales del juego, que son leidas al inicializarse el juego en el server.

### Server
#### Descripción general
La parte fundamental del servidor es el modelo el cual se encarga de manejar los sucesos y funcionamientos del juego. Pero además, este modelo requiere de "representantes" de los clientes dentro del servidor, los cuales se encargan de realizar las comunicaciones con los clientes.

#### Clases
- __Juego__: Es la clase principal del modelo. Esta clase contiene a los jugadores, a los objetos (Unidad, Edificio, Bandera, Bloque, etc), a las fábricas de los objetos (FabricaUnidades, FabricaMuniciones, FabricaEdificios, FabricaInmovibles) y a dos colas de mensajes (una para recibir y otra para enviar). Esta clase hereda de Thread, puesto que se busca que se ejecute en un hilo propio. El ciclo principal del juego se encuentran en el método ```run```, en el se va llamando a los métodos ```chequearColisiones```, ```eliminarMuertos```, ```actualizarDisparos``` y ```actualizarEdificios```. Estos métodos se encargan de actualizar el modelo en base a las acciones realizadas por los jugadores (recibidas en ```actualizarRecibidos```), y posteriormente se envían estas actualizaciones a los jugadores (mediante ```enviarMensajesEncolados```).
- __Jugador__: Esta clase se encarga de representar a los clientes dentro del servidor, es decir es la que se encarga de establecer las comunicaciones. Al igual que juego, ésta hereda de Thread, ya que cada uno de los jugadores deben estar esperando información de los clientes de forma simultanea. Por lo tanto, en el método ```run``` el Jugador está constanmente esperando recibir mensajes, los cuales se encolan en la colaDeRecibidos (la misma cola que tiene el servidor). Además contiene un método enviarMensaje que permite establecer una comunicación con el cliente en el sentido inverso al anterior. Estas comunicaciones son posibles ya que contiene un atributo Socket.
- __Objeto__: Todos los objetos visibles en el mapa heredan de Objeto (cuenta con caracteristicas básicas como son la vida, posicion, diensiones, un identificador y un tipo). Mediante el double dispatch hace posible el chequeo de colisiones entre distintos tipos de objetos, actuando en cada caso en consecuencia. De esta clase heredan __Movible__, __Inmovible__, cada cual con sus herederos respectivos (__Unidad__, __Municion__, __Bandera__ y __Bloque__).
- __Fabricas__: La creación de la mayoría de los distintos elementos integrantes del modelo se realiza mediante fábricas. Éstas continenen las características particulares de cada tipo de objeto (leido mediante xml al ser instanciadas) y las van cargando en los objetos devueltos. El modelo contiene varios tipos de fábricas: __FabricaUnidades__, __FabricasTerrenos__, __FabricaMuniciones__, __FabricaInmovibles__, __FabricaEdificios__, etc. En general el método más importante de lás fabricas es el que devuelve un elemento del que es fabricado (ejemplo, getUnidad, getTerreno, getMunicion, etc.), pero además, en algunos casos, se utiliza para conocer de forma externa algunas características de las mismas (getAlcance, getTiempo, etc.).
- __AEstrella__: Es una clase que se encarga de calcular los recorridos AEStrella para cada tipo de unidad (para eso utiliza la función ```getRecorrido```), desde una posición de origen a una de destino.

#### Diagramas UML
#### Descripción de archivos y protocolos

### Client
#### Descripción general
#### Clases
#### Diagramas UML
#### Descripción de archivos y protocolos


