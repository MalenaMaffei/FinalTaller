#### Mapa ####
1. el mapa era una tabla de hash con coordenadas como claves, en cada valor habia una parcela.
2. Habia 3 tipos de parcela: aire, tierra y mineral. Cada unidad podia caminar sobre distintos tipos de parcelas. Lo que se hacia era un dispatch: unidad le dice a parcela guardame y se mandaba a si mismo, parcela recibia a la unidad en ese metodo y llamaba a un metodo de unidad que usaba dispatch para depende que parcela habia llamado sabia si guardarse o no. No me acuerdo el nombre del patron.
3. Habia una funcion que creaba mapas al azar pero no al 100%, se creaban bloques de distintas parcelas para que tuviera un poco de logica el mapa.
