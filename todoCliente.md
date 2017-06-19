## Cliente

* *Canvas.cpp*:

    * ~~**"Fix pedorro"**~~ Cambiado a fix malo

    * Explicar los timers utilizados

    * Separar la carga del juego del *main loop*

* *Cola Salida*: Usar referencias en vez de punteros... ¿Para qué se usa? ¿Es Thread safe? -> Creo que es thread safe, supongo que con referencias se refiere a los mutexes, confirmar. 

* Realizar los *TODO*s

    * Funcionalidad faltante

    * Código no performante, poco claro, sin RAII, etc -> Preguntar por sin RAII

* ~~Crashea si no le paso los parámetros correctamente, no hay texto de ayuda.~~ tiene los try catch necesarios e imprime mensajes mas amigables cuando pasa algo y  si no le pasas los parametros, te los pide. 


* **ELIMINAR BUSY WAITS** -> Preguntar donde

* Hay mucho código comentado, hay código "complejo" sin comentar.

* Falta comentar headers, describir clases y métodos no triviales.

* Falta loggear actividad. -> Preguntar

* Clientes y servidores frágiles, el crash en uno termina con todos. -> del lado del cliente ahora se cierra grácilmente si el servidor se cae, con eso basta? Preguntar qué mensaje amigable se puede mostrar al margen de  "Se cerro el socket" y en esa linea... hace falta que muestre los errores? O directamente digo, se cerro la conexión en todos los casos y chau?
//            TODO se podria decir, si ya estaba salir==true, es que cerre yo
// al socket entonces no muestro nada. si salir==false, se cerro desde el server

* Consumo alto de cpu sobre todo en el cliente.

### PREGUNTAS ###
* Hago excepciones para cuando no se puede cargar una imagen y cosas asi o dejo que el juego siga su curso?
* Updates de hud y factoryGui? Por ahora reciben la info cada vez que se hace un click, pero si me queda seleccionada no es que se actualiza. 
* Clase bala. no la tuve en cuenta al diseñar y ahora me quedo un hibirido malisimo.
* Clase ElementoGui, asi en hud y el oyto tengo una lista y nada mas les paso los paquetes que me llegan y cada uno se enciende o se apaga o setea sus atributos de acuerdo a eso. Me da miedo que me lleve mucho trabajo y sea dificil de debugguear
* Clase Paquete y PaqueteFabrica no hay herencia entre ellas... crear clase madre qeu una a las dos? Aunque tendrian muy pocas cosas en comun
-----
##### COMENTAR CODIGO #####



6. inhibir errores de valgrind de SDL.

7. spcket reuseaddrinfo.

8. que el hud cree todas sus vistas.

11. poner para los items de abajo en su clase vista que codigo se corresponde con que posicion en el spritesheet.
 
12. que se muestren armas

13. que se muestren tanques

14. qye se muestren construibles

15. terminar de crear spritesheets para los vehiculos que faltan.

16. ver como refactorizar clase bala. 

18. mostrar al jugador que color le toco ni bien le llega el paquete.

19. generar sonidos cuando haya un paquete que sucede dentro de la camara.

25. Refactor en edificioGui, crear clase guiElement o algo asi y usar composicion en vez de un millon de atributos

27. Si sobra tiempo, mensaje en la ventana misma "esperando que se conecte el resto de los jugadores" y despues que muestre el color que te toco. Ideal seria que el servidor te pase un color ni bien te conectas, asi te dice que color sos mientras que esperas al resto.

28. En el hud se puede poner tambien una etiqueta que te diga que color sos.

29. SelectBox se vacia solo cuando se hace una nueva seleccion. Preguntar por las dudas.

30. Capturar ubicacion del fuerte al comienzo y qye empuece la pantalla alli.

31. shortcut para ir a tu fuerte de una.

32. Mouse sprite cuando se hace click?

33. Hacer pruebas definitivas de no seleccion de muertos.

34. Bala Podría ser un elemento coloreado asi se sabe cuales son de quien.

#### Resuletos ####

34. ~~cliente se queda trabado cuando no hay server, en vez de crashear. ~~
1. ~~Arreglar Bug Seleccion de muertos y moribundos.~~
2. ~~Arreglar bugs de offset para botones del gui del edificio.~~
3. ~~Pasar SDL al main en un solo thread.~~
4. ~~Crear cola bloqueante para el sender.~~
5. ~~ver que onda el uso del CPU.~~
9. ~~ver como pedir los tiempos en los paquetes.~~
10. ~~display tiempo en gui fabrica.~~
11. ~~barra de vida.~~
* ~~en hud~~
* ~~en guiEdificio~~
* ~~para la construccion~~
17. ~~mandar paquetes de pedido de informacion.~~
20. ~~como despertrar a la cola sender cuando esta durmiendo para poder cerrar el juego~~ 
21. ~~Poner destructores de vistaManager y elementoManager~~
22. ~~clase mapa para mostrar mapa en vez de mostrar tiles~~
23. ~~VistaColoreada heredada por vistabandera creo que no sirve para nada, revisar bien~~
24. ~~in lieu de gui, mostrar mensajes amigables por consola para setear ip y puerto.~~
26. ~~mostrar el tiempo de una manera mas elegante.~~
29. ~~Catch exceciponmes de socket, en particular cuando no te podes conectar, que diga server lleno conectese mas tarde o algo asi.~~
