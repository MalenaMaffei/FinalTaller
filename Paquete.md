**Todos los paquetes seran precedidos por su largo, un int de 4 bytes, valga la redundancia, no lo agrego en los diagramas.**
### Paquetes que envía el Cliente ###
##### Mover ######

comando | id | x | y
--- | --- | --- | ---
2 | 007 | 0001 | 0001
1 char | 3 chars | 4 chars | 4 chars

##### Crear ######
Lo van a enviar las fabricas

comando | id | x | y | tipo 
--- | --- | --- | --- | --- 
0 | 007 | 0001 | 0001 | 09 
1 char | 3 chars | 4 chars | 4 chars | 2 chars 

##### PedirInfo ######
Se va a enviar cuando el usuario hace click sobre una unidad para saber su vida

comando | id |
--- | --- |
4 | 007 |
1 char | 3 chars |

##### Disparar ######
comando | id | id
--- | --- | ---
3 | 007 | 001
|| agresor | agredido
1 char | 3 chars | 3 chars

### Paquetes que necesita el Cliente ###
Hay un par que todavia no diseñe: Los de sonido y los de informacion sobre que unidades puede fabricar una fabrica, el tiempo para terminar de fabricar y por otro lado los de la info que necesita el hHUd( cuanta vida le queda a la unidad y si un vehiculo esta ocupado).
##### Mover ######

comando | id | x | y
--- | --- | --- | ---
2 | 007 | 0001 | 0001
1 char | 3 chars | 4 chars | 4 chars

##### Crear ######
Lo van a enviar las fabricas

comando | id | x | y | tipo | color
--- | --- | --- | --- | --- | --- 
0 | 007 | 0001 | 0001 | 09 | 2 
|||||| color de 0 a 3 |
1 char | 3 chars | 4 chars | 4 chars | 2 chars | 1 char

##### Disparar ######
Solo necesito quien y a donde se dispara para poder calcular el sprite a usar

comando | id | x | y
--- | --- | --- | ---
3 | 007 | 0001 | 0001
|| disparador ||
1 char | 3 chars | 4 chars | 4 chars

##### Matar ######

comando | id |
--- | --- |
1 | 007 |
|| el/lo que murio |
1 char | 3 chars |


##### Enviar Mapa #####

comando |  

Esto es lo que estoy usando yo para definir los comandos que hay, los tipos de unidades, y los largos de cada comando:
```c++
enum comandos{
  crear = 0,
  matar = 1,
  mover = 2,
  disparar = 3,
  info = 4,
  mapa = 5,
  equipo = 6
};

enum tipos{
  roca = 0,
  puente = 1,
  bandera = 2,
  fuerte = 3,
  fabricaRobot = 4,
  fabricaVehiculo = 5,
  grunt = 6,
  psycho = 7,
  tough = 8,
  pyro = 9,
  sniper = 10,
  laser = 11,
  jeep = 12,
  light = 13,
  medium = 14,
  heavy = 15,
  missile = 16
};

enum largos{
  comando = 1,
  id = 3,
  x = 4,
  y = 4,
  delCliente = 1,
  tipo = 2,
  color = 1
};

  enum colores{
    amarillo = 0,
    azul = 1,
    rojo = 2,
    verde = 3
  };
```
