#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<string.h>
#include"navg.h"

void NAVG_Init(Navg *navg, SDL_Surface **screen){
	navg->screen = screen;
	navg->bg = IMG_Load("menu2.jpg");
	navg->per1=IMG_Load("per1.png") ;
  navg->p1.x=0 ;
  navg->p1.y=0 ;
  
  navg->img1=IMG_Load("Souris.png") ;
  navg->pos1.x=0 ;
  navg->pos1.y=70 ;
  
  navg->img2=IMG_Load("Clavier.png") ;
  navg->pos2.x=0 ;
  navg->pos2.y=70 ;
  
  navg->img3=IMG_Load("Manette.png") ;
  navg->pos3.x=0 ;
  navg->pos3.y=70 ;
  
  navg->per2=IMG_Load("per2.png") ;
  navg->p2.x=0 ;
  navg->p2.y=0 ;
  
  navg->perso1=IMG_Load("perso1.png") ;
  navg->p11.x=0 ;
  navg->p11.y=0 ;
  
  navg->perso2=IMG_Load("perso2.png") ;
  navg->p12.x=0 ;
  navg->p12.y=0 ;

        
	navg->noire.r = navg->noire.g = navg->noire.b = 0;
	navg->choixMenu = 0;
	navg->enabled = 0;
	navg->choixMenu2 = 0;
	navg->enabled2 = 0;
}

void NAVG_Render(Navg *navg){
int continuer=1;
SDL_Event event;
	SDL_BlitSurface(navg->bg, NULL, *navg->screen, NULL);


	if (navg->choixMenu == 0)
	SDL_BlitSurface(navg->img2,NULL,*navg->screen,&navg->pos2);
	if (navg->choixMenu == 1)
	SDL_BlitSurface(navg->img3,NULL,*navg->screen,&navg->pos3);
	if (navg->choixMenu == 2)
	SDL_BlitSurface(navg->img1,NULL,*navg->screen,&navg->pos1);
	
	
	/*if(navg->choixMenu2 ==1)
        navg->per1=IMG_Load("per1.png") ;
        else
        navg->per2=IMG_Load("per2.png") ;
	while (continuer)
        {
            SDL_WaitEvent(&event);
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_UP: // Flèche haut
                    if (navg->choixMenu == 1)
                    {
                        navg->p2.y -= 2;
                    }

                    break;
                case SDLK_DOWN: // Flèche bas
                    if (navg->choixMenu == 1)
                        navg->p2.y += 2;
                    break;
                case SDLK_RIGHT: // Flèche droite
                    if (navg->choixMenu == 1)
                        navg->p2.x += 2;
                    break;
                case SDLK_LEFT: // Flèche gauche
                    if (navg->choixMenu == 1)
                        navg->p2.x -= 2;
                    break;
                }
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (navg->choixMenu == 3)
                {
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {

                        if (event.button.x <= 500 / 2)

                            navg->p2.x -= 20;
                        else
                            navg->p2.x += 20;
                    }
                }

                break;
            }
            }
	*/
	
}


void NAVG_HandleEvent(Navg *navg,SDL_Event *event){
Mix_Chunk *son;
son = Mix_LoadWAV("bt3.wav");
			if(event->type == SDL_KEYDOWN)
			{
				if(event->key.keysym.sym == SDLK_RIGHT){
					if(navg->choixMenu != 2){
						navg->choixMenu++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						navg->choixMenu = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_LEFT){
					if(navg->choixMenu != 0){
						
						Mix_PlayChannel(1, son, 0);
						navg->choixMenu--;}
					else {
						navg->choixMenu = 2;
						Mix_PlayChannel(1, son, 0); }
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(navg->choixMenu == 1){
						navg->enabled =1 ;
						
					}
					
				}
				/*if(event->key.keysym.sym == SDLK_ESCAPE){
					navg->enabled = 0;
				}}
				
				if(event->type == SDL_KEYDOWN){
				if(event->key.keysym.sym == SDLK_RIGHT){
					if(navg->choixMenu2 != 1){
						navg->choixMenu2++;
						
						Mix_PlayChannel(1, son, 0);}
					else {
						navg->choixMenu2 = 0;
						Mix_PlayChannel(1, son, 0);}
				}
				if(event->key.keysym.sym == SDLK_LEFT){
					if(navg->choixMenu2 != 0){
						
						Mix_PlayChannel(1, son, 0);
						navg->choixMenu2--;}
					/*else {
						navg->choixMenu2 = 2;
						Mix_PlayChannel(1, son, 0); }*
				}

				if(event->key.keysym.sym == SDLK_RETURN){
					if(navg->choixMenu2 == 1){
						navg->enabled2 =1 ;
						
					}
					
				}
				if(event->key.keysym.sym == SDLK_ESCAPE){
					navg->enabled2 = 0;
				}
			}*/

}}

