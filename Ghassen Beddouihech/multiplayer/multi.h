/**

*	\file multi.h



*/
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/**
*@ struct Ecran
*@ breif struct pour ecran   
*/

typedef struct Ecran
{
    SDL_Surface *bg ;
    SDL_Rect topclip ; /*!postition rectangle topclip!*/
    SDL_Rect topclippos; /*!postition de topclip!*/

    SDL_Rect botclio ; /*!postition rectangle botclip!*/
    SDL_Rect botclippos ; /*!postition botclip!*/

} ecran ;

/**
*@ struct Perso
*@ struct pour coordonnees des perso 
*/
typedef struct Perso
{
SDL_Surface *pe1,*pe2 ;
SDL_Rect  pos1; /*!postition  perso 1*/
SDL_Rect pos2 ; /*!postition  perso  2*/

} Perso ;

void partage_ecran(SDL_Surface *screen ,ecran *e ) ;
void affichage (SDL_Surface *screen ,ecran *e ) ;
void initialiserperso(SDL_Surface *screen , Perso *p,ecran *e) ;
void affichageperso(SDL_Surface *screen , Perso *p,ecran *e) ;
void deplacement(SDL_Surface *screen , Perso *p , ecran *e,SDL_Event *event ) ;
void scrolling(SDL_Surface *screen , Perso *p , ecran *e) ;




