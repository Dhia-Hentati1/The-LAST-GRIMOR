#include<SDL/SDL.h>
#include"game.h"

void GAME_Init(Game *game){
	game->running = 1;
	game->screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE |SDL_DOUBLEBUF);
}
//1366.768
