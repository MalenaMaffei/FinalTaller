#ifndef TPFINAL_LTEXTURE_H
#define TPFINAL_LTEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <SDL2/SDL_ttf.h>
#include "Logger.h"
class Texture {
 public:
  explicit Texture(SDL_Renderer *gRenderer);

  ~Texture();
//Crea una textura a partir de una imagen
  bool loadFromFile(std::string path);
//  Crea una textura a partir de un string y una fuente
  bool loadFromRenderedText(std::string textureText,
                              SDL_Color textColor,
                              TTF_Font *gFont);
  void free();

//  Muestra el clip pasado en la posicion pasada
  void render(int x, int y, SDL_Rect* clip = NULL);
//Para renderizar sobre la textura
  void setAsRenderTarget();
//  crea una textura vacia sin inicializar
  bool crearTexturaVacia(int width, int height,
                         SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);
  int getWidth();
  int getHeight();
//  Setea niveles de transparencia
  void setBlendMode(SDL_BlendMode blending);

 protected:
  SDL_Texture* mTexture;
  int mWidth;
  int mHeight;
  SDL_Renderer* gRenderer;
};

#endif //TPFINAL_LTEXTURE_H
