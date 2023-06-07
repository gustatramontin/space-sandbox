#include "gfx.h"

gfx_Color gfx_color_from_rgb(int r, int g, int b) {
  gfx_Color c = {r, g, b, 255};
  return c;
}

Context gfx_init(int x, int y, int w, int h) {
  Context ctx;
  SDL_Init(SDL_INIT_VIDEO);
  ctx.w = SDL_CreateWindow("SDL2", x, y,
                              w, h, SDL_WINDOW_SHOWN);

  ctx.r = SDL_CreateRenderer(ctx.w, -1, SDL_RENDERER_ACCELERATED);
  return ctx;
}
void gfx_clear(Context ctx) {
  SDL_RenderClear(ctx.r);
}
void gfx_color(Context ctx, gfx_Color c) {
    SDL_SetRenderDrawColor(ctx.r, c.r, c.g, c.b, c.a);
}

void gfx_point(Context ctx, int x , int y) {
  SDL_RenderDrawPoint(ctx.r, x , y);

}

void gfx_line(Context ctx, int x1, int y1, int x2, int y2) {
  SDL_RenderDrawLine(ctx.r, x1, y1, x2, y2);
}
