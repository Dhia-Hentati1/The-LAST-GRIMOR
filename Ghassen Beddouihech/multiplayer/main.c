/**

*	\file main.c
*	\breif pour tester le programme 
*	\verison  1
*	\author   ghassen beddouihech



*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "multi.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface *screen ;
SDL_Event event ;
ecran e ;
Perso  p ;
int running = 1 ;
screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
initialiserperso(screen,&p,&e) ;
SDL_EnableKeyRepeat(10,10);
while(running)
{

while(SDL_PollEvent(&event)){
if(event.type == SDL_QUIT)
{
        running = 0;
}
else
{
partage_ecran(screen,&e) ;

deplacement(screen ,&p ,&e,&event) ;

affichage (screen,&e) ;
affichageperso(screen ,&p,&e) ;



}







SDL_Flip(screen);
SDL_Delay(16) ;
}// pollevent
}



SDL_FreeSurface(screen);
	SDL_Quit();
}
