#pragma once



typedef struct Game {
	int running;
	SDL_Surface *screen;
	
	


} Game;

void GAME_Init(Game *game);
void GAME_Render(Game *game);
void GAME_HandleEvent(Game *game, SDL_Event *event);
