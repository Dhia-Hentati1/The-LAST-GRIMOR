
/**

*	\file main.c
*	\breif pour tester le programme 
*	\verison  1
*	\author   ghassen beddouihech



*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"
#include <time.h>

int main()
{
    srand(time(NULL));
    int continuer=1,eq=0,xmotion=0,ymotion=0 ,nb=0, time=0 ;
    SDL_Event event;

    SDL_Surface *ecran =NULL;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) ;
    ecran = SDL_SetVideoMode(350,350, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    image background,question1,question2 , bouton1 , bouton2 , bouton3 , bouton4,correct,fa ;
    background=initialisation("enigme.png",0,0);
    question1=initialisation("eq1/eq1.png",0,0);
    question2=initialisation("eq2/eq2.png",0,0);
    bouton1=initialisation("eq1/eq1true.png",150-35,140) ;
    bouton2=initialisation("eq1/eq1false.png",150-35,80) ;
    bouton3=initialisation("eq2/eq2false.png",150-35,140) ;
    bouton4=initialisation("eq2/eq2true.png",150-35,80) ;
    correct=initialisation("correct.png",100,170) ;
    fa=initialisation("wrong.png",100,170) ;


//msg tmp


    nb=random_nbr(nb);

    switch(nb)
    {case 1 :
    eq = 1  ;
    affichage(ecran,background);
    affichage(ecran,question1);
    affichage(ecran,bouton1);
    affichage(ecran,bouton2);
    SDL_Flip(ecran);
    break ;
    case 2 :
    eq = 2  ;
    affichage(ecran,background);
    affichage(ecran,question2);
    affichage(ecran,bouton3);
    affichage(ecran,bouton4);
    SDL_Flip(ecran);
    break  ;
    }//switchnb

    while (continuer)
    {

     time=SDL_GetTicks() ;
    if(time==10000)
    continuer=0;


        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0;
            break;

        }






        switch(eq)
        {
        case 1 :
        if (event.type == SDL_MOUSEBUTTONUP)
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if( ( (event.button.x > bouton1.posimg.x) && (event.button.x < bouton1.posimg.x + 102 )) && (event.button.y > bouton1.posimg.y) && (event.button.y < bouton1.posimg.y + 43) )

                {
               ;
                    affichage(ecran,background);
                    affichage(ecran,question1);
                    affichage(ecran,bouton1);
                    affichage(ecran,bouton2);
                    affichage(ecran,correct) ;
                    SDL_Flip(ecran) ;

                }
            else
            {

                affichage(ecran,background);
                affichage(ecran,question1);
                affichage(ecran,bouton1);
                affichage(ecran,bouton2);
                affichage(ecran,fa) ;
                SDL_Flip(ecran);

            }
        break;
///---------EQ2-------///

       case 2 :
        if (event.type == SDL_MOUSEBUTTONUP)
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                if( ( (event.button.x > bouton4.posimg.x) && (event.button.x < bouton4.posimg.x + 102 )) && (event.button.y > bouton4.posimg.y) && (event.button.y < bouton4.posimg.y + 43) )

                {

                    affichage(ecran,background);
                    affichage(ecran,question2);
                    affichage(ecran,bouton3);
                    affichage(ecran,bouton4);
                    affichage(ecran,correct) ;
                    SDL_Flip(ecran) ;

                }
            else
            {

               affichage(ecran,background);
                affichage(ecran,question2);
                affichage(ecran,bouton3);
                affichage(ecran,bouton4);
                affichage(ecran,fa) ;
                SDL_Flip(ecran);

            }
        break;










            }//switchequation

    break ;





SDL_FreeSurface(background.img);
SDL_FreeSurface(question1.img);
SDL_FreeSurface(question2.img);
SDL_FreeSurface(bouton1.img);
SDL_FreeSurface(bouton2.img);
SDL_FreeSurface(bouton3.img);
SDL_FreeSurface(bouton4.img);
SDL_FreeSurface(correct.img);

SDL_Quit();


} // switch
}//while


}}
