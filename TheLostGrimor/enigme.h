#ifndef ENIGME_H_INCLUDED
#define ENIGME_H_INCLUDED
typedef struct Enigme
{
	SDL_Surface *img,*background,*question1,*question2 , *bouton1 , *bouton2 , *bouton3 , *bouton4,*correct,*fa;

	SDL_Rect posimg,pbackground,pquestion1,pquestion2 , pbouton1 , pbouton2 ,pbouton3 , pbouton4,pcorrect,pfa;
}Enigme;

int   random_nbr(int nb) ;
Enigme initialisation(char nameofpicure[70],int x,int y) ;
void affichageEQ1(SDL_Surface **screen,Enigme *e);
void affichageEQ2(SDL_Surface **screen,Enigme *e);
void ENIGME_Init(Enigme *e, SDL_Surface **screen);
void ENIGME_Render(Enigme *e, SDL_Surface **screen,int nb,SDL_Event *event);


#endif // ENIGME_H_INCLUDED
