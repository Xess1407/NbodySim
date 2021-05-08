/**
 * @file main.c
 * @author Clausse (clausseeva@gmail.eu)
 * @brief 
 * @version 0.0.4
 * @date 25-01-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 *     compilation windows: gcc src/"*.c" -Wall -lm  -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf 
 *     execute : .\bin\prog
 * 
 */

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "pythagore.h"
#include "geometry.h"
#include "gravitation.h"
#include "camera.h"
#include "demo.h"
#include "menu.h"

#define HEIGHT 800
#define WIDTH 800

/*SDL*/
void SDL_ExitWithError(const char *message);
SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;


int taille; //Nombre de corps/planet
const int nTrace = 125; //Nombre de point pour le tracer de l'orbit 
int type = 0; //Selection 
int aleaUser; //Choix de l'utilisateur entre condition aleatoire ou entrer
int count = 0;
short start = 0; //Verifie si c'est le 1 chargement (Pour free les listes)

/*Gestion du texte FPS*/
int texW = 0, texH = 0;
TTF_Font *font = NULL;
TTF_Font *fontTitle = NULL;
SDL_Surface *texteFPS = NULL;
SDL_Texture * texture;
char test[10];

/*Gestion des menus*/
int isMenuOn = 1;

/*Gestion des fps*/
int fps = 0, tick = 0, tickDepart = 0, tickArrivee = 0, difference = 0; 

// Image
SDL_Surface* iconSurface = NULL;
SDL_Surface* fondSurface = NULL;

SDL_bool program_launched = SDL_TRUE;
SDL_Event event;
planet *tab = NULL;
camera cam;
point centerMass;

//Position de la souris
int x;
int y;


