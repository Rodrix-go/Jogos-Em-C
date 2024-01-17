#include "jogoForca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_PALAVRA 20
char tema[10];
char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

int enforcou()
{

  int erros = 0;

  for (int i = 0; i < chutesdados; i++)
  {

    int existe = 0;

    for (int j = 0; j < strlen(palavrasecreta); j++)
    {
      if (chutes[i] == palavrasecreta[j])
      {
        existe = 1;
        break;
      }
    }

    if (!existe)
      erros++;
  }

  return erros >= QNTD_DE_ERROS;
}

int ganhou()
{
  for (int i = 0; i < strlen(palavrasecreta); i++)
  {
    if (!jachutou(palavrasecreta[i]))
    {
      return 0;
    }
  }

  return 1;
}

int jachutou(char letra)
{
  int achou = 0;
  for (int j = 0; j < chutesdados; j++)
  {
    if (chutes[j] == letra)
    {
      achou = 1;
      break;
    }
  }

  return achou;
}

int letraexiste(char letra)
{

  for (int j = 0; j < strlen(palavrasecreta); j++)
  {
    if (letra == palavrasecreta[j])
    {
      return 1;
    }
  }

  return 0;
}

void abertura()
{
  printf("/****************/\n");
  printf("/ Jogo de Forca */\n");
  printf("/****************/\n\n");
}

void chuta(char letra)
{
  chutes[chutesdados] = letra;
  chutesdados++;
}

int chuteserrados()
{
  int erros = 0;

  for (int i = 0; i < chutesdados; i++)
  {

    if (!letraexiste(chutes[i]))
    {
      erros++;
    }
  }

  return erros;
}

void escolhetema()
{
  FILE *f;
  f = fopen("Forca/palavrasSecretas/temas.txt", "r");
  if (f == 0)
  {
    printf("Banco de dados de palavras n�o dispon�vel\n\n");
    exit(1);
  }

  int qntdetemas;
  fscanf(f, "%d", &qntdetemas);

  srand(time(0));

  int randomico = rand() % qntdetemas;

  for (int i = 0; i <= randomico; i++)
  {
    fscanf(f, "%s", tema);
  }
  fclose(f);
}

void escolhepalavra()
{
  FILE *f;
  char str_tmp[40];
  sprintf(str_tmp, "Forca/palavrasSecretas/%s.txt", tema);
  f = fopen(str_tmp, "r");

  if (f == 0)
  {
    printf("Banco de dados de palavras n�o dispon�vel\n\n");
    exit(1);
  }

  int qtddepalavras;
  fscanf(f, "%d", &qtddepalavras);

  srand(time(0));

  int randomico = rand() % qtddepalavras;

  for (int i = 0; i <= randomico; i++)
  {
    fscanf(f, "%s", palavrasecreta);
  }
  fclose(f);
}

void adcionapalavra()
{
  char quer;
  printf("Voce deseja adicionar uma nova palvra no jogo (S/N)");
  scanf(" %c", &quer);

  if (quer == 'S')
  {

    char novapalavra[TAMANHO_PALAVRA];
    printf("Qual a nova palavra? ");
    scanf("%s", novapalavra);

    FILE *f;

    f = fopen("Forca/PalavrasSecretas.txt", "r+");

    int qtd;
    fscanf(f, "%d", &qtd);
    qtd++;

    fseek(f, 0, SEEK_SET);
    fprintf(f, "%d", qtd);

    fseek(f, 0, SEEK_END);
    fprintf(f, "\n%s", novapalavra);

    fclose(f);
  }
}

void jogo_forca()
{

  abertura();
  adcionapalavra();
  escolhepalavra();

  do
  {

    desenhaforca();
    chuta('A');

  } while (!ganhou() && !enforcou());

  printf("\nA palavra secreta era ** %s **", palavrasecreta);

  if (ganhou())
  {

    printf("\nParabéns você ganhou !!");
  }
  else
  {

    printf("\nInfelizemente você perdeu");
  }
}