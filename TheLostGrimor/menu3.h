#pragma once

typedef struct Menu3 {
	SDL_Surface **screen, *bg, *msg;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	Mix_Music *bgm;
	int choixMenu;
	int enabled;
} Menu3;

void MENU3_Init(Menu3 *menu3, SDL_Surface **screen);
void MENU3_Render(Menu3 *menu3);
void MENU3_RenderFont(Menu3 *menu3, int x, int y, const char* text, int b);
void MENU3_HandleEvent(Menu3 *menu3, Play *play, SDL_Event *event);
