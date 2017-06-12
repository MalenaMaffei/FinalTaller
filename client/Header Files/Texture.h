#ifndef TPFINAL_LTEXTURE_H
#define TPFINAL_LTEXTURE_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <SDL2/SDL_ttf.h>
class Texture
{
 public:
  //Initializes variables
  Texture(SDL_Renderer *gRenderer);

  //Deallocates memory
  ~Texture();

  //Loads image at specified path
  bool loadFromFile( std::string path );
  bool loadFromRenderedText(std::string textureText,
                              SDL_Color textColor,
                              TTF_Font *gFont);
  //Deallocates texture
  void free();

  //Set color modulation
  void setColor( Uint8 red, Uint8 green, Uint8 blue );


  //Set blending
  void setBlendMode( SDL_BlendMode blending );

  //Set alpha modulation
  void setAlpha( Uint8 alpha );

  //Renders texture at given coords
  void render( int x, int y, SDL_Rect* clip = NULL );

  //Gets image dimensions
  int getWidth();
  int getHeight();

 protected:
  //The actual hardware texture
  SDL_Texture* mTexture;

  //Image dimensions
  int mWidth;
  int mHeight;
  SDL_Renderer* gRenderer;
};



#endif //TPFINAL_LTEXTURE_H
