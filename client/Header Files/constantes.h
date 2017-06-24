#ifndef TPFINAL_CONSTANTES_H
#define TPFINAL_CONSTANTES_H

//Tile constants
static const int TILE_WIDTH = 16;
static const int TILE_HEIGHT = 16;
static const int TILE_CLIPS = 8;
static const int TILESX = 400;
static const int TILESY = 400;

static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 600;
static const int LEVEL_WIDTH = TILESX*TILE_WIDTH;
static const int LEVEL_HEIGHT = TILESY*TILE_HEIGHT;



static const int COLORES = 4;

static const char tankPath[] = "../client/imgs/tank.png";
static const char tilePath[] = "../client/imgs/todosTiles.png";
static const char rocaPath[] = "../client/imgs/Rocas/roca_roca.png";
static const char hieloPath[] = "../client/imgs/Rocas/roca_hielo.png";
static const char balaPath[] = "../client/imgs/bala.png";
static const char fuertePath[] = "../client/imgs/Edificios/fuerte.png";
static const char fabricaVehiculosPath[] = ""
    "../client/imgs/Edificios/fabrica_vehiculos.png";
static const char fabricaRobotsPath[] = "../client/imgs/Edificios/fabrica_robots.png";
static const char puentePath[] = "../client/imgs/Puentes/bridge_city.png";
static const char banderaPath[] = "../client/imgs/Banderas/bandera.png";

//------------ROBOTS------------------
static const char robotCaminarPath[] = "../client/imgs/Robots/caminar_robot.png";
static const char robotPyroDisparar[] = "../client/imgs/Robots/disparo_pyro.png";
static const char robotGruntDisparar[] = "../client/imgs/Robots/disparo_grunt.png";
static const char robotToughDisparar[] = "."
    "./client/imgs/Robots/disparo_tough.png";
static const char robotLaserDisparar[] = "."
    "./client/imgs/Robots/disparo_laser.png";
static const char robotPsychoDisparar[] = "../client/imgs/Robots/disparo_psycho.png";
static const char robotSniperDisparar[] = "."
    "./client/imgs/Robots/disparo_sniper.png";
static const char robotMuertePath[] = "../client/imgs/Robots/muerte.png";

//------------VEHICULOS------------------
static const char heavyCaminarPath[] = "../client/imgs/Tanks/caminar_heavy.png";
static const char heavyDispararPath[] = "../client/imgs/Tanks/disparar_heavy.png";

static const char tanqueMuertePath[] = "../client/imgs/Tanks/explosion.png";
static const char tanqueMissilePath[] = "../client/imgs/Tanks/missile.png";

//---------------------HUD---------------------
static const char hudPath[] = "../client/imgs/Gui/hud.png";
static const char carasPath[] = "../client/imgs/Gui/unidades.png";
static const char robotsLabelPath[] = "../client/imgs/Gui/robot_labels.png";
static const char vehiculosLabelPath[] = "../client/imgs/Gui/vehiculos_labels.png";
static const char vehiculosPath[] = "../client/imgs/Gui/vehiculos.png";
static const char armasPath[] = "../client/imgs/Gui/armas.png";



//----------------GUI EDIFICIO ---------------
static const char guiEdificioPath[] = "../client/imgs/Gui/edificio.png";

static const char fuentePath[] = "../client/ttf/AUDIMRG_.TTF";


//--------------MISC----------------------
static const char greeterPath[] = "../client/imgs/greeting.txt";

#endif //TPFINAL_CONSTANTES_H
