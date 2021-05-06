#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include "gravitation.h"

void setPixelVerif(SDL_Renderer *renderer,int x, int y)
{
    SDL_SetRenderDrawColor(renderer, 255,0,0,255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void cercle(SDL_Renderer *renderer, int cx, int cy, int rayon)
{
  int d, y, x;
 
  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;
 
  while (y >= x) {
    setPixelVerif(renderer, cx + x, cy + y);
    setPixelVerif(renderer, cx + y, cy + x);
    setPixelVerif(renderer, cx - x, cy + y);
    setPixelVerif(renderer, cx - y, cy + x);
    setPixelVerif(renderer, cx + x, cy - y);
    setPixelVerif(renderer, cx + y, cy - x);
    setPixelVerif(renderer, cx - x, cy - y);
    setPixelVerif(renderer, cx - y, cy - x);
 
    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }
 
    x++;
  }
}