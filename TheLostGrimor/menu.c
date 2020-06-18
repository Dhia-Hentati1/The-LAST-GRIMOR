#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"settings2.h"
#include"credits.h"
#include"play.h"
#include"game.h"
#include"menu.h"
#include"menu2.h"

void MENU_Init(Menu *menu, SDL_Surface **screen){
int x=0;
Mix_Chunk *bgm,*bgm2;
	menu->screen = screen;
	menu->a = IMG_Load("w.png");
        menu->c = IMG_Load("w1.png");
        menu->d = IMG_Load("w3.png");
        menu->e = IMG_Load("welcome.jpg");
        menu->bg = IMG_Load("menujeu.png");
        menu->jouer=IMG_Load("menu play.png");
        menu->set=IMG_Load("menu settings.png");
        menu->quit=IMG_Load("menu quit.png");

menu->posw.x=0;
menu->posw.y=200;
menu->posw1.x=0;
menu->posw1.y=200;
menu->poswelcome.w=menu->e->w;
menu->poswelcome.h=menu->e->h;
menu->posw3.x=0;
menu->posw3.y=200;

bgm=Mix_LoadWAV("bar.wav");
//bgm2=Mix_LoadWAV("deathnote.wav");
	
	Mix_PlayChannel(1,bgm,0);
SDL_BlitSurface(menu->a,NULL,*menu->screen,&menu->posw);
SDL_Flip(*menu->screen);
SDL_Delay(850);
SDL_BlitSurface(menu->c,NULL,*menu->screen,&menu->posw1);
SDL_Flip(*menu->screen);
SDL_Delay(850);
SDL_BlitSurface(menu->d,NULL,*menu->screen,&menu->posw3);
SDL_Flip(*menu->screen);
SDL_Delay(850);
SDL_BlitSurface(menu->e,NULL,*menu->screen,&menu->poswelcome);
SDL_Flip(*menu->screen);
SDL_Delay(850);

SDL_BlitSurface(menu->bg,NULL,*menu->screen,&menu->posbg);

menu->posjouer.x=0;
menu->posjouer.y=0;
menu->posset.x=0;
menu->posset.y=0;
menu->posquit.x=0;
menu->posquit.y=0;

menu->choixMenu==0;


        Mix_PlayChannel(2,bgm2,-1);
	
	menu->enabled=1;

}
void MENU_Render(Menu *menu){
	SDL_BlitSurface(menu->bg, NULL, *menu->screen, NULL);
if (menu->choixMenu == 0)
         SDL_BlitSurface(menu->jouer,NULL,*menu->screen,&menu->posjouer);
if (menu->choixMenu == 1)
	SDL_BlitSurface(menu->set,NULL,*menu->screen,&menu->posset);
if (menu->choixMenu == 2)
	SDL_BlitSurface(menu->quit,NULL,*menu->screen,&menu->posquit);
}

void MENU_HandleEvent(Menu *menu,Menu2 *menu2, Game* game, Settings *settings,Play *play,Credits *credits,Exit *exit,SDL_Event *event){
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
switch(event->type)
{case SDL_MOUSEMOTION:
if((event->motion.x<247&&event->motion.x>82)&&(event->motion.y<291&&event->motion.y>205))
menu->choixMenu == 1;
break;}
			if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_DOWN){
					if(menu->choixMenu != 2){//3
						menu->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						menu->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_UP){
					if(menu->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						menu->choixMenu--;}
					else {
						menu->choixMenu = 2;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(menu->choixMenu == 2)
						exit->enabled =1;
					
					if(menu->choixMenu == 1)
						settings->enabled = 1;
					if(menu->choixMenu == 0)

						menu2->enabled = 1;
				}

			}

}
