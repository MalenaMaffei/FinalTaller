# Manual de Proyecto

## Integrantes y división de tareas

La distribución de tareas se tuvo que reorganizar debido a que un integrante debió abandonar trabajo.

__Distribución original__

- Malena Maffei: Cliente - Animaciones
- Matías Cano: Cliente - Generador y GUI
- 3er integrante: Servidor - Modelo

__Distribución final__

- Malena Maffei: Cliente - Animaciones y GUI.
- Matías Cano: Servidor - Modelo y Generador.

## Evolución del proyecto

### Semana 1
__Tareas propuestas__:
	- Definición de modelo, diagrama de clases y modelo de concurrencia.
	- Repositorio compartido.
	- Implementación del algoritmo A-Star sobre un mapa con distintos terrenos y con unidades con diferentes movilidades. Un robot o vehículo debería poder encontrar el camino a su objetivo.
	- Mostrar una imagen. Mostrar una animación. Mostrar ambas en un lugar fijo o desplazándose por la pantalla (movimiento).
	- Emitir un sonido. Carga y guardado de información a disco. Draft de la interfaz ( wireframes ).
__Tareas realizadas__:
	- Diagrama de clases incial del modelo y modelo de concurrencia.
	- Repositorio compartido.
	- Implementación básica de algoritmo A-Star, sin territorios, sin unidades.
	- Animación de personaje con movimiento usando SDL.
	- Clase reproductor de sonido con SDL. Herramienta tinyxml2 para manejo de archivos xml.

### Semana 2
__Tareas propuestas__:
	- Protocolo de comunicación cliente-servidor, definir clases pertenecientes a cliente y a servidor.
	- Compilado automático con cmake.
	- Finalización del algoritmo de A-Star. Lógica del modelo sobre el ataque y destrucción de unidades y edificios.
	- Mostrar todo el mapa, incluyendo varios tipos de territorios distintos, puentes, fábricas, banderas, robots y vehículos.
	- Mostrar una interfaz para el jugador, excepto el mapa. Incluye la vista de las caras de los robots seleccionados y crear nuevas unidades (fábricas y fuertes): mostrar unidades disponibles, sus tiempos y la unidad actual a crear.
__Tareas realizadas__:
	- Protocolo de comunicación, y definición de clases del cliente asociadas a las del servidor (relación vista/objeto).
	- Compilado automático con cmake.
	- Vista básica de mapa.
	- Interfaz para el jugador usando gtkmm.

### Semana 3
__Tareas propuestas__:
	- Lógica del modelo sobre la creación de los robots y vehículos.
	- Movimiento de la cámara pero ninguna animación o explosión o disparo.
	- Generación de mapas simples: terrenos y algunos objetos con posiciones fijas.
__Tareas realizadas__:
	- Inicio de lógica del modelo sobre creación de los robots y vehículos.
	- Movimiento de la cámara pero ninguna animación o explosión o disparo.
	- Se crearon las vistas de todos los elementos estáticos.
	- Generación de mapas mediante algoritmos aleatorio.

### Semana 4
___Baja de 3er integrante, reorganización de tareas___
__Tareas propuestas__:
	- Lógica de modelo sobre captura de territorios y condiciones de victoria y derrota.
	- Selección de unidades y fábricas. Acciones de mover y atacar. Selección de que unidad crear.
	- Creación de mapas complejos con todos los objetos sobre él, desde rocas hasta robots y fábricas.
__Tareas realizadas__:
    - Finalización de algoritmo A-Star
    - Lógica de ataque y destrucción de unidades y edificios.
    - Lógica de creación de robots y vehículos.
    - Lógica de captura de territorios.
    - Selección de unidades y fábricas. Acciones de mover y atacar. Selección de qué unidad crear.
    - Creación de animaciones para los movimientos y disparos de las unidades.
    - Comunicación básica cliente/servidor.

### Semana 5
__Tareas propuestas__:
    - Creación de una partida multijugador de N jugadores.
    - Mostrar las unidades con animaciones.
