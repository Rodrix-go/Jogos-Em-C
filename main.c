#include "Adivinha/jogoadivin.h"
#include "Forca/jogoForca.h"
#include "Pega-Pega/jogoPega.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    C�digo desenvolvido no curso:
    "C: conhecendo a Linguagem das Linguagens"
    pela Alura...
*/

int main() {

  printf("==============================P=\n");
  printf("Bem vindo ao jogo da Advinhação\n");
  printf("===============================\n");

  printf("Voce deseja jogar qual jogo: \n1 - Jogo da Adivinhação\n2 - Jogo da "
         "Forca\n3 - Pac-man\n");
  int opc = 3; // Valor 0

  printf("Insira sua resposta : ");

  scanf("%d", &opc);

  switch (opc) {

  case 1:
    jogoAdvinhacao();
    break;
  case 2:
    jogo_forca();
    break;
  case 3:
    jogoPega();
    break;
  default:
    printf("Você não selecionou nenhum jogo !!");
    break;
  }
}