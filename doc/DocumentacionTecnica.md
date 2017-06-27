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
- __Objeto__: Todos los objetos presentes en el mapa heredan de Objeto (cuenta con caracteristicas básicas como son la vida, posicion, dimensiones, un identificador y un tipo). Mediante el double dispatch hace posible el chequeo de colisiones entre distintos tipos de objetos, actuando en cada caso en consecuencia. De esta clase heredan __Movible__ e __Inmovible__, cada cual con sus herederos respectivos (__Unidad__, __Municion__, __Bandera__ y __Bloque__).
- __Fabricas__: La creación de la mayoría de los distintos elementos integrantes del modelo se realiza mediante fábricas. Éstas continenen las características particulares de cada tipo de objeto (leido mediante xml al ser instanciadas) y las van cargando en los objetos devueltos. El modelo contiene varios tipos de fábricas: __FabricaUnidades__, __FabricasTerrenos__, __FabricaMuniciones__, __FabricaInmovibles__, __FabricaEdificios__, etc. En general el método más importante de lás fabricas es el que devuelve un elemento del que es fabricado (ejemplo, getUnidad, getTerreno, getMunicion, etc.), pero además, en algunos casos, se utiliza para conocer de forma externa algunas características de las mismas (getAlcance, getTiempo, etc.).
- __AEstrella__: Es una clase que se encarga de calcular los recorridos AEStrella para cada tipo de unidad (para eso utiliza la función ```getRecorrido```), desde una posición de origen a una de destino.

#### Diagramas UML

En primer lugar, para lograr entender el modelo, es necesario comprender como están relacionados los objetos que están involucrados en el mismo. Como se mencionó anteriormente, todos los objetos que forman parte del juego propiamente dicho heredan de la clase __Objeto__. En el siguiente diagrama de clases se puede observar como se relacionan los mismos.

![Herencia de los distintos tipos de objeto](img/Objetos.png)

Como se puede ver, hay dos clases principales que tienen como padre __Objeto__, estas son __Movible__ e __Inmovible__. Como sus nombres lo indican, la diferencia entre estos es que los objetos del primer grupo tienen la logica necesaria para poder moverse, mientras que los del segundo grupo no.
A su vez, de __Movible__ heredan __Unidad__ y __Munición__. __Unidad__ incluye a los personajes que pueden ser movidos por los jugadores correspondientes. Las unidades guardan la lógica necesaria para realizar disparos y capturar banderas. __Municion__ es la clase que representa a las balas generadas cuando una __Unidad__ desea efectuar un disparo. 
Por otro lado, de __Inmovible__ se observa que se desprenden __Bloque__, __Bandera__ y __Edificio__. El primero, es simplemente un objeto que ocupa un espacio en el mapa, el segundo ocupa un espacio en el mapa pero además al pasar una __Unidad__ por el mismo la bandera es capturada, y por último en __Edificio__ se guarda la lógica de la creación de unidades (desde el punto de vista del modelo, no es la clase que genera las instancias de __Unidad__).

Dicho esto, es importante mencionar que esta estructuración permite que cualquier objeto pueda colisionar con cualquier objeto, y que internamente dependiendo de las clases de los mismos, las colisiones se manejen según correspondan. Veamos simplemente los métodos de __Objeto__ que permiten esto:

![Metodos de colisión, en Objeto](img/ObjetosColision.png)

Como se puede ver, todo objeto debe saber colisionar con cualquier instancia de una clase heredra de Objeto.

Pero la clase principal del modelo, no es __Objeto__, sino __Juego__. Esta clase es la más extensa e importante del modelo, y tiene la funcionalidad principal de __manejar y modificar los estados del modelo__. Pero estas modificaciones deben ser desencadenadas a partir de mensajes recibidos del cliente. Por lo tanto el __Juego__ debe también __interactuar con los jugadores__. Por lo tanto, se puede decir que es una clase con dos "caras". 

Veamos la primera:

![Juego como administrador de estados del modelo](img/JuegoModelo.png)

Se puede observar que los métodos que están involucrados son:
- ```moverUnidades```: Como su nombre lo indica, se encarga de mover los movibles, tanto de la clase Robot, como Vehículo y Munición.

