/**

*	\file multi.c
*	\author ghassen 
*	\version 1.0

*/
#include "multi.h"
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>


/**
*	\brief	partage_ecran initialisation de partage d'ecran 
*	\param	screen pointeur 
*	\param	e  pointeur struct ecran 
*/
void partage_ecran(SDL_Surface *screen ,ecran *e )
{

e->bg = IMG_Load("mapofficel.png");
e->topclip.x = 0 ;
e->topclip.y = 200-60 ; //200
e->topclip.w = 7500 ;
e->topclip.h = 300 ;
e->topclippos.x = 0 ;
e->topclippos.y = 0 ;
//------------------------
e->botclio.x=0;
e->botclio.y=200; //200
e->botclio.w=7500;
e->botclio.h=300;
e->botclippos.x = 0 ;
e->botclippos.y = 300  ;
}

/**
*	\brief	Affichage de topclip et botclip 
*	\param	screen pointeur 
*	\param	e  pointeur struct ecran 
*/
void affichage (SDL_Surface *screen ,ecran *e )
{

SDL_BlitSurface(e->bg,&e->botclio,screen,&e->botclippos);
SDL_BlitSurface(e->bg,&e->topclip,screen,&e->topclippos);

}

/**
*	\brief	initilisation des perso 
*	\param	screen pointeur 
*	\param	e  pointeur struct ecran 
*	\param	p  pointeur struct Perso
*/
void initialiserperso(SDL_Surface *screen , Perso *p,ecran *e)
{
    p->pe1 = IMG_Load("silva.png");
    p->pe2 = IMG_Load("silva.png");
    p->pos1.x = 0 ;
    p->pos1.y = 300-150 ;
    p->pos2.x = 0 ;
    p->pos2.y = 300+120 ;
    }

/**
*	\brief	affichage des personnages 1 et 2 
*	\param	screen pointeur 
*	\param	e  pointeur struct ecran 
*	\param	p  pointeur struct Perso
*/
void affichageperso(SDL_Surface *screen , Perso *p,ecran *e)
{
SDL_BlitSurface(p->pe1,NULL,screen,&p->pos1);
SDL_BlitSurface(p->pe2,NULL,screen,&p->pos2);
}

/**
*	\brief	deplacement des personnages 1 et 2 
*	\param	screen pointeur 
*	\param	e  pointeur struct ecran 
*	\param	p  pointeur struct Perso
*/
void deplacement(SDL_Surface *screen , Perso *p , ecran *e , SDL_Event *event )
{


			if(event->type == SDL_KEYDOWN) {
			if(event->key.keysym.sym == SDLK_RIGHT) {
					p->pos1.x += 5;
				}
				if(event->key.keysym.sym == SDLK_LEFT) {
					p->pos1.y -= 5;
				}
				if(event->key.keysym.sym == SDLK_d) {
					p->pos2.x += 5;
				}
				if(event->key.keysym.sym == SDLK_s) {
                        p->pos2.y -= 5;
				}
			}
		}

/**
*	\brief	scrolling 
*	\param	screen pointeur 
*	\param	e  pointeur struct ecran 
*	\param	p  pointeur struct Perso
*/
void scrolling(SDL_Surface *screen , Perso *p , ecran *e)
{


        e->topclip.x = p->pos1.x - 384;
		if(e->topclip.x < 0)
			e->topclip.x = 0;
		if(e->topclip.x > 7100)
			e->topclip.x = 7100;

		e->botclio.x = p->pos2.x - 384;
		if(e->botclio.x  < 0)
			e->botclio.x  = 0;
		if(e->botclio.x  > 7100)
			e->botclio.x  = 7100;

}




