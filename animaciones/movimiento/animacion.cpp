/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 8;
const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;
//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

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
LTexture gSpriteSheetTextureTank;

SDL_Rect gSpriteClipsBird[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTextureBird;

SDL_Rect gSpriteClipsExpd[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTextureEp;

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}

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
	}
	if( !gSpriteSheetTextureBird.loadFromFile( "bird.png" ) ){
		printf( "Failed to load bird animation texture!\n" );
		success = false;
	}
	else
	{
		int col = 0;
		for (size_t j = 0; j < 3; j++) {
			gSpriteClipsTank[ j ].x =   col;
			gSpriteClipsTank[ j ].y =   0;
			gSpriteClipsTank[ j ].w =  32;
			gSpriteClipsTank[ j ].h = 96;

			gSpriteClipsBird[ j ].x =   col;
			gSpriteClipsBird[ j ].y =   0;
			gSpriteClipsBird[ j ].w =  32;
			gSpriteClipsBird[ j ].h = 32;

			col += 32;

			// printf("frame: %i\n", frame);
			// ++frame;
		}

	}

	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTextureTank.free();
	gSpriteSheetTextureBird.free();

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

class LTimer
{
    public:
		//Initializes variables
		LTimer();

		//The various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks the status of the timer
		bool isStarted();
		bool isPaused();

    private:
		//The clock time when the timer started
		Uint32 mStartTicks;

		//The ticks stored when the timer was paused
		Uint32 mPausedTicks;

		//The timer status
		bool mPaused;
		bool mStarted;
};
LTimer::LTimer()
{
    //Initialize the variables
    mStartTicks = 0;
    mPausedTicks = 0;

    mPaused = false;
    mStarted = false;
}

void LTimer::start()
{
    //Start the timer
    mStarted = true;

    //Unpause the timer
    mPaused = false;

    //Get the current clock time
    mStartTicks = SDL_GetTicks();
	mPausedTicks = 0;
}

Uint32 LTimer::getTicks()
{
	//The actual timer time
	Uint32 time = 0;

    //If the timer is running
    if( mStarted )
    {
        //If the timer is paused
        if( mPaused )
        {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
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
				SDL_Rect* currentClipBird = &gSpriteClipsBird[ frame / 4 ];
				if (i == 1) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				} else if (i==2){
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==3) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==4) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==4) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==5) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==6) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==7) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==8) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==9) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==10) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==11) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					++i;
					pos+=15;
				}else if (i==12) {
					gSpriteSheetTextureTank.render( pos, ( SCREEN_HEIGHT - currentClipTank->h ) / 2, currentClipTank );
					gSpriteSheetTextureBird.render( pos, ( SCREEN_HEIGHT - currentClipBird->h ) / 2 -100, currentClipBird );
					i=1;
					pos = 213;
				}
				// gSpriteSheetTexture.render( ( SCREEN_WIDTH - currentClip->w ) / 2, ( SCREEN_HEIGHT - currentClip->h ) / 2, currentClip );

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
