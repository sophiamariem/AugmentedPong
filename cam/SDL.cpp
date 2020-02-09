#include "SDL.h"
#include <iostream>
SDL_Surface* bitmap = NULL;
SDL_Surface* screen = NULL;

SDL_Event event;

SDL_Surface* OnLoad(char* File) {
	SDL_Surface* bit = NULL;
	SDL_Surface* pong = NULL;

	bit = SDL_LoadBMP(File);
	//bit =IMG_Load(File);

	if (bit == NULL) {
		return NULL;
	}

	pong = SDL_DisplayFormat(bit);
	SDL_FreeSurface(bit);



	return pong;
}


bool showBitmap(SDL_Surface* bitm, SDL_Surface* scr, int xcoord, int ycoord) {
	
	/*if(screen == NULL || bitmap == NULL) {
		return false;
	}
	*/
	SDL_Rect toscreen;

	toscreen.x = xcoord;
	toscreen.y = ycoord;

	SDL_BlitSurface(bitm, NULL, scr, &toscreen);

	return true;
}


bool OnDraw(SDL_Surface* bitm, SDL_Surface* scr, int xcoord, int ycoord, int xcoord2, int ycoord2, int width, int height) {
	/*if(bitmap == NULL || screen == NULL) {
		return false;
	}*/

	SDL_Rect toScreen;

	toScreen.x = xcoord;
	toScreen.y = ycoord;

	SDL_Rect SrcR;

	SrcR.x = xcoord2;
	SrcR.y = ycoord2;
	SrcR.w = width;
	SrcR.h = height;

	SDL_BlitSurface(bitm, &SrcR, scr, &toScreen);

	//SDL_Flip(screen);

	return true;
}



bool init()
{

    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;    
    }   
  

    screen = SDL_SetVideoMode(1000, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    	
	if(screen == NULL) {
		return false;
	}

    SDL_WM_SetCaption( "Testing...", NULL );
    
    return true;
}

bool loadImg(){
		//screen = SDL_LoadBMP("pong.bmp");
	
	bitmap=OnLoad( "pong.bmp" );
	
	if (bitmap == NULL){
		return false;}
	return true;
}

void clear(){
    SDL_FreeSurface(bitmap);
    SDL_Quit();    
}

int main( int argc, char* args[] )
{
	bool quit = false;

	
	if(init() == false)
        return 1;    


	if(loadImg() == false)
        return 1;    

	
	//showBitmap(bitmap, screen, 0, 0);
	OnDraw (bitmap, screen, 300, 200, 0, 0, 400, 200);

	
	 if( SDL_Flip(screen) == -1 )
        return 1;    
   
	
	while( quit == false )
	{
		while( SDL_PollEvent(&event ) )
		{
			if( event.type == SDL_QUIT )
				quit = true;
		}}
		

	clear();

	return 0;
}

