#include "../Header Files/VistaTexto.h"
#include "../Header Files/constantes.h"
#include "../Header Files/Punto.h"
#include <string>

VistaTexto::VistaTexto(SDL_Renderer *gRenderer) : Texture(gRenderer) {}

void VistaTexto::loadFont(std::string fontPath, int fontSize) {
    gFont = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (gFont == NULL){
        Logger* logger = Logger::getInstancia();
        logger->logACerr("No se pudo cargar la fuente SDL_ttf Error: "
                                  "" + std::string(TTF_GetError()));
    }
}

void VistaTexto::mostrar(std::string texto, SDL_Color color, Punto p) {
    Logger* logger = Logger::getInstancia();

    if (NULL == gFont){
        logger->logACerr("se va a intentar imprimir con una null font");
    }
    if (loadFromRenderedText(texto, color, gFont)){
        render(p.x, p.y);
    } else {
        logger->logACerr("No se pudo renderizar el texto");
    }
}

VistaTexto::~VistaTexto() {
    free();
}

void VistaTexto::closeFont() {
    TTF_CloseFont(gFont);
    gFont = NULL;
}