int main(int argc, char **argv){

    /*--------Initialisation--------*/
    //Initialisation de la seed (si on a besoin des condition de depart aleatoire)
    srand(time(NULL));

    //Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) SDL_ExitWithError("Initialisation SDL");
    
    //Initialisation de la SDL TTF
    if(TTF_Init() == -1) SDL_ExitWithError("Erreur d'initialisation de TTF_Init");

    //creation fenetre
    window = SDL_CreateWindow("N-Body simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, HEIGHT, WIDTH, SDL_WINDOW_SHOWN);
    if (window == NULL) SDL_ExitWithError("Creation fenetre");

    //Creation rendu
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) SDL_ExitWithError("Creation rendu echouee");

    //Recuperation de la police de caractere
    if((font = TTF_OpenFont("ressources/fonts/arial.ttf", 20)) == NULL)
        SDL_ExitWithError("Erreur de chargement de la police de caractere !\n");
    if((fontTitle = TTF_OpenFont("ressources/fonts/arial.ttf", 42)) == NULL)
        SDL_ExitWithError("Erreur de chargement de la police de caractere !\n");

    //Chargement de l'image de fond
    fondSurface = IMG_Load("ressources/img/fondEtoile.jpg");
    if (fondSurface == NULL) // Conversion de l'image en texture 
            printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());
        
    /*--------------------------*/

    tick = SDL_GetTicks();
    SDL_Color colorWhite = {255, 255, 255}; //Definition de la couleur blanc pour la police de caractere

    //boucle pour que le programme tourne 
    while(program_launched){
        tickDepart = SDL_GetTicks();

        /*--------gestion-evenement---------*/
        while(SDL_PollEvent(&event)){

            switch (event.type)
            {
            case SDL_QUIT: //Bouton quit
                    program_launched = SDL_FALSE;
                break;
            case SDL_MOUSEBUTTONDOWN : //Souris
                SDL_GetMouseState(&x, &y); //Recuperation des coord de la souris au moment du click

                if(isMenuOn){
                    if (x > 303 && x < 480 && y > 225 && y < 290){ //On verifie si le click est dans le bouton
                        type = 1;
                    }
                    else if (x > 305 && x < 480 && y > 320 && y < 385){
                        type = 2;
                    }
                    else if (x > 305 && x < 480 && y > 412 && y < 480){
                        type = 3;
                    }
                    else if (x > 305 && x < 480 && y > 508 && y < 575){
                        type = 4;
                    }

                    if (type == 0){ 

                    }else if (type == 1){
                        taille = 2; //Nombre de corps 2
                        tab = allocPlanet(taille);
                        initPlanetDemo1(tab, HEIGHT,WIDTH); //Chargement de la premiere demo
                        //Allocation pour la track de l'orbit
                        start = 1;
                        isMenuOn = 0;//On quit le menu
                    }else if (type > 1){
                        taille = type;
                        tab = allocPlanet(taille);
                        initPlanetAlea(tab, taille, HEIGHT, WIDTH);
                            //Allocation pour la track de l'orbit
                        start = 1;
                        isMenuOn = 0; //On quit le menu
                    }
                    type = 0;
                }
                break;
                case SDL_KEYDOWN :
                    switch (event.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                    if (isMenuOn != 1){
                            isMenuOn = 1; //retour au menu si on n'y est pas deja
                    }
                        break;
                    default:
                        break;
                    }
                break;
            default :
                break;
            }
        }
        /*------------------------------*/


        // Permet de detruire ce qui a etait fait avant
        if (SDL_SetRenderDrawColor(renderer, 0,0,0, SDL_ALPHA_OPAQUE) != 0) 
            SDL_ExitWithError("Impossible de changer de couleur");
        SDL_RenderClear(renderer);

        /*Gestion de l'image de fond*/
        texture = SDL_CreateTextureFromSurface(renderer, fondSurface);
        SDL_Rect dest = {0, 0, 800, 800};
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        SDL_RenderCopy(renderer, texture, NULL, &dest);
        SDL_DestroyTexture(texture);
        
        if(isMenuOn){/*----Menu principal----*/
            menu(renderer, fontTitle, HEIGHT,WIDTH);   
        }else{/*----Simulation----*/

            //Ajustement du coefficient de deplacement, permet de garder le centre de masse au centre de l'ecran
            centerOfMass(tab, taille, &centerMass.x, &centerMass.y);
            cam.x = centerMass.x - (WIDTH/2);
            cam.y = centerMass.y - (HEIGHT/2);

            //Application du coefficient de deplacement
            for (int i = 0; i < taille; i++){
                tab[i].x -= cam.x;
                tab[i].y -= cam.y;
            }

            //Actualisation de la position des planetes
            updatePlanet(tab, taille);

            //Affichage des planete
            affichage(renderer, tab, taille);
            
            /*--------Gestion-FPS--------*/

            if (SDL_GetTicks() < tick + 1000){
                fps++;
            }else{
                sprintf(test, "FPS : %d", fps);
                tick = SDL_GetTicks();
                fps = 0;
            }
            tickArrivee = SDL_GetTicks();
            difference = (tickArrivee - tickDepart) > 16 ? 16 : (tickArrivee - tickDepart);
            SDL_Delay(16-difference);

            /*--------------------------*/

            /*--------Gestion-du-texteFPS-FPS--------*/
            texteFPS = TTF_RenderText_Blended(font, test, colorWhite);
            texture = SDL_CreateTextureFromSurface(renderer, texteFPS);
            SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
            SDL_Rect dstrect = { 0, 0, texW, texH };
            SDL_RenderCopy(renderer, texture, NULL, &dstrect);

            SDL_FreeSurface(texteFPS); 
            //SDL_DestroyTexture(texture);

            /*--------------------------*/
        } 

        SDL_RenderPresent(renderer); //Actualise la fenetre
        SDL_DestroyTexture(texture);
        texture = NULL;
    }
    
    /*--------Liberation de la memoire et arret des librairies--------*/
    SDL_FreeSurface(fondSurface);
    SDL_DestroyRenderer(renderer);
    TTF_CloseFont(font);
    TTF_CloseFont(fontTitle);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(texteFPS); 
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
    free(tab);
    return EXIT_SUCCESS;
}

//procedure d'erreur pour la SDL
void SDL_ExitWithError(const char *message){
    SDL_Log("Erreur : %s -> %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}