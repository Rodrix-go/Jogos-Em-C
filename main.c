#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogoadivin.h"
#include "jogoForca.h"
/*
    C�digo desenvolvido no curso:
    "C: conhecendo a Linguagem das Linguagens"
    pela Alura...
*/

int main() {

    printf("===============================\n");
    printf("Bem vindo ao jogo da Advinha��o\n");
    printf("===============================\n");


    printf("Voc� deseja jogar qual jogo: \n1 - Jogo da Adivinha��o\n2 - Jogo da Forca\n3 - Pac-man\n");
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
            printf("Voc� n�o selecionou nenhum jogo !!");
            break;

    }





}