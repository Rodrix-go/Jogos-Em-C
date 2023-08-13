#include "jogoadivin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void jogoAdvinhacao(void) {

    printf("Bem-Vindo ao jogo da Advinha��o");


    //Declara��o de v�riaveis
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;
    int nivel;

    //Sele��o da dificuldade
    printf("Qual o n�vel de dificuldade?\n");
    printf("(1) F�cil (2) M�dio (3) Dif�cil\n\n");
    printf("Escolha: ");
    scanf_s("%d", &nivel);

    int numerodetentativas;
    if(nivel == 1) numerodetentativas = 20;
    else if (nivel == 2) numerodetentativas = 15;
    else if (nivel == 3) numerodetentativas = 6;
    else numerodetentativas = 15;
    
    //Algoritimo de tentativas
    
    
    for (int i = 1; i <= numerodetentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual � o seu n�mero? ");

        scanf_s("%d", &chute);
        printf("Seu chute foi: %d\n", chute);

        if (chute < 0) {
            printf("Voc� n�o pode chutar n�meros negativos!\n");
            continue;
        }

        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if (acertou) {
            break;
        }
        else if (maior) {
            printf("Seu chute foi maior que o n�mero secreto\n");
        }
        else {
            printf("Seu chute foi menor que o n�mero secreto\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2.0;
        pontos = pontos - pontosperdidos;
    }


    //Conferir resultado
    printf("Fim de jogo!\n");


    if (acertou) {
        printf("Voc� ganhou!\n");
        printf("Voc� acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }

    else {
        printf("Voc� perdeu! Tente de novo!\n");
    }

}
