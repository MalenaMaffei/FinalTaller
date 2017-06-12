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
###### Ambos Casos (Unidad o  Fabrica): ######
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

##### Informacion #####
###### Caso Unidad: ######
comando | id | tipo | vida | 
--- | --- | --- | --- |
4 | 007 | 09 | 999 |
||| tipo unidad | vida que le queda |
1 char | 3 chars | 2 chars | 3 chars |

###### Caso Fabrica: ######
comando | id | tipo | vida | cant q puede construir | tipo 1 | tiempo 1 | tipo 2 | tiempo 2 | ... | esta construyendo? | tipo construyendo | %construido
--- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
7 | 007 | 03 | 999 | 02 | 09 | 0100 | 10 | 1400 | ... | 1 | 09 | 010 |
||| fuerte | vida que le queda | cuantas unidades sabe construir | tipo pyro | mmss |tipo sniper | mmss | ... | bool | tipo en construccion(si el anterior fue true) | % que ya se construyo (si el bool fue true) |
1 char | 3 chars | 2 chars | 3 chars | 2 chars | 2 chars | 4 chars | 2 chars | 4 chars | ... | 1 char | 2 char | 3 char |

##### Enviar Mapa #####

comando |  tiposTiles |
--- | --- |
1 char | 400x400 chars de ints| 

Esto es lo que estoy usando yo para definir los comandos que hay, los tipos de unidades, y los largos de cada comando:
```c++
enum tiles{
  pantano = 0,
  asfaltado = 1, 
  lava = 3, 
  tierra = 4,
  agua = 5,
  carretera = 6,
  nieve = 7,
  pradera = 8
}
enum comandos{
  crear = 0,
  matar = 1,
  mover = 2,
  disparar = 3,
  infoUnidad = 4,
  mapa = 5,
  equipo = 6, 
  infoFabrica = 7
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
    x = 5,
    y = 5,
    tipo = 2,
    color = 1
  };

  enum posiciones{
    posComando = 0,
    posId = 1,
    posX = 4,
    posY = 9,
    posTipo = 14,
    posColor = 16
  };
```
