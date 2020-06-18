#pragma once
#include"menu3.h"
typedef struct Menu2 {
	SDL_Surface **screen, *bg, *msg;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	Mix_Music *bgm;
	int choixMenu;
	int enabled;
} Menu2;

void MENU2_Init(Menu2 *menu2, SDL_Surface **screen);
void MENU2_Render(Menu2 *menu2);
void MENU2_RenderFont(Menu2 *menu2, int x, int y, const char* text, int b);
void MENU2_HandleEvent(Menu2 *menu2, Menu3 *menu3, SDL_Event *event);
