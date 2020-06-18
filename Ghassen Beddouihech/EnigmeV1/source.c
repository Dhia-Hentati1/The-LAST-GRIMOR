/**

*	\file source.c
*	\author ghassen 


*/




#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"
#include <time.h>

/**
*	\brief	initialisation  de partage d'ecran 
*	\param	nameofpicture  le nom de l'image 
*	\param	x entier 
*	\param	y  entier 
*	\return  image 
*/
image initialisation(char nameofpicure[70],int x,int y)
{
    image image;
    image.img=IMG_Load(nameofpicure);
    image.posimg.x=x;
    image.posimg.y=y;
    return image;
}

/**
*	\brief	Affichage des image 
*	\param	ecran pointeur 
*	\param	image sturct 


*/
void affichage(SDL_Surface *ecran,image image)
{
    SDL_BlitSurface(image.img,NULL,ecran,&image.posimg);
}
/**
*	\brief	Donner un entier aleatoirement 
*	\param	nb entier 
*	\return nb



*/
int random_nbr(int nb)
{
    srand(time(NULL));
    nb=rand() % 2 + 1;
    return nb;
}



