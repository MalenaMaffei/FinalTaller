/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
// #include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 8;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;
#define SPRITE_SIZE 32
//Texture wrapper class


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Walking animation
const int WALKING_ANIMATION_FRAMES = 3;
SDL_Rect gSpriteClipsTank[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTextureTank(nullptr);

SDL_Rect gSpriteClipsDiag[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTextureDiag(nullptr);

SDL_Rect gSpriteClipsBird[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTextureBird(nullptr);

SDL_Rect gSpriteClipsExpd[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTextureEp(nullptr);

SDL_Rect gSpriteClipsGrass[ 1 ];
LTexture gSpriteSheetTextureGrass(nullptr);

SDL_Rect gSpriteClipsCrater[ 1 ];
LTexture gSpriteSheetTextureCrater(nullptr);


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteSheetTextureTank.loadFromFile( "tank.png" ) ){
		printf( "Failed to load tank animation texture!\n" );
		success = false;
		return success;
	}
	if( !gSpriteSheetTextureBird.loadFromFile( "bird.png" ) ){
		printf( "Failed to load bird animation texture!\n" );
		success = false;
		return success;
	}
	if( !gSpriteSheetTextureGrass.loadFromFile( "grass.bmp" ) ){
		printf( "Failed to load grass texture!\n" );
		success = false;
		return success;
	}
	if( !gSpriteSheetTextureCrater.loadFromFile( "crater.png" ) ){
		printf( "Failed to load crater texture!\n" );
		success = false;
		return success;
	}
	if( !gSpriteSheetTextureDiag.loadFromFile( "diag.png" ) ){
		printf( "Failed to load diag animation texture!\n" );
		success = false;
		return success;
	}

	else
	{
		int col = 0;
		for (size_t j = 0; j < 3; j++) {
			gSpriteClipsTank[ j ].x =   col;
			gSpriteClipsTank[ j ].y =   0;
			gSpriteClipsTank[ j ].w =  32;
			gSpriteClipsTank[ j ].h = 96;

			gSpriteClipsDiag[ j ].x =   col;
			gSpriteClipsDiag[ j ].y =   0;
			gSpriteClipsDiag[ j ].w =  32;
			gSpriteClipsDiag[ j ].h = 96;

			gSpriteClipsBird[ j ].x =   col;
			gSpriteClipsBird[ j ].y =   0;
			gSpriteClipsBird[ j ].w =  32;
			gSpriteClipsBird[ j ].h = 32;

			col += 32;

			// printf("frame: %i\n", frame);
			// ++frame;
		}
		gSpriteClipsGrass[ 0 ].x =   0;
		gSpriteClipsGrass[ 0 ].y =   0;
		gSpriteClipsGrass[ 0 ].w =  32;
		gSpriteClipsGrass[ 0 ].h = 32;

		gSpriteClipsCrater[ 0 ].x =   0;
		gSpriteClipsCrater[ 0 ].y =   0;
		gSpriteClipsCrater[ 0 ].w =  32;
		gSpriteClipsCrater[ 0 ].h = 32;

	}

	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTextureTank.free();
	gSpriteSheetTextureDiag.free();
	gSpriteSheetTextureBird.free();
	gSpriteSheetTextureGrass.free();
	gSpriteSheetTextureCrater.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}




int main( int argc, char* args[] )
{

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() ){
			printf( "Failed to load media!\n" );
		}
		else{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
			//The frames per second timer
			LTimer fpsTimer;

			//The frames per second cap timer
			LTimer capTimer;
			//Current animation frame
			int frame = 0;

			//While application is running
			int i =1;
			int pos = 213;
			while( !quit )
			{
				capTimer.start();
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render current frame
				SDL_Rect* currentClipTank = &gSpriteClipsTank[ frame / 4 ];
				SDL_Rect* currentClipDiag = &gSpriteClipsDiag[ frame / 4 ];
				SDL_Rect* currentClipBird = &gSpriteClipsBird[ frame / 4 ];
				SDL_Rect* currentClipGrass = &gSpriteClipsGrass[0];
				SDL_Rect* currentClipCrater = &gSpriteClipsCrater[0];

				for (int x = 0; x < (SCREEN_WIDTH / SPRITE_SIZE); x++) {
					for (int y = 0; y < SCREEN_HEIGHT / SPRITE_SIZE; y++) {
						// rcGrass.x = x * SPRITE_SIZE;
						// rcGrass.y = y * SPRITE_SIZE;
						// SDL_BlitSurface(grass, NULL, screen, &rcGrass);
						if(x==y){
							gSpriteSheetTextureCrater.render(  x * SPRITE_SIZE, y * SPRITE_SIZE, currentClipCrater );
						} else{
							gSpriteSheetTextureGrass.render( x * SPRITE_SIZE, y * SPRITE_SIZE, currentClipGrass );

						}
					}
				}

				pos = (i%42)*15;
				gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
				gSpriteSheetTextureDiag.render( pos, pos, currentClipDiag );
				gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
				++i;

				//Update screen
				SDL_RenderPresent( gRenderer );

				//Go to next frame
				++frame;

				//Cycle animation
				if( frame / 4 >= WALKING_ANIMATION_FRAMES ){
					frame = 0;
				}

				int frameTicks = capTimer.getTicks();
				if( frameTicks < SCREEN_TICK_PER_FRAME ){
					//Wait remaining time
					SDL_Delay( SCREEN_TICK_PER_FRAME - frameTicks );
				}
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