__Tareas realizadas__:
    - Implementaciónde protocolo de intercambio de mensajes entre cliente y servidor.
    - Profundización en la implementación del modelo.
    - Implementación de GUI en SDL (cambio respecto de la idea original de combinar SDL y gtkmm).

### Semana 6
__Tareas propuestas__:
    - Pruebas y correcciones sobre estabilidad, jugabilidad y performance.
__Tareas realizadas__:
    - Partida con un solo cliente, jugador puede disparar, eliminar, crear, moverse, etc.
    - Refactor de fábricas (antes implementadas como singleton).
    - Protocolo de comunicación entre cliente y servidor afianzado.
    - Primer partida multijugador, implementación de clase Jugadro en el servidor.
    - Creación de animaciones para las estructuras.

### Semana 7
__Tareas propuestas__:
    - Testing, corrección de bugs, documentación.
__Tareas realizadas__:
    - Mensajes de pedido de información de fabricas y unidades.
    - Finalización las Guis de unidades y fábricas.
    - Corrección de bugs.

### Semana 8
__Tareas propuestas__:
    - Testing, corrección de bugs, documentación.
    - Armado de entregable.
__Tareas realizadas__:  
    - Condiciones de victoria y derrota.
    - Refactor en clases del servidor y clientes.
    - Últimas imágenes de unidades generadas.
    - Mejoras en performance.
    - Cambios en la manera en que se renderiza el mapa en el Cliente.
    - Corrección de bugs.
    - Documentación.
    - Armado de entregable.

## Inconvenientes encontrados

### Servidor

#### Mapa invertido
Una problemática que surgió fue que se observó que al moverse la unidad en el mapa, sus velocidades variaban, pero no lo hacían acorde al terreno en el que estaba. Esto nos hizo sospechar del buen funcionamiento del A*. Luego de destinar un tiempo considerable a buscar el error en este algoritmo, se descubrió que el error estaba en la forma en que se enviaba el mapa. Mientras que en el cliente se iteraba primero filas y luego columnas, el servidor las enviaba como columnas y luego filas. Por lo tanto, el mapa observado por el cliente no era el mimso que usaba el algoritmo A*, y por tal motivo no estaban las velocidades bien asociadas.

#### Tiempo de A*
Dado el funcionamiento del algoritmo, en casos en que se eligen caminos muy largos o "costosos" de encontrar, puede llegar a tardar más del tiempo del del TICK asignado por el servidor. Para solucionar esto, se reemplazo la distancia euclideana como heurística por la distancia manhattan (la cual requiere un menor grado de cálculo), además se decidió poner un máximo numero de iteraciones en el algoritmo. Por lo tanto, en caso de no encontrar un camino en ese número de iteraciones, simplemente no hace nada. 
Esto además soluciona el problema de seleccionar como destino una posición con lava o inaccesible (rodeada por lava). Si bien el primer caso, se podría solucionar verificando que el destino no sea lava, el segundo caso es más complejo. Supongamos que se selecciona una isla que tiene lava a su alrededor, en este caso el algoritmo buscará exhaustivamente un camino hasta darse cuenta de que no puede llegar hasta allí.
Asimismo, esta problemática nos hizo dar cuenta de la necesidad de considerar el caso en que alguna iteración del ciclo de juego tarde más de un TICK de reloj. En estos casos, se opta por enviar la información en el siguiente TICK en el que esté obtenida.

#### Clase Juego
Si bien se buscó minimizar al máximo el código necesario en la clase Juego, esta fue una tarea dificil. La dificultad reside en que esta clase es la principal del modelo, y además requiere participar activamente del intercambio de información con los jugadores. Por lo tanto, no solo debe contener los métodos y atributos del modelo, sino también una serie de métodos y atributos asociados a la comunicación con los jugadores. Por este motivo, la clase tomó una extensión considerablemente mayor con respecto a otras clases, y si bien se la refactorizó con el fin de minimizarla, no se la pudo reducir a una extensión todavía menor.

