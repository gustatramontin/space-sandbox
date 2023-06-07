#ifndef MAIN_H_
#define MAIN_H_

#include <math.h>
#include <SDL2/SDL.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#define UNIVERSTAILLE 500

typedef SDL_Renderer renderer;

typedef struct {
  int x;
  int y;
} ivecteur;

typedef struct {
  int masse;
  ivecteur vitesse;

} Matiere;

typedef struct {
  Matiere univers_plan[UNIVERSTAILLE*UNIVERSTAILLE];
} Univers;

const Matiere Vide = {0, {0, 0}};
const Univers UniversVide = { { Vide } };

#endif // MAIN_H_
