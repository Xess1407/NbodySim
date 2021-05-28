/**
 * @file demo.c
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
#include "gravitation.h"

/**
 * @brief Procedure to initialise an array of planets for demo 
 * 
 * @param t 
 * @param height 
 * @param width
 */
void initPlanetDemo1(planet* t, int height, int width){

        t[0].x = width/8 + 5;
        t[0].y = height/8 + 5;
        t[0].x_vel = 10;
        t[0].y_vel = -10;
        t[0].rayon = 20;

        t[1].x = width/2;
        t[1].y = height/2;
        t[1].x_vel = 0;
        t[1].y_vel = 0;
        t[1].rayon = 70;
}

/**
 * @brief Procedure to initialise an array of planets for demo 
 * 
 * @param t 
 * @param height 
 * @param width
 */
void initPlanetDemo2(planet* t, int height, int width){

        t[0].x = width/2; //en haut
        t[0].y = height/4;
        t[0].x_vel = -10;
        t[0].y_vel = 0;
        t[0].rayon = 20;

        t[1].x = width/4; //a gauche
        t[1].y = height/2;
        t[1].x_vel = 0;
        t[1].y_vel = 10;
        t[1].rayon = 20;
}

/**
 * @brief Procedure to initialise an array of planets for demo 
 * 
 * @param t 
 * @param height 
 * @param width
 */
void initPlanetDemo3(planet* t, int height, int width){

        t[0].x = width/2; //en haut
        t[0].y = height/4;
        t[0].x_vel = -10;
        t[0].y_vel = 0;
        t[0].rayon = 20;

        t[1].x = width/4; //a gauche
        t[1].y = height/2;
        t[1].x_vel = 0;
        t[1].y_vel = 2;
        t[1].rayon = 20;

        t[2].x = width - 10; //a gauche
        t[2].y = height - 50;
        t[2].x_vel = 0;
        t[2].y_vel = 10;
        t[2].rayon = 20;
}

/**
 * @brief Procedure to initialise an array of planets for demo 
 * 
 * @param t 
 * @param height 
 * @param width
 */
void initPlanetDemo4(planet* t, int height, int width){

        t[0].x = width/2; 
        t[0].y = height/4;
        t[0].x_vel = -10;
        t[0].y_vel = 0;
        t[0].rayon = 20;

        t[1].x = width/4; 
        t[1].y = height/2;
        t[1].x_vel = 0;
        t[1].y_vel = 2;
        t[1].rayon = 20;

        t[2].x = width - 10; 
        t[2].y = height - 50;
        t[2].x_vel = 0;
        t[2].y_vel = 10;
        t[2].rayon = 50;
}