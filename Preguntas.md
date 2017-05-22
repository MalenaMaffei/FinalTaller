## Martes 23/05 ##
#### Male (Cliente) ####
1. Se recibe el mapa por sockets y se guarda en un archivo para que SDL dsp lo dibuje o se lo vamos pasando desde el socket a SDL? Yo me inclino por lo primero.
2. Como manejar los frames x segundo para las animaciones? cada vista tiene un contador y cada tantas vueltas en el loop actualiza el clip de la animacion? porque si lo hago global el scrolleo del mapa queda mal.
3. Cargar textura una sola vez por cada unidad que exista y dsp c/ unidad real toma la imagen que le sirve de aquella textura en vez de cargar por cada unidad existente la misma textura. Es correcto? Qué tan difícil sería cargar la textura solo si se crea una unidad nueva cuya textura no estaba cargada?
4. Tanques tienen cañón que se podría mover independientemente de la dirección del tanuqe, hace falta? Se podría girar el tanque para disparar
5. Cuando se hace un click, le digo que id se toco al server para que me devuelva que mostrar? o muestra el cliente la ventana que corresponde y despues manda al server que accion se hizo?
6. Puedo esperar que el servidor me diga correctamente qué métodos usar sobre un Elemento del mapa? Así no tengo que preocuparme de intentar validar Si x Elemento es del tipo ElementMovible.