- ```chequearColisiones```: Verifica si hay objetos que están colisionando, y en caso de colisión llama a los métodos colisionar para que ocurra la interacción esperada.

- ```eliminarMuertos```: Elimina todos los objetos que estén muertos (con vida menor a 0).

- ```actualizarDisparos```: Si una Unidad debe generar un nuevo disparo, realiza el disparo creando la nueva Munición correspondiente.

- ```actualizarEdificios``: Si un Edificio debe generar una nueva unidad, crea la nueva Unidad.

Además de una serie de métodos de inicialización de Juego, y el método ```run``` en donde se inicia el hilo y con él, el ciclo de juego.

A fin de manejar el modelo, la clase Juego cuenta con las clases fábrica, que permiten generar los Inmovible y Movible que luego se almacenan también en la clase principal. Además, el Juego contiene un Mapa, y utiliza la clase AEstrella para generar los caminos de las unidades.

Por otro lado, en lo que respecta a la interacción:

![Juego como comunicador con jugadores](img/JuegoComunicacion.png)

En primer lugar, en este diagrama de clases se puede observar que tanto Juego como Jugador heredan de la clase Thread. Es decir, los métodos run correrán en hilos separados.
Dentro de Juego, se observan una serie de métodos encargados de recibir mensajes y enviar mensajes. Estos mensajes se modelan en la clase Mensaje, la cual dependiendo del tipo de mensaje se encarga de generar y guardar el string que se enviará posteriormente a los clientes. El intercambio de mensajes con los clientes se realiza mediante la clase Jugador, la cual encola los mensajes recibidos en la colaDeRecibidos (posteriormente los lee el Juego) y va enviando mensajes desde servidor a medida de que el Juego llama a ```enviarMensaje```. 

A partir de este diagrama se introduce la concurrencia dentro del servidor, para aclarar un poco este funcionamiento se puede observar el siguiente esquema:

![Esquema general de comunicación](img/Esquema.png)

En este diagrama ilustrativo se puede observar la correlación uno a uno entre Jugador y Cliente. Por cada Cliente hay un Jugador en el modelo con el cual interactua. Una vez recibido los mensajes, cada Jugador encola los mensajes en una colaDeRecibidos, como lo ilustra el esquema. Estos mensajes luego son desencolados por el Juego, el cual los procesa, y encola nuevos mensajes para los clientes (en la colaDeEnviados). Luego, va desencolando los mensaje y los envía a cada uno de los jugadores para que los evíen a sus clientes.

Se puede observar que, dado que tanto los Jugadores como el Juego corren concurrentemente, la colaDeRecibidos puede llegar a intentar ser accedida por varios jugadores en simultaneo. Por lo tanto, esta es la principal fuente de _race conditions_ que puede existir dentro del servidor. Para evitar que se produzcan resultados no determinísticos por esta causa, se optó por proteger esta cola mediante el uso de un __lock__. Así, todo acceso (tanto de escritura como de lectura) está protegido.


#### Descripción de archivos y protocolos

### Client
#### Descripción general
El Cliente es el encargado de reflejar el estado de juego mediante animaciones. Asimismo es el encargado de reportar todas las acciones del usuario al servidor, que serán luego reflejadas en el modelo del juego.

#### Clases
El funcionamiento general del cliente puede ser resumido a tres clases principales: __PaqueteReceiver__, __PaqueteSender__ y __Canvas__. Las primeras dos son las que se encargan de la comunicación por sockets con el servidor y la última es la que interactúa con el cliente y renderiza todo el juego.
###### PaqueteReceiver
Esta clase es la encargada de recibir los paquetes que llegan del servidor. Esta constantemente recibiendo por el socket y cuando algo llega, lo encola en __ColaPaquete__ para que sea procesado por __Canvas__.
###### PaqueteSender
Aquí se envían los paquetes previamente encolados por __Canvas__
###### Canvas
Esta clase es la que maneja todas las acciones del cliente y todas las visualizaciones, aquí es donde SDL es utilizado.


#### Diagramas UML
#### Descripción de archivos y protocolos
