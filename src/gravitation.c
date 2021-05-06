/**
 * @file gravitation.c
 * @author Clausse (clausseeva@gmail.eu)
 * @brief 
 * @version 0.2
 * @date 19-02-2021
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "pythagore.h"
#include "geometry.h"

typedef struct planet
{
    float x; //position x 
    float y; //position y
    float x_vel; //Velocity in x
    float y_vel; //Velocity in y
    int rayon;

}planet;

/**
 * @brief Function that give a random number between 0 and max
 * 
 * @param max 
 * @return int 
 */
int aleaMax(int max){
    
    int alea = (rand() % max);
    return alea;
}

/**
 * @brief Function to allocate the memory for an array of planet
 * 
 * @param size 
 * @return planet* 
 */
planet* allocPlanet(int size){
    planet *t;

    t = malloc(sizeof(planet)* size);

    return t;
}

/**
 * @brief Procedure to initialise an array of planets
 * 
 * @param t 
 * @param size 
 * @param x_max 
 * @param y_max 
 * @param x_vel_max 
 * @param y_vel_max 
 */
void initPlanetAlea(planet* t, int size, int height, int width){

    for (int i = 0; i < size; i++){
        t[i].x = aleaMax(height-30)+30;
        t[i].y = aleaMax(width-30)+30;
        t[i].x_vel = 0;
        t[i].y_vel = 0;
        t[i].rayon = 20;
    }
}

/**
 * @brief Procedure to initialise an array of planets
 * 
 * @param t 
 * @param size 
 * @param x_max 
 * @param y_max 
 * @param x_vel_max 
 * @param y_vel_max 
 */
void initPlanetBySelection(planet* t, int size, int height, int width){
    int x,y,vx,vy,r;

    printf("Entrer les condition de depart de la simulation :\n");
    for (int i = 0; i < size; i++){
        printf("Entrer la position x de la planet %d : \n", i+1);
        scanf("%d", &x);
        printf("Entrer la position y de la planet %d : \n", i+1);
        scanf("%d", &y);
        printf("Entrer la vitesse en x de la planet %d : \n", i+1);
        scanf("%d", &vx);
        printf("Entrer la vitesse en y de la planet %d : \n", i+1);
        scanf("%d", &vy);
        printf("Entrer le rayon/massse de la planet %d : \n", i+1);
        scanf("%d", &r);

        t[i].x = x;
        t[i].y = y;
        t[i].x_vel = vx;
        t[i].y_vel = vy;
        t[i].rayon = r;
    }
    printf("\n");
}

void updatePlanet(planet* t, int size){
    float dis;
    double angle;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (j != i)
            {
                //Actualisation des formules
                dis = distance(t[i].x,t[i].y,t[j].x,t[j].y);
                angle = atan2(t[j].y-t[i].y,t[j].x-t[i].x);

                //Actualisation des vitesses
                t[i].x_vel += sqrt(t[j].rayon/dis) * cos(angle);
                t[i].y_vel += sqrt(t[j].rayon/dis) * sin(angle);
            }
        }
        //Actualisation des coordonnées
        t[i].x += t[i].x_vel;
        t[i].y += t[i].y_vel;
    }
}

/**
 * @brief Affichage des cercles
 * 
 * @param renderer 
 * @param t 
 * @param size 
 */
void affichage(SDL_Renderer* renderer, planet* t, int size){
    if (SDL_SetRenderDrawColor(renderer, 255,0,255, SDL_ALPHA_OPAQUE) != 0) 
                printf("Impossible de changer de couleur");

    for (int i = 0; i < size; i++){
        cercle(renderer, t[i].x, t[i].y, t[i].rayon);
    }   
}

/**
 * @brief Procedure that give the center of mass
 * 
 * @param t 
 * @param size 
 * @param centerMassX 
 * @param centerMassY 
 */
void centerOfMass(planet* t, int size, float* centerMassX, float* centerMassY){
    *centerMassX = 0;
    *centerMassY = 0;
    int rayonTotal = 0;
    for (int i = 0; i < size; i++)
    {
        *centerMassX += t[i].x*t[i].rayon;
        *centerMassY += t[i].y*t[i].rayon;
    }
    for (int i = 0; i < size; i++)
    {
        rayonTotal += t[i].rayon;
    }
    *centerMassX /= rayonTotal;
    *centerMassY /= rayonTotal;
}


typedef struct point
{
    float x,y;
}point;

point** allocPoint2(int ligne, int colonne){
    point** t;

    t = malloc(sizeof(point)*ligne);
    for (int i = 0; i < ligne; i++)
    {
        t[i] = malloc(sizeof(point) * colonne);
    }
    return t;
}

void updateTracker(planet* t, point** p, int size, int j){
    for (int i = 0; i < size; i++)
    {
      p[i][j].x = t[i].x;
      p[i][j].y = t[i].y;
    }
    
}

void affichageTracker(SDL_Renderer *renderer, point** p, int size, int nTrace){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < nTrace; j++)
        {
            SDL_RenderDrawPoint(renderer, p[i][j].x, p[i][j].y);
            //SDL_RenderDrawLine(renderer, p[i][j+1].x, p[i][j+1].y, p[i][j].x, p[i][j].y);
            
        }
    }
}

void freePoint2(point** p, int colonne){
    for (int i = 0; i < colonne; i++)
    {
        free(p[i]);
    }
    free(*p);
}