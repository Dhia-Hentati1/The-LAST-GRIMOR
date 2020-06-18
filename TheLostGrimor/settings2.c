#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"play.h"
#include"settings2.h"
#include"navg.h"

void SETTINGS_Init(Settings *settings, SDL_Surface **screen){
	settings->screen = screen;
	settings->bg = IMG_Load("menu2.jpg");
	settings->font = TTF_OpenFont("theme.ttf",86);

	settings->rouge.r = 217;
	settings->rouge.g = 10;
	settings->rouge.b = 4;

	settings->gold.r = 251;
	settings->gold.g = 208;
	settings->gold.b = 119;	

	settings->noire.r = settings->noire.g = settings->noire.b = 0;
	settings->choixMenu = 0;
	settings->enabled = 0;
}

void SETTINGS_Render(Settings *settings){
	SDL_BlitSurface(settings->bg, NULL, *settings->screen, NULL);


	SETTINGS_RenderFont(settings,260,250,"AUDIO",settings->choixMenu == 0);
	SETTINGS_RenderFont(settings,150,420,"NAVIGATION", settings->choixMenu == 1);
	
}

void SETTINGS_RenderFont(Settings *settings, int x, int y, const char* text, int b){
	SDL_Rect r;
	r.x = x;
	r.y = y;
	settings->msg = TTF_RenderText_Solid(settings->font,text,settings->noire);
	SDL_BlitSurface(settings->msg,NULL,*settings->screen,&r);
	r.x -= 7;
	r.y += 7;
	if(!b)
		settings->msg = TTF_RenderText_Solid(settings->font,text,settings->rouge);
	else 
		settings->msg = TTF_RenderText_Solid(settings->font,text,settings->gold);
	SDL_BlitSurface(settings->msg,NULL,*settings->screen,&r);
}

void SETTINGS_HandleEvent(Settings *settings,Navg *navg,SDL_Event *event){
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_DOWN){
					if(settings->choixMenu != 1){
						settings->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						settings->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_UP){
					if(settings->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						settings->choixMenu--;}
					else {
						settings->choixMenu = 1;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(settings->choixMenu == 1){
						navg->enabled =1 ;
						
					}
					/*if(settings->choixMenu == 0){
						settings->enabled = 0;
						
						
					}*/
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					settings->enabled = 0;
				}
			}

}

