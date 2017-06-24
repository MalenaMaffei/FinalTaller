#ifndef TPFINAL_CONSTANTES_H
#define TPFINAL_CONSTANTES_H

//Tile constants
const int TILE_WIDTH = 16;
const int TILE_HEIGHT = 16;
const int TILE_CLIPS = 8;
const int TILESX = 400;
const int TILESY = 400;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int LEVEL_WIDTH = TILESX*TILE_WIDTH;
const int LEVEL_HEIGHT = TILESY*TILE_HEIGHT;



const int COLORES = 4;

const char tankPath[] = "../client/imgs/tank.png";
const char tilePath[] = "../client/imgs/todosTiles.png";
const char rocaPath[] = "../client/imgs/Rocas/roca_roca.png";
const char hieloPath[] = "../client/imgs/Rocas/roca_hielo.png";
const char balaPath[] = "../client/imgs/bala.png";
const char fuertePath[] = "../client/imgs/Edificios/fuerte.png";
const char fabricaVehiculosPath[] = ""
    "../client/imgs/Edificios/fabrica_vehiculos.png";
const char fabricaRobotsPath[] = "../client/imgs/Edificios/fabrica_robots.png";
const char puentePath[] = "../client/imgs/Puentes/bridge_city.png";
const char banderaPath[] = "../client/imgs/Banderas/bandera.png";

//------------ROBOTS------------------
const char robotCaminarPath[] = "../client/imgs/Robots/caminar_robot.png";
const char robotPyroDisparar[] = "../client/imgs/Robots/disparo_pyro.png";
const char robotGruntDisparar[] = "../client/imgs/Robots/disparo_grunt.png";
const char robotToughDisparar[] = "."
    "./client/imgs/Robots/disparo_tough.png";
const char robotLaserDisparar[] = "."
    "./client/imgs/Robots/disparo_laser.png";
const char robotPsychoDisparar[] = "../client/imgs/Robots/disparo_psycho.png";
const char robotSniperDisparar[] = "."
    "./client/imgs/Robots/disparo_sniper.png";
const char robotMuertePath[] = "../client/imgs/Robots/muerte.png";

//------------VEHICULOS------------------
const char heavyCaminarPath[] = "../client/imgs/Tanks/caminar_heavy.png";
const char heavyDispararPath[] = "../client/imgs/Tanks/disparar_heavy.png";

const char tanqueMuertePath[] = "../client/imgs/Tanks/explosion.png";
const char tanqueMissilePath[] = "../client/imgs/Tanks/missile.png";

//---------------------HUD---------------------
const char hudPath[] = "../client/imgs/Gui/hud.png";
const char carasPath[] = "../client/imgs/Gui/unidades.png";
const char robotsLabelPath[] = "../client/imgs/Gui/robot_labels.png";
const char vehiculosLabelPath[] = "../client/imgs/Gui/vehiculos_labels.png";
const char vehiculosPath[] = "../client/imgs/Gui/vehiculos.png";
const char armasPath[] = "../client/imgs/Gui/armas.png";



//----------------GUI EDIFICIO ---------------
const char guiEdificioPath[] = "../client/imgs/Gui/edificio.png";

const char fuentePath[] = "../client/ttf/AUDIMRG_.TTF";


//--------------MISC----------------------
const char greeterPath[] = "../client/imgs/greeting.txt";

#endif //TPFINAL_CONSTANTES_H
