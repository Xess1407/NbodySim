/**
 * @file menu.c
 * @author Clausse (clausseeva@gmail.eu)
 * @brief 
 * @version 0.1
 * @date 21-02-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Affichage du menu principal
 * 
 * @param renderer 
 * @param font 
 * @param height 
 * @param width 
 */
void menu(SDL_Renderer* renderer,TTF_Font *font, int height, int width){
    int texW = width, texH = height;
    SDL_Surface *texte = NULL;
    SDL_Texture * texture;

    SDL_Color colorWhite = {255, 255, 255};

    /*Titre*/
    texte = TTF_RenderText_Blended(font, "PROJET TIPE :", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectTitre = { texW/1.1, texH/2, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectTitre);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*Titre*/
    texte = TTF_RenderText_Blended(font, "Simulation de physique", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectTitre2 = { texW/2.4, texH*2, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectTitre2);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);


    /*DEMONSTRATION*/
    texte = TTF_RenderText_Blended(font, "Demo", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectBoutonDemo = { texW*2.8, texH*5, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectBoutonDemo);

    rectBoutonDemo.x -= 10;
    rectBoutonDemo.y -= 10;
    rectBoutonDemo.w += 65;
    rectBoutonDemo.h += 20;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderDrawRect(renderer, &rectBoutonDemo);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*2-Body*/
    texte = TTF_RenderText_Blended(font, "2-Body", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectBouton2 = { texW*2.4, texH*7, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectBouton2);

    rectBouton2.x -= 10;
    rectBouton2.y -= 10;
    rectBouton2.w += 40;
    rectBouton2.h += 20;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderDrawRect(renderer, &rectBouton2);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*3-Body*/
    texte = TTF_RenderText_Blended(font, "3-Body", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectBouton3 = { texW*2.4, texH*9, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectBouton3);

    rectBouton3.x -= 10;
    rectBouton3.y -= 10;
    rectBouton3.w += 40;
    rectBouton3.h += 20;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderDrawRect(renderer, &rectBouton3);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*4-Body*/
    texte = TTF_RenderText_Blended(font, "3-Body", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectBouton4 = { texW*2.4, texH*11, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectBouton4);

    rectBouton4.x -= 10;
    rectBouton4.y -= 10;
    rectBouton4.w += 40;
    rectBouton4.h += 20;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderDrawRect(renderer, &rectBouton4);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*Version*/
    texte = TTF_RenderText_Blended(font, "Version : 0.0.4 : stable", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectVersion = { 0, 0, texW/2, texH/2};
    SDL_RenderCopy(renderer, texture, NULL, &rectVersion);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*Fait par*/
    texte = TTF_RenderText_Blended(font, "Fait par : Evan, Remi, Anthony, Ugo, Hippolyte", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectFait = { 0, 700, texW*0.85, texH*0.85};
    SDL_RenderCopy(renderer, texture, NULL, &rectFait);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*Année*/
    texte = TTF_RenderText_Blended(font, "En 2021", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectAnnee = { 0, 750, texW*0.85, texH*0.85};
    SDL_RenderCopy(renderer, texture, NULL, &rectAnnee);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);
}

/**
 * @brief Affichage du menu pause
 * 
 * @param renderer 
 * @param font 
 * @param height 
 * @param width 
 */
void menuPause(SDL_Renderer* renderer,TTF_Font *font, int height, int width){
    int texW = width, texH = height;
    SDL_Surface *texte = NULL;
    SDL_Texture * texture;

    SDL_Color colorWhite = {255, 255, 255};

    /*Pause*/
    texte = TTF_RenderText_Blended(font, "Pause", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectTitre = { texW/1.1, texH/2, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectTitre);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*Reprendre*/
    texte = TTF_RenderText_Blended(font, "Reprendre", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectBoutonRep = { texW*2.8, texH*5, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectBoutonRep);

    rectBoutonRep.x -= 10;
    rectBoutonRep.y -= 10;
    rectBoutonRep.w += 65;
    rectBoutonRep.h += 20;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderDrawRect(renderer, &rectBoutonRep);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

    /*2-Body*/
    texte = TTF_RenderText_Blended(font, "Retour au menu", colorWhite);
    texture = SDL_CreateTextureFromSurface(renderer, texte);
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect rectBoutonRetour = { texW*2.4, texH*7, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &rectBoutonRetour);

    rectBoutonRetour.x -= 10;
    rectBoutonRetour.y -= 10;
    rectBoutonRetour.w += 40;
    rectBoutonRetour.h += 20;
    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
    SDL_RenderDrawRect(renderer, &rectBoutonRetour);

    SDL_FreeSurface(texte); 
    SDL_DestroyTexture(texture);

}