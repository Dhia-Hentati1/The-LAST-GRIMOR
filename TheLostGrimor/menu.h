#pragma once

#include"menu2.h"
#include"exit.h"

typedef struct Menu {
	SDL_Surface **screen, *bg,*a,*c,*d,*e,*jouer,*msg,*set,*quit;
      SDL_Rect posw,posw3,posw1,poswelcome,posbg,posjouer,posset,posquit;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	//Mix_Music *bgm,*bgm2;
        //*music,*music1,*music2,*music3;
       
	int choixMenu;
	int enabled;
} Menu;

void MENU_Init(Menu *menu, SDL_Surface **screen);
void MENU_Render(Menu *menu);
void MENU_HandleEvent(Menu *menu,Menu2 *menu2, Game *game,Settings *settings,Play *play,Credits *credits,Exit *exit, SDL_Event *event);
