# FinalTaller


## Ideas Generacion de Mapas teniendo en cuenta los tiles que existen ##
* Estoy probando con una vista de águila de 800\*600 y un mapa total de 3200\*3600 lo que sería 200\*225 tiles, parecería ser una buena resolución, cuando tenga un mapa completo lo subo y se fijan que les parece en términos de jugabilidad.
* Propongo para los mapas usar el típico archivo .map, es una matriz de números, cada uno índica un tipo de tile.
* Al comienzo del mapa se indica si es de tipo jungla, ciudad o artico
* Tierra, Pradera o Nieve se simbolizarían con un solo numero (p. ej 0), la imagen la decide el cliente teniendo en cuenta el comienzo del mapa
* Agua y Pantano, mismo número PERO hay que tener otro simbolo para los __bordes__ . Propongo agua para ciudad y artico y pantano para jungla.
* Lava es la misma p/ todos los tipos de mapa
* Carretera, Camino mismo número también, yo pondría la carretera para ciudad y artico y el Camino para la jungla. ~~Mismo tema de señalizar los bordes de las carretaras/caminos con otro número más.~~ Encontré unos tiles que son como baldozas y no harían falta los bordes para distinguirlos.
* Puentes, rocas etc se mandan por separado con sus posiciones, no serían parte del mapa ya que se dibujan *sobre* los Tiles y se pueden destruir.
