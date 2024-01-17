#ifndef _UI_H_
#define _UI_H_

#include "mapa.h"
#include "gtk/gtk.h"

int FogeWindow1(int argc, char *argv[]);
int FogeWindow2(int argc, char *argv[], int resultado);
void atualiza_mapa();
void imprimeparte(char desenho[4][7], int parte);
void imprimemapa(MAPA *m);

#endif