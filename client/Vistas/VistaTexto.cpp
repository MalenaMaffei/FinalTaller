#include "../Header Files/VistaTexto.h"
#include "../Header Files/constantes.h"
#include "../Header Files/Punto.h"
#include <string>

VistaTexto::VistaTexto(SDL_Renderer *gRenderer) : Texture(gRenderer) {}

bool VistaTexto::loadFont(std::string fontPath, int fontSize) {
    bool success = true;

    gFont = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (gFont == NULL){
        printf("No se pudo cargar la fuente SDL_ttf Error: %s\n", TTF_GetError
            ());
        success = false;
    }

    return success;
}

void VistaTexto::mostrar(std::string texto, SDL_Color color, Punto p) {
    if( NULL == gFont ){
        printf("se va a intentar imprimir ocn una null fonr\n");
    }
    if (loadFromRenderedText(texto, color, gFont)){
        render(p.x, p.y);
    } else {
        printf("No se pudo renderizar el texto\n");
//        TODO lanzar excep? O dejar que el juego siga sin texto?
    }
}

VistaTexto::~VistaTexto() {
    //Free loaded images
    free();
        //Quit SDL subsystems
//    TTF_Quit();
}

void VistaTexto::closeFont() {
    //Free global font
    printf("se va a cerrar font\t");
    TTF_CloseFont(gFont);
    gFont = NULL;
    printf("se cerrp font\n");
}
