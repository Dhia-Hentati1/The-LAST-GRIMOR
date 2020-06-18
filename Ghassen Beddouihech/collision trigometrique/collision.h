/**

*	\file collision.h
*	\author ghassen beddouihech 



*/


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**

*	\struct  cercle 
*	\breif   structure  cercle 




*/
typedef struct 
{
  int x ;
  int y ;
  float rayon ;

}Circle;



/**

*	\struct  Objet
*	\breif   structure  Objet




*/
typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos; /*! position objet !*/
  Circle c ; /*! struct  cercle  !*/
  
}Objet;


void init (Objet *objet1,Objet *objet2) ;
void setup (SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
void calculer_centre_rayon (Objet *objet1,Objet *objet2) ;
float calculer_distance (Objet *objet1,Objet *objet2) ;
int verif_collision ( Objet *objet1,Objet *objet2,float D1 ) ;
void deplacement_objet(Objet *objet,int *running) ;
void update (SDL_Surface *screen,Objet *objet1,Objet *objet2) ;
void liberate_memory (Objet *objet1,Objet *objet2) ;
