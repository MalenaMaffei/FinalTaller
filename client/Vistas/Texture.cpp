#include "../Header Files/Texture.h"
#include "SDL2/SDL_ttf.h"
#include <string>
Texture::Texture(SDL_Renderer *gRenderer) : gRenderer(gRenderer) {
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture(){
    free();
}

bool Texture::loadFromFile(std::string path){
    free();

    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL){
        printf("No se pudo cargar la imagen: %s. SDL_image Error: %s\n", path
            .c_str(), IMG_GetError());
    } else{
        SDL_SetColorKey(loadedSurface, SDL_TRUE,
                        SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL){
            printf("No se pudo crear textura de imagen: %s. SDL Error: %s\n",
                    path.c_str(), SDL_GetError());
        }else{
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }

    mTexture = newTexture;
    return mTexture != NULL;
}


bool Texture::loadFromRenderedText(std::string textureText,
                                   SDL_Color textColor,
                                   TTF_Font *gFont) {
    free();

    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(),
                                                    textColor);
    if (textSurface == NULL){
        printf("No se pudo renderizar el texto: SDL_ttf Error: %s\n",
                TTF_GetError());
    } else {
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (mTexture == NULL){
            printf("No se pudo crear textura del texto renderizado: SDL "
                        "Error: %s\n", SDL_GetError());
        } else {
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        SDL_FreeSurface(textSurface);
    }

    return mTexture != NULL;
}



void Texture::free(){
    //Free texture if it exists
    if (mTexture != NULL){
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y, SDL_Rect* clip){
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };

    if (clip != NULL){
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

int Texture::getWidth(){
    return mWidth;
}

int Texture::getHeight(){
    return mHeight;
}

void Texture::setAsRenderTarget() {
    SDL_SetRenderTarget(gRenderer, mTexture);
}

bool Texture::createBlank(int width, int height, SDL_TextureAccess access) {
    //Create uninitialized texture
    mTexture = SDL_CreateTexture( gRenderer, SDL_PIXELFORMAT_RGBA8888, access, width, height );
    if(mTexture == NULL) {
        printf("Unable to create blank texture! SDL Error: %s\n", SDL_GetError());
    }
    else {
        mWidth = width;
        mHeight = height;
    }

    return mTexture != NULL;
}
void Texture::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode( mTexture, blending );
}
