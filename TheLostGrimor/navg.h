#pragma once

typedef struct Navg {
	SDL_Surface **screen, *bg, *img,*img1,*img2,*img3,*per1,*per2,*perso1,*perso2;
	SDL_Rect pos,pos1,pos2,pos3,p1,p2,p11,p12;
	SDL_Color rouge,noire,gold;
	TTF_Font *font;
	Mix_Music *bgm;
	int choixMenu,choixMenu2;
	int enabled,enabled2;
} Navg;

void NAVG_Init(Navg *navg, SDL_Surface **screen);
void NAVG_Render(Navg *navg);
void NAVG_HandleEvent(Navg *navg, SDL_Event *event);
