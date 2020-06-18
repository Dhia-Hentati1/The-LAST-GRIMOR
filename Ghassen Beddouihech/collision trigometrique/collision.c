/**

*	\file collision.c
*	\author ghassen 


*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include "collision.h"

#define width 1360 
#define height 760

#define posXobj1 50 
#define posYobj1 50

#define posXobj2 300
#define posYobj2 80


/**
*	\brief	 initialisation objet 1 & 2 
*	\param	objet1  pointeur objet1
*	\param	objet2 pointeur objet2


*/
void init (Objet *objet1,Objet *objet2)
{
 objet1->img=IMG_Load("detective.png");
 objet1->pos.x=posXobj1 ;
 objet1->pos.y=posYobj1 ;

 objet2->img=IMG_Load("sapin.png") ;
 objet2->pos.x=posXobj2 ;
 objet2->pos.y=posYobj2 ;
}
/**
*	\brief	 affichage objet 1 & 2 
*	\param	screen 
*	\param	objet1  pointeur objet1
*	\param	objet2 pointeur objet2


*/
void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
 SDL_WM_SetCaption("collision trigo", NULL);
 SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
 SDL_BlitSurface(objet1->img,NULL,screen,&(objet1->pos)) ;
 SDL_BlitSurface(objet2->img,NULL,screen,&(objet2->pos)) ;
 SDL_Flip(screen) ;

}
/**
*	\brief	 calcule rayon 
*	\param	objet1  pointeur objet1
*	\param	objet2 pointeur objet2


*/
void calculer_centre_rayon (Objet *objet1,Objet *objet2)
{
 objet1->c.x=objet1->pos.x+ (objet1->img->w)/2 ;
 objet1->c.y=objet1->pos.y+ (objet1->img->h)/2 ;
 objet1->c.rayon=sqrt( pow( (objet1->img->w)/2 , 2) + pow( (objet1->img->h)/2 , 2) ) ;

 objet2->c.x=objet2->pos.x+ (objet2->img->w)/2 ;
 objet2->c.y=objet2->pos.y+ (objet2->img->h)/2 ;
 objet2->c.rayon=sqrt( pow( (objet2->img->w)/2 , 2) + pow( (objet2->img->h)/2 , 2) ) ;

}
/**
*	\brief	 calcule distance 
*	\param	objet1  pointeur objet1
*	\param	objet2 pointeur objet2


*/
float calculer_distance (Objet *objet1,Objet *objet2) 
{
  float D ;

  D=sqrt( pow( (objet1->c.x) - (objet2->c.x) ,2 ) + pow ( (objet1->c.y) - (objet2->c.y) , 2  ) ) ;

  return D ;
}
/**
*	\brief	 verification collision 
*	\param	objet1  pointeur objet1
*	\param	objet2 pointeur objet2
*	\param	D1 distance objet1


*/
int verif_collision ( Objet *objet1,Objet *objet2,float D1 )
{
  float D2 ;
  int collision=0 ;

  D2=objet1->c.rayon + objet2->c.rayon ;

  if(D1<=D2)
    collision= 1 ;
  
  return collision ;
}
/**
*	\brief	 deplacement   
*	\param	objet  pointeur 
*	\param	running entier 




*/
void deplacement_objet(Objet *objet,int *running)
{
  SDL_Event event ;


 
 SDL_WaitEvent(&event);
     switch(event.type)
      {
         case SDL_QUIT:
              *running=0;
         break;
         case SDL_KEYDOWN:
              switch(event.key.keysym.sym)
               {
                case SDLK_DOWN:
                    objet->pos.y+=10;
                break;
                case SDLK_UP:
                    objet->pos.y-=10;
                break;
                case SDLK_RIGHT:
                    objet->pos.x+=10;
                break;
                case SDLK_LEFT:
                    objet->pos.x-=10;
                break;
               }
      }
}
/**
*	\brief	 mise  a jour affichage 
*	\param	objet1  pointeur objet1
*	\param	objet2 pointeur objet2
*	\param	screen  pointeur 




*/
void update (SDL_Surface *screen,Objet *objet1,Objet *objet2)
{
  SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,255,255,255)) ;
  SDL_BlitSurface(objet1->img,NULL,screen,&(objet1->pos)) ;
  SDL_BlitSurface(objet2->img,NULL,screen,&(objet2->pos)) ;
  SDL_Flip(screen) ;
  
}
/**
*	\brief	 liberer memoire 
*




*/
void liberate_memory (Objet *objet1,Objet *objet2)
{
  SDL_FreeSurface (objet1->img) ;
  SDL_FreeSurface (objet2->img) ;
  SDL_Quit () ;
}
