
/**

*	\file header.h
*	\author ghassen beddouihech 



*/



/**
*@ struct image 
*@ breif struct pour image enigme    
*/

typedef struct image
{
	SDL_Surface *img;
	SDL_Rect posimg; /*!position enigme! */
}image;


image initialisation(char nomimage[100],int x,int y);
void affichage(SDL_Surface *ecran,image img);
int random_nbr(int nb) ;
//void dice (image eq , int nb) ;




