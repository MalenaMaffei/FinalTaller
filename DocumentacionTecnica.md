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
apt-get install libsdl2-ttf-dev
yum install SDL2_mixer-devel
apt-get install libsdl2-mixer-dev

```

### tinyXML2
También es necesario tener TinyXML2 instalado.

```
apt-get install libtinyxml2-dev
```
Para tener la versión más nueva se puede usar el código fuente del github del protyecto: https://github.com/leethomason/tinyxml2. Instrucciones para instalar la librería usando el código fuente del Repositorio pueden encotnrarse aquí: https://charmie11.wordpress.com/2014/03/24/script-for-install-tinyxml2-on-ubuntu/ (recurso en inglés).

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
El Cliente es el encargado de reflejar el estado de juego mediante animaciones y sonidos. Asimismo es el encargado de reportar todas las acciones del usuario al servidor, que serán luego reflejadas en el modelo del juego.

#### __Clases__
El funcionamiento general del cliente puede ser resumido a tres clases principales: __PaqueteReceiver__, __PaqueteSender__ y __Canvas__. Las primeras dos son las que se encargan de la comunicación por sockets con el servidor y la última es la que interactúa con el cliente y renderiza todo el juego.
***
##### PaqueteReceiver
Esta clase es la encargada de recibir los paquetes que llegan del servidor. Está constantemente recibiendo por el socket y cuando algo llega, lo encola en __ColaPaquete__ para que sea procesado por __Canvas__.
***
##### PaqueteSender
Aquí se envían los paquetes previamente encolados por __Canvas__.
***
##### Canvas
Esta clase es la que maneja todas las acciones del cliente y todas las visualizaciones, aquí es donde SDL es utilizado.
Las responsabilidades de esta clase son: interpretar todos los paquetes que llegan del servidor por medio de __PaqueteReceiver__, reflejar estos paquetes mostrando el estado del juego en la pantalla mediante el *GameLoop* y por último interpretar los eventos generados por el cliente para enviarle al servidor la acción que el usuario quiso llevar a cabo. En este sentido, el Cliente no es del todo "tonto". No se limita a informar "el cliente hizo click en x,y" si no que interpreta una cadena de eventos para enviar al servidor mensajes del tipo "Id x ataca a id y" o "pedir informacion de la unidad de id x", para dar unos ejemplos.
A continuación se hará una descripcion de las partes mas importantes que componen a esta parte del cliente.

###### Análisis de eventos
Los eventos soportados por esta aplicación son: movimiento del mouse, click del mouse, apretar la barra espaciadora, apretar las teclas w,a,s,d y cerrar la ventana.
* __Mouse__: Esta clase se encarga de registrar los eventos relacionados al mouse. Cuando detecta que se quiso hacer una seleccion (arrastrar apretando el botón derecho), le infroma a la clase __SelectBox__ de qué dimensiones es el rectángulo de selección creado. Cuando detecta un click izquierdo le informa a la clase __Click__ las coordenadas del mismo. En __SelectBox__ quedarán guardadas las unidades seleccionadas y en __Click__ el elemento clickeado.
* __ColectorDeAcciones__: Aquí es donde se interpretan los contenidos de __SelectBox__ y __Click__ y se decide cuál fue la acción específica que quiso realizar el usuario. Una vez determinada la misma aquí mismo se arma el Paquete y se encola en __ColaDePaquetes__, cola compartida con __PaqueteReceiver__.
* __Camara__: Camara es básicamente un rectángulo __Rect__ contra el cuál se comparan todos los elementos del mapa para ver si hay una colisión. Si la hay, el elemento será mostrado. La cámara se puede mover usando w,a,s,d para moverse en las cuatro direcciones y usando la barra espaciadora se vuelve en un solo movimiento al fuerte del jugador.

###### Reflejando el estado del modelo
En el cliente hay una relación uno a uno con todos los elementos existentes en el modelo del servidor. Todos los elementos son de clase __Elemento__ con una __Vista__, que es la que contiene a la imagen que representará al elemento en pantalla. __ElementoManager__ y __VistaManager__ son las clases que coordinan el acceso y creación de estas clases respectivamente.
* __Elemento__: compuesto por un puntero a una __Vista__ y un rectángulo __Rect__. El mismo reflejará la posición del elemento renderizándose la imagen pertintente sobre él y también se utilizará para registrar clicks sobre el __Elemento__, entre otros atributos.
* __Vista__: hereda de __Texture__ que es una clase que simplemente encapsula a SDL_Texture. Hay una __Vista__ por cada tipo de elemento que existe en el juego. Una __Vista__ contiene la imagen entera de animaciones que componen a un elemento del juego. Por ejemplo, la vista de un Fuerte es una imagen que contiene varios cuadros de la animación del mismo más un cuadro extra que se muestra al ser destruido, asimismo  la imagen contiene a todas las animaciones del mismo elemento pero de diferentes colores. Lo positivo de este enfoque es que se cargan pocas imágenes en memoria y además todos los elementos de un mismo tipo comparten una misma __Vista__.
* *manejarPaquetes*: Aquí se desencolan los paquetes de la __ColaPaquetes__. Este método es el que define qué hay que hacer con cada __Paquete__, hay tres tipos: __PaqueteAccion__, que es enviado a __ElementoManager__; __PaqueteUnidad__, que es enviado al __Hud__ (dónde se muestra la vida de la unidad seleccionada); y por último __PaqueteFabrica__, usado por __GuiFabrica__ para mostrar al usuario las distintas unidades que la fábrica puede construir. También en *manejarPaquetes* se reproducen sonidos para informar al usuario de algunos __Paquetes__ que merecen la atención del usuario.
***

#### __Concurrencia__
Debido a la necesidad de mostrar constantemente animaciones por pantalla y monitorear las acciones del usario al mismo tiempo que se envían y reciben mensajes por __Sockets__, se tuvo que hacer una implementación concurrente del juego. El juego está compuesto de 3 __Threads__. La principal es la que hace la primer conexión con el servidor y luego corre __Canvas__. Las otras dos threads son __PaqueteReceiver__ y __PaqueteSender__, ambas cuentan cada una como se mencionó anteriormente con una __ColaPaquetes__. Esta implementación de cola contiene __Paquetes__, está protegida con mutexes y tiene dos versiones de *desencolar*: una normal y una bloqueante. *desencolarBloqueante* es utilizado por __PaqueteSender__ para que no este constantemente chequeando si hay algo en la cola para enviar, directamente intenta desencolar y se quedará bloqueado allí hasta que entre un nuevo __Paquete__ en la cola. __PaqueteReceiver__ simplemente se queda bloqueado en *Socket::Receive* hasta que haya algo para recibir.




#### Diagramas UML
#### Descripción de archivos y protocolos
