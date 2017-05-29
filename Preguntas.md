## Martes 30/05 ##
#### Male (Cliente) ####
1. Me conviene guardar el offset o la pos real de cada elemento? .. creo el la pos real -> entonces como hago para "saber" el offset sin tener que andar pasandolo por todos lados???
2. que tan malo es chequear nullptr? seguramente deberia hacer un get
3. Como hago para cuando cierro el SDL, lo pongo en el ~ directamente? o es conveniente dejar la funcion close


## Martes 23/05 ##
#### Male (Cliente) ####
1. Se recibe el mapa por sockets y se guarda en un archivo para que SDL dsp lo dibuje o se lo vamos pasando desde el socket a SDL? Yo me inclino por lo primero. 

2. Como manejar los frames x segundo para las animaciones? cada vista tiene un contador y cada tantas vueltas en el loop actualiza el clip de la animacion? porque si lo hago global el scrolleo del mapa queda mal.

3. Cargar textura una sola vez por cada unidad que exista y dsp c/ unidad real toma la imagen que le sirve de aquella textura en vez de cargar por cada unidad existente la misma textura. Es correcto? Qué tan difícil sería cargar la textura solo si se crea una unidad nueva cuya textura no estaba cargada? __map con punteros a las vistas__

4. Tanques tienen cañón que se podría mover independientemente de la dirección del tanuqe, hace falta? Se podría girar el tanque para disparar __SE  MUEVE TODO EL TANQUE__

5. Cuando se hace un click, le digo que id se toco al server para que me devuelva que mostrar? o muestra el cliente la ventana que corresponde y despues manda al server que accion se hizo? __cliente tiene qe saber que unidades tengo que son mias__

6. Puedo esperar que el servidor me diga correctamente qué métodos usar sobre un Elemento del mapa? Así no tengo que preocuparme de intentar validar Si x Elemento es del tipo ElementMovible y directamente hago elementos[id].mover(x,y). Relacionado: como manejo los containers de elementos? quiero poder tener un vector de todos los elementos y poder decirles mostrate a todos, pero por otro lado necesito un vector de ElementosUnidad para poder decirles movete o ataca...  o a la clase Elemento le hago un metodo mover xej vacio y solo esta bien implementado en clases que lo usan? __tengovarios contenedores, o dynamic cast__

7. Colores de las unidades:
  * hago una vista con todos los colores y cada elemento elige la fila en el spritesheet que le corresponde
  * hago una Textura para cada color
  * cambio el string de donde la vista saca la imagen.. aunque me traeria otros problemas con el diseño que ya tengo.
  __mismo spirete sheet de todos los colores__
  
8. Elementos son los SDL_Rects que toman el clip que necesitan de una Vista, una misma vista es usada por varios elementos que son del mismo tipo. Necesito que los elementos sepan quiénes son? Empecé haciendo ELementoRoca ElementoPuente etc, pero perfectamente podrían ser los dos ElementoNoAnimado o algo asi y todos las unidades son ElementosAnimados o Movibles o lo que sea, siento que al tener el id a mi no me importa qué exactamente es un elemento, solo necesito su id para pasarle al Server. La única diferencia entre mismos tipos(movible, no movible, etc) de elementos va a ser qué vista le paso cuando lo creo.

9. Como se maneja el caso en que un robot esta disparando (animacion corriendo) y lo muevo? Tiene que terminar la otra animacion primero. Pasa unos instantes desde que se dispara y conecta con un enemigo, el servidor me va actualizando sobre el estado y el camino de la bala y si conecto o no, no? El servidor va a saber en cuantos ticks alguien va a morir o el robot termina de disparar para no dejar al cliente intentar hacer cosas como mover al robot mientras esta disparando?

10. Elementos con bools 'muriendo' 'disparando' 'caminando' para pasar de una tarea a otra, hay una mejor manera?__ENUM DE ESTADO__

11. ESTETICA QUE ONDA __NO IMPORTA__


12. ROOCA ES UN TIPO QUE ME VA A LLEGAR, YO TENGO QUE PONER UN TILE ABAJO.

13. BANDERAS 
