#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "enigme.h"
#include <time.h>


int continuer=1,xmotion=0,ymotion=0 ,time2 = 0 ;

//SDL_Event event1 ;


void ENIGME_Init(Enigme *e, SDL_Surface **screen)
{
    e->background = IMG_Load("enigme.png");
    e->pbackground.x = 0 ;
    e->pbackground.y = 0;
     e->question1   = IMG_Load("eq1/eq1.png");
    e->pquestion1.x = 0;
    e->pquestion1.y = 0;

      e->bouton1   = IMG_Load("eq1/eq1false.png");
    e->pbouton1.x = 150-35;
    e->pbouton1.y = 140;
    e->bouton2   = IMG_Load("eq1/eq1true.png");
    e->pbouton2.x = 150-35;
    e->pbouton2.y = 80;
//---------------------------------------------
   e->question2   = IMG_Load("eq2/eq2.png");
    e->pquestion2.x = 0 ;
    e->pquestion2.y = 0;

      e->bouton3   = IMG_Load("eq2/eq2false.png");
    e->pbouton3.x = 150-35 ;
    e->pbouton3.y = 140;
    e->bouton4   = IMG_Load("eq2/eq2true.png");
    e->pbouton4.x = 150-35 ;
    e->pbouton4.y = 80;
///---------------------------------------------------

     e->correct = IMG_Load("correct.png");
    e->pcorrect.x = 100 ;
    e->pcorrect.y = 170;
    e->fa  = IMG_Load("over.jpg");
    e->pfa.x = 0 ;
    e->pfa.y = 0;



}

void affichageEQ1(SDL_Surface **screen,Enigme *e)
{

SDL_BlitSurface(e->background,NULL,*screen,&e->pbackground) ;
SDL_BlitSurface(e->question1,NULL,*screen,&e->pquestion1) ;
SDL_BlitSurface(e->bouton1,NULL,*screen,&e->pbouton1) ;
SDL_BlitSurface(e->bouton2,NULL,*screen,&e->pbouton2) ;
}

void affichageEQ2(SDL_Surface **screen,Enigme *e)
{

SDL_BlitSurface(e->background,NULL,*screen,&e->pbackground) ;
SDL_BlitSurface(e->question2,NULL,*screen,&e->pquestion2) ;
SDL_BlitSurface(e->bouton3,NULL,*screen,&e->pbouton3) ;
SDL_BlitSurface(e->bouton4,NULL,*screen,&e->pbouton4) ;
}

int   random_nbr(int nb)
{
    srand(time(NULL));
    nb=rand() % 2 + 1;
return nb ;
}

void ENIGME_Render(Enigme *e, SDL_Surface **screen,int nb,SDL_Event *event)
{
int eq = 0  ;

nb =  random_nbr(nb) ;
//SDL_PollEvent(&event1);
//int nb = 0 ;
//random_nbr(&nb);

 switch(nb)
    {case 1 :
    eq = 1  ;
SDL_BlitSurface(e->background,NULL,*screen,&e->pbackground) ;
SDL_BlitSurface(e->question1,NULL,*screen,&e->pquestion1) ;
SDL_BlitSurface(e->bouton1,NULL,*screen,&e->pbouton1) ;
SDL_BlitSurface(e->bouton2,NULL,*screen,&e->pbouton2) ;
break ;
    case 2 :
    eq = 2  ;
SDL_BlitSurface(e->background,NULL,*screen,&e->pbackground) ;
SDL_BlitSurface(e->question2,NULL,*screen,&e->pquestion2) ;
SDL_BlitSurface(e->bouton3,NULL,*screen,&e->pbouton3) ;
SDL_BlitSurface(e->bouton4,NULL,*screen,&e->pbouton4) ;
   break  ;
   }//switchnb */

///-----------------------------------


      switch(eq)

      {
            case 1 :

            if (event->type == SDL_MOUSEBUTTONUP)

            if (event->button.button == SDL_BUTTON_LEFT)
        {
                if  ( ( (event->button.x > e->pbouton2.x) && (event->button.x < e->pbouton2.x + 102 )) && (event->button.y > e->pbouton2.y) && (event->button.y <  e->pbouton2.y + 43) )

                {

                SDL_BlitSurface(e->correct,NULL,*screen,&e->pcorrect) ;
                }
                else

               SDL_BlitSurface(e->fa,NULL,*screen,&e->pfa) ;

                }
                break ;

                case 2 :
                 if (event->type == SDL_MOUSEBUTTONUP)

            if (event->button.button == SDL_BUTTON_LEFT)
                {
                if  ( ( (event->button.x > e->pbouton4.x) && (event->button.x < e->pbouton4.x + 102 )) && (event->button.y > e->pbouton4.y) && (event->button.y <  e->pbouton4.y + 43) )

                {

                SDL_BlitSurface(e->correct,NULL,*screen,&e->pcorrect) ;

                }
                else

               SDL_BlitSurface(e->fa,NULL,*screen,&e->pfa) ;

                }
        break ;




//}

}//switch eq

}
