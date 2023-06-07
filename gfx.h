#ifndef GFX_H_
#define GFX_H_

#include <SDL2/SDL.h>

typedef int i32;
typedef long long int i64;

typedef struct {
  SDL_Window *w;
  SDL_Renderer *r;
  SDL_Event *e;
} Context;

typedef struct {
  int r,g,b,a;
} gfx_Color;

gfx_Color gfx_color_from_rgb(int r, int g, int b);

Context gfx_init(int x, int y, int w, int h);
void gfx_clear(Context ctx);
void gfx_color(Context ctx, gfx_Color c);
void gfx_point(Context ctx, int x , int y);
void gfx_line(Context ctx, int x1, int y1, int x2, int y2);

#endif // GFX_H_
