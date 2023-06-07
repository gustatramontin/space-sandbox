#include "main.h"
#include "gfx.h"

int est_vide(Matiere m) {
  return m.masse == Vide.masse && m.vitesse.x == Vide.vitesse.x && m.vitesse.y == Vide.vitesse.y;
}

ivecteur position(int p) {
  int y = floor(p/(double) UNIVERSTAILLE);
  int x = p - y*UNIVERSTAILLE;
  ivecteur nouvelle_p = {x, y};

  return nouvelle_p;
}

void dessiner_le_univers(Context ctx, Univers u) {
  int taille_de_lunivers = sizeof(u.univers_plan)/sizeof(Matiere);
  for (int m=0; m<taille_de_lunivers; m++) {

    Matiere cette_matiere = u.univers_plan[m];
    if (est_vide(cette_matiere))
      continue;

    gfx_color(ctx, gfx_color_from_rgb(0,255,0));

    ivecteur p = position(m);
    gfx_point(ctx, p.x, p.y);
  }
}

Univers avancer_dans_le_temps(int temps, Univers u) {
  int taille_de_lunivers = sizeof(u.univers_plan)/sizeof(Matiere);
  Univers nouveau_univers = UniversVide;

  for (int m=0; m < taille_de_lunivers; m++) {
    Matiere cette_matiere = u.univers_plan[m];
    int limite_h = ceil(m/(double) UNIVERSTAILLE)*UNIVERSTAILLE;

    if (est_vide(cette_matiere))
      continue;

    int nouvelle_position = MIN(limite_h, MAX(m+cette_matiere.vitesse.x, limite_h-UNIVERSTAILLE)) +
      MIN(cette_matiere.vitesse.y*UNIVERSTAILLE, MAX(UNIVERSTAILLE*UNIVERSTAILLE, 0));

    nouveau_univers.univers_plan[nouvelle_position] = cette_matiere;

    if (!est_vide(u.univers_plan[nouvelle_position])) {

    }

  }

  return nouveau_univers;
}


int main(int argc, char *argv[]) {

    Context ctx = gfx_init(SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,UNIVERSTAILLE, UNIVERSTAILLE );

    Univers u = UniversVide;

    ivecteur v = {1, 1};
    Matiere m = {1, v};

    u.univers_plan[1] = m;

    int exited = 0;
    for (;;) {
      gfx_color(ctx, gfx_color_from_rgb(2,2,2));
      gfx_clear(ctx);


      dessiner_le_univers(ctx, u);
      u = avancer_dans_le_temps(0, u);


      SDL_RenderPresent(ctx.r);
      SDL_Delay(10);
    }
  return 0;
}
