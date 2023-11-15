#include "jogoadivin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <math.h>
#include <ctype.h>

GtkWidget *adivinha_window01;
int adivinhacaoScreen01(int argc, char *argv[])
{
  GtkWidget *adivinha_fixed1;
  GtkWidget *button_easy;
  GtkWidget *button_medium;
  GtkWidget *button_hard;
  GtkWidget *adivinha_text1;
  GtkBuilder *adivinha_builder;

  gtk_init(&argc, &argv); // init Gtk

  adivinha_builder = gtk_builder_new_from_file("Adivinha/AdivinhaTela01.glade");

  adivinha_window01 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_window01"));

  g_signal_connect(adivinha_window01, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(adivinha_builder, NULL);

  adivinha_fixed1 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_fixed01"));
  button_easy = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "button_easy"));
  button_medium = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "button_medium"));
  button_hard = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "button_hard"));
  adivinha_text1 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text1"));

  gtk_widget_show(adivinha_window01);

  gtk_main();
  gtk_widget_destroy(adivinha_window01);

  return EXIT_SUCCESS;
}

void on_button_easy_clicked(GtkButton *b)
{
  gtk_widget_destroy(adivinha_window01);
}

void on_button_medium_clicked(GtkButton *b, gpointer user_data)
{
  gtk_widget_destroy(adivinha_window01);
}

void on_button_hard_clicked(GtkButton *b, gpointer user_data)
{
  // Destruir a janela principal
  gtk_widget_destroy(adivinha_window01);
}

void jogoAdvinhacao(int argc, char *argv[], int nivel)
{
  // Declaração de váriaveis
  int segundos = time(0);
  srand(segundos);
  int numerogrande = rand();
  int numerosecreto = numerogrande % 100;
  int chute;
  int tentativas = 1;
  double pontos = 1000;
  int acertou = 0;

  // Seleção da dificuldade
  printf("Qual o n�vel de dificuldade?\n");
  printf("(1) Fácil (2) Médio (3) Difícil\n\n");
  printf("Escolha: ");
  scanf("%d", &nivel);

  int numerodetentativas;
  if (nivel == 1)
    numerodetentativas = 20;
  else if (nivel == 2)
    numerodetentativas = 15;
  else if (nivel == 3)
    numerodetentativas = 6;
  else
    numerodetentativas = 15;

  // Algoritimo de tentativas

  for (int i = 1; i <= numerodetentativas; i++)
  {

    printf("Tentativa %d\n", tentativas);
    printf("Qual o o seu número? ");

    scanf("%d", &chute);
    printf("Seu chute foi: %d\n", chute);

    if (chute < 0)
    {
      printf("Você não pode chutar números negativos!\n");
      continue;
    }

    acertou = (chute == numerosecreto);
    int maior = chute > numerosecreto;

    if (acertou)
    {
      break;
    }
    else if (maior)
    {
      printf("Seu chute foi maior que o número secreto\n");
    }
    else
    {
      printf("Seu chute foi menor que o número secreto\n");
    }

    tentativas++;

    double pontosperdidos = abs(chute - numerosecreto) / (double)2.0;
    pontos = pontos - pontosperdidos;
  }

  // Conferir resultado
  printf("Fim de jogo!\n");

  if (acertou)
  {
    printf("Você ganhou!\n");
    printf("Você acertou em %d tentativas!\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);
  }

  else
  {
    printf("Você perdeu! Tente de novo!\n");
  }
}
