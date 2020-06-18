#pragma once
#include"game.h"
typedef struct Savem {
	SDL_Surface **screen, *bg, *msg;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	//Mix_Music *bgm;
	int choixMenu;
	int enabled;
} Savem;

void Savem_Init(Savem *save, SDL_Surface **screen);
void Savem_Render(Savem *save);
void Savem_RenderFont(Savem *save, int x, int y, const char* text, int b);
void Savem_HandleEvent(Savem *save, Game *game, SDL_Event *event);
