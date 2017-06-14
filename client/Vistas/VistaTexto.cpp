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
    if (loadFromRenderedText(texto, color, gFont)){
        render(p.x, p.y);
    } else {
        printf("No se pudo renderizar el texto\n");
//        TODO lanzar excep
    }
}

VistaTexto::~VistaTexto() {
    //Free loaded images
    free();

    //Free global font
    TTF_CloseFont(gFont);
    gFont = NULL;

    //Quit SDL subsystems
    TTF_Quit();
}