#### Bugs varios
A lo largo del desarrollo del juego se fueron encontrando distintos bugs. El primero fue que las balas finalizaban en el objetivo (en lugar de seguir su trayectoria), por más que este haya sido eliminado. Otro bug con disparar fue que en caso de disparar a un objeto lejano, se ponía a disparar constantemente por más de que no llegara nunca la munición. Además, fueron surgiendo otros bugs que solo se percibían mediante la visualización del cliente, por lo que recién establecida la comunicación pudieron ser resueltos.


### Cliente
#### Performance
Un gran inconveniente encontrado del lado del cliente que llevó un par de días de trabajo e investigación fue consumo del CPU, no fuimos conscientes del mismo hasta la semana 7 aproximadamente. La performance era muy pobre incluso cuando solo se estaba mostrando el mapa, sin unidades moviendose ni otros elementos animados.
Al principio se pensó que el problema podía ser el hecho de que se iteraran todos los tiles del mapa a ver cuáles estaban siendo enfocados por la cámara y debían ser mostrados, ya que originalmente el mapa era de 160.000 tiles.
Se pasó a calcular qué índices del vector de tiles se verían enfocados por la cámara de acuerdo a su posición actual e iterar y mostrar solamente aquellos (1875 tiles). Lamentablemente, si bien el consumo bajó, no se solucionó el problema.
Eventualmente se llegó a la conclusión de que el problema era que la pantalla se refrescaba constantemente, ya que incluso elementos estáticos tenían animaciones, por lo cual no era posible actualizar la pantalla solo cuando ocurría algún evento.
Después de encontrado el origen del alto consumo, se empezaron a investigar distintas técnicas para no tener que actualizar los tiles en cada iteración del Game Loop. Esto llevó un tiempo considerable, pero se le dió la más alta prioridad ya que en algunas máquinas era casi imposible disfrutar del juego.
Finalmente investigando la documentación de SDL se encontró la función SDL_SetRenderTarget, que permite usar una textura como renderer en vez de la pantalla. Al parecer el problema era el overhead de renderizar muchos elementos chicos (tiles) en vez de una sola textura del tamaño de toda la pantalla.
Lo que se hace entonces en cada iteración del Game Loop es:
1. Chequear si la cámara se ha movido:
	* Si lo hizo, se cargan todos los tiles a ser renderizados a una textura, y después se la renderiza a la pantalla.
	* Si la cámara no se había movido, se reusa la textura de tiles que había sido cargada en alguna iteración anterior.  
2. Luego, todo el resto de los elementos son renderizados directamente a la pantalla.
3. Al finalizar el loop, se limpia la pantalla.

#### Spritesheets y Guis dentro del Juego
La creación de spritesheets fue un proceso tedioso y largo, mucho más de lo que se había previsto inicialmente. Se tomo un enfoque pragmático, al principio solo había una sola imagen para todos los robots y otra para todos los vehículos, de a poco se fueron agregando las imágenes particulares.
La creación de guis también fue larga y se le fueron agregando elementos por partes. Al comienzo se pensaba usar un diseño propio, pero finalmente se optó por copiar lo más posible las guis originales de juego, ya que eran claras y sobretodo intuitivas y nos pareció que intentando reinventarlas íbamos a terminar tardando más tiempo.

#### Mal uso del Socket
En la última semana, probando el juego en condiciones normales, el mismo empezó a crashear. Después de un tiempo pudimos identificar que el problema se generaba al momento de leer o envíar al Socket. El problema surgía cuando se intentaban mandar y recibir muchos paqutes al mismo tiempo.
Finalmente, luego de una consulta, encontramos al culpable: ```int read = recv(fD, NULL, 0, MSG_DONTWAIT | MSG_PEEK);``` Su uso había pasado totalmente por desapercibido y no era necesario en absoluto.
Lamentablemente, como se explica en la Documentación Técnica, se usan dos threads para el envío y recepción de información, así que perdimos bastante tiempo investigando esta pista falsa convencidos de que el problema era debido a una Race Condition.



