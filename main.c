#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogoadivin.h"
#include "jogoForca.h"
/*
    Código desenvolvido no curso:
    "C: conhecendo a Linguagem das Linguagens"
    pela Alura...
*/

int main() {

    printf("===============================\n");
    printf("Bem vindo ao jogo da Advinhação\n");
    printf("===============================\n");


    printf("Você deseja jogar qual jogo: \n1 - Jogo da Adivinhação\n2 - Jogo da Forca\n3 - Pac-man\n");
    int opc = 0;

    printf("Insira sua resposta : ");

    scanf_s("%d", &opc);

    switch(opc){
    
        case 1:
            jogo_advinhacao();
            break;
        case 2:
            jogo_forca();
            break;
        case 3:
            //jogo_pacman();
            break;
        default:
            printf("Você não selecionou nenhum jogo !!");
            break;

    }





}