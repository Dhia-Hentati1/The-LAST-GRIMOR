#pragma once
#include"navg.h"
typedef struct Settings {
	SDL_Surface **screen, *bg, *msg;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	Mix_Music *bgm;
	int choixMenu;
	int enabled;
} Settings;

void SETTINGS_Init(Settings *settings, SDL_Surface **screen);
void SETTINGS_Render(Settings *settings);
void SETTINGS_RenderFont(Settings *settings, int x, int y, const char* text, int b);
void SETTINGS_HandleEvent(Settings *settings,Navg *navg, SDL_Event *event);
