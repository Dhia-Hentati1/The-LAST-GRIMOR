#pragma once
#include"game.h"
typedef struct Exit {
	SDL_Surface **screen, *bg, *msg;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	//Mix_Music *bgm;
	int choixMenu,ex;
	int enabled;
} Exit;

void EXIT_Init(Exit *exit, SDL_Surface **screen);
void EXIT_Render(Exit *exit);
void EXIT_RenderFont(Exit *exit, int x, int y, const char* text, int b);
void EXIT_HandleEvent(Exit *exit, Game *game, SDL_Event *event);
