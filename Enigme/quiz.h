	
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
typedef struct quiz 
{
 SDL_Surface * img;  
 SDL_Rect 	p; 
}quiz;

void QUIZ_Init (quiz *q) ;
void  afficherAlea  (SDL_Surface * screen  , char image [],quiz *q,int *alea) ;
int solutionQuiz2 (char image []);
int resolutionQuiz1 (int * running,int *run );
int resolutionQuiz2 (int * running,int *run );
void solutionQuiz1 (SDL_Surface * screen,char image [],int *x1,int *x2) ;
void afficherResultat(SDL_Surface * screen,int r2,int r1,quiz *qz,int x1,int x2);
