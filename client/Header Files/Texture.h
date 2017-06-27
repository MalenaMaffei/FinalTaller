#ifndef TPFINAL_LTEXTURE_H
#define TPFINAL_LTEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <SDL2/SDL_ttf.h>
class Texture {
 public:
  explicit Texture(SDL_Renderer *gRenderer);

  ~Texture();

  bool loadFromFile(std::string path);
  bool loadFromRenderedText(std::string textureText,
                              SDL_Color textColor,
                              TTF_Font *gFont);
  void free();

  void render(int x, int y, SDL_Rect* clip = NULL);
//Set self as render target
  void setAsRenderTarget();
//  crea una textura vacia sin inicializar
  bool createBlank(int width, int height,
                   SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);
  int getWidth();
  int getHeight();
  void setBlendMode(SDL_BlendMode blending);

 protected:
  //The actual hardware texture
  SDL_Texture* mTexture;

  //Image dimensions
  int mWidth;
  int mHeight;
  SDL_Renderer* gRenderer;
};

#endif //TPFINAL_LTEXTURE_H