## Análisis de puntos pendientes
* Sonidos: Si bien el juego cuenta con la capacidad de reproducir sonidos, solo pudimos reproducir tres. Esto se debe a que para reproducir sonidos en otros eventos, debíamos enviar más paquetes y el servidor debía monitorear más eventos que no eran los estrictamente necesarios para el desarrollo del juego. Los eventos en los que hay sonido son los que coinciden con paquetes que ya estaba recibiendo el cliente de todas formas.
* Puentes: Finalmente no pudimos implementar la lógica de creación de puentes sobre un canal de agua.
* Generador de Mapas: Nos hubiera gustado poder terminar de pulirlo, hay algunos chequeos que no se hacen, como comprobar que haya un camino transitable entre todos los fuertes y filtrar que no queden tiles sueltos de un solo tipo, por ejemplo un solo tile de pradera en medio de un lago de lava.
* Las unidades no empiezan a disparar automáticamente cuando tienen a un enemigo al alcance.
* Los conductores de los vehículos son meramente estéticos, es decir, no tienen representación real ni en el modelo de servidor ni en el cliente, solo son mostrados en la gui como conductores. Tomamos esta decisión porque no llegamos a implementar la lógica de subir y bajar unidades de los vehículos, así que no nos pareció crear unidades de más (los conductores) que nunca van a interactuar con ningún otro elemento.
## Herramientas
* Para coordinar el trabajo se usó git, hosteando el repositorio en github.
* CMake fue usado para generar fácilmente los ejecutables.
* Para la realización del cliente se utilizó el IDE CLion. Realmente es altamente recomendable ya que se puede obtener una licencia gratis de estudiante muy fácilmente si se tiene un email otorgado por la FIUBA y ayuda mucho a la productividad.
* Para generar los spritesheets se usó una herramienta web muy útil y simple: https://draeton.github.io/stitches/ y para la edición de imágenes, Pinta: https://pinta-project.com/pintaproject/pinta/ también una herramienta sumamente simple aunque no cuenta con funcionalidades muy avanzadas.
* Para probar los mapas generados sin necesidad de correr el juego se implementó un script de python que lo visualizaba.

## Conclusiones
Realizar el juego fue un trabajo realmente arduo, aunque gratificante. Ninguno de los integrantes había encarado antes un proyecto de esta envergadura, así que fue una experiencia muy enriquecedora para ambos. 
Se hizo evidente muy rápidamente la importancia de una comunicación fluida entre ambos, muchas veces tanto del cliente, como del servidor se tuvo que modificar partes del código por no haber previsto el tipo de paquetes que iba a necesitar cada parte. En retrospectiva, lo primero que deberíamos haber hecho fue establecer un protocolo sólido de comunicación pensando con detenimiento en cada tipo de paquete y sus campos. Si bien al iniciarse el proyecto se buscó establecer esta "convención", en los comienzos tampoco sabíamos a ciencia cierta qué exactamente íbamos a necesitar. La conclusión que sacamos de este "catch-22", es que es fundamental tener un diseño básico pero hecho a conciencia antes de ponerse a hacer cualquier otra cosa.
Desde un punto de vista estrictamente técnico, el tp nos ayudo a consolidar conocimientos de concurrencia y de comunicación por socket, así como también nos dió mayor práctica en la programación en C++. Sin embargo, consideramos que un aprendizaje no menor, está en el manejo de un proyecto a mayor escala. A lo largo de este tipo de proyectos, pueden ocurrir inconvenientes o problemas que deben ser resueltos o que involucran realizar cambios con respecto a la idea inicial o incluso que implican una reestructuración en las tareas asignadas. Consideramos que en mayor o menor medida, es innevitable que ocurran, por lo tanto es importante mantener cierta flexibilidad con respecto a la planificación inicialmente propuesta y en cuanto a objetivos (dado el factor de tiempo).

En cuanto al trabajo práctico en particular, nos pareció que el juego propuesto era demasiado amplio. Con amplio nos referimos a que tenía quizas demasiadas "particularidades". Tal vez, hubieramos preferido un proyecto con un scope más limitado, pero poder hacerlo más prolijo y cumpliendo todas las especificacione. Positivamente, destacamos que la implementación de un juego puede ser motivadora a la hora de encarar un proyecto.

A modo de conclusión, consideramos que el trabajo permitió afianzar conocimientos no solo de programación, sino también en cuanto a administración de un proyecto.
