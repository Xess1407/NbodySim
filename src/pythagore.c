/* Functions for doing geometric calculations in C. */
#include <stdio.h>
#include <math.h>

/**
 * @brief Function who return the distance beetween two points
 * 
 * @param ax 
 * @param ay 
 * @param bx 
 * @param by 
 * @return float 
 */
float distance(int ax, int ay, int bx, int by){
    float distance;

    distance = pow((bx-ax), 2.0)+ pow((by - ay), 2.0);

    return (sqrt(distance));
}