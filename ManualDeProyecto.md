# Manual de Proyecto

## Integrantes y división de tareas

La distribución de tareas se tuvo que reorganizar debido a que un integrante debío abandonar trabajo.

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
    - Selección de unidades y fábricas. Acciones de mover y atacar. Selección de que unidad crear.
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
    - Refactor de factories (antes implementadas como singleton).
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
### Cliente
#### Performance
Un gran inconveniente encontrado del lado del cliente que llevó un par de días de trabajo e investigación fue consumo del CPU. La performance era muy pobre incluso cuando solo se estaba mostrando el mapa, sin unidades moviendose ni otros elementos animados.


## Analisis de puntos pendientes

## Herramientas

## Conclusiones
    
    


