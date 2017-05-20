# FinalTaller


## Ideas Generacion de Mapas teniendo en cuenta los tiles que existen ##
* Propongo para los mapas usar el típico archivo .map, es una matriz de números, cada uno índica un tipo de tile.
* Al comienzo del mapa se indica si es de tipo jungla, ciudad o artico
* Tierra, Pradera o Nieve se simbolizarían con un solo numero (p. ej 0), la imagen la decide el cliente teniendo en cuenta el comienzo del mapa
* Agua y Pantano, mismo número PERO hay que tener otro simbolo para los __bordes__ 
* Lava es la misma p/ todos los tipos de mapa
* Carretera, Camino mismo número también, yo pondría la carretera para ciudad y artico y el Camino para la jungla. Mismo tema de señalizar los bordes de las carretaras/caminos con otro número más.
* Puentes, rocas etc se mandan por separado con sus posiciones, no serían parte del mapa ya que se dibujan *sobre* los Tiles y se pueden destruir.
