#ifndef __GRAVITATION_H_
#define __GRAVITATION_H_
#include <SDL.h>

/**
 * @brief Definition d'une structure de planet
 * 
 */
typedef struct planet
{
    float x; //position x 
    float y; //position y
    float x_vel; //Velocity in x
    float y_vel; //Velocity in y
    int rayon;

}planet;

/**
 * @brief Definition d'une structure de point
 * 
 */
typedef struct point
{
    float x,y;
}point;

typedef struct pointInt
{
    int x,y;
}pointInt;


point** allocPoint2(int ligne, int colonne);
void updateTracker(planet* t, point** p, int size, int j);
void affichageTracker(SDL_Renderer *renderer, point** p, int size, int nTrace);

planet* allocPlanet(int size);
void initPlanetAlea(planet* t, int size, int height, int width);
void initPlanetBySelection(planet* t, int size, int height, int width);
void updatePlanet(planet* t, int size);
void affichage(SDL_Renderer* renderer, planet* t, int size);


void centerOfMass(planet* t, int size, float* centerMassX, float* centerMassY);

void freePoint2(point** p, int colonne);

#endif