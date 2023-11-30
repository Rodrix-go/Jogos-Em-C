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

// Váriaveis Globais
char num_maiores[100] = "";
char num_menores[100] = "";
int numero_tentativas;
int numerosecreto;
int tentativas;

int resultado = 0;
/*
1 - Ganhou
2 - Perdeu
*/
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

void on_button_medium_clicked(GtkButton *b)
{
  gtk_widget_destroy(adivinha_window01);
  adivinhacaoScreen02(0, 0, 15);
}

void on_button_easy_clicked(GtkButton *b)
{
  gtk_widget_destroy(adivinha_window01);
  adivinhacaoScreen02(0, 0, 20);
}

void on_button_hard_clicked(GtkButton *b)
{
  gtk_widget_destroy(adivinha_window01);
  adivinhacaoScreen02(0, 0, 6);
}

GtkWidget *adivinha_text8;
GtkWidget *adivinha_num_maior;
GtkWidget *adivinha_num_menor;
GtkWidget *adivinha_chances;
GtkWidget *adivinha_text_secret;
GtkWidget *adivinha_entry1;

GtkWidget *adivinha_window02;
int adivinhacaoScreen02(int argc, char *argv[], int chances)
{
  GtkWidget *adivinha_fixed2;

  GtkWidget *adivinha_text2;
  GtkWidget *adivinha_text3;
  GtkWidget *adivinha_text4;
  GtkWidget *adivinha_text5;
  GtkWidget *adivinha_text6;
  GtkWidget *adivinha_text7;

  GtkBuilder *adivinha_builder;

  gtk_init(&argc, &argv); // init Gtk

  adivinha_builder = gtk_builder_new_from_file("Adivinha/AdivinhaTela02.glade");

  adivinha_window02 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_window02"));

  g_signal_connect(adivinha_window02, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(adivinha_builder, NULL);

  adivinha_text_secret = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text_secret"));
  adivinha_num_menor = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_num_menor"));
  adivinha_num_maior = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_num_maior"));
  adivinha_chances = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_chances"));
  adivinha_entry1 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_entry1"));
  adivinha_text2 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text2"));
  adivinha_text3 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text3"));
  adivinha_text4 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text4"));
  adivinha_text5 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text5"));
  adivinha_text6 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text6"));
  adivinha_text7 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text7"));
  adivinha_text8 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text8"));

  int segundos = time(0);
  srand(segundos);
  int numerogrande = rand();
  numerosecreto = numerogrande % 100;
  printf("O número secreto é: %d\n", numerosecreto);

  // Altera valor inicial das chances restantes com base no nível
  char texto_chances[10];
  sprintf(texto_chances, "%d", chances);
  gtk_label_set_text(GTK_LABEL(adivinha_chances), (const gchar *)texto_chances);
  numero_tentativas = chances;

  // Esconde Texto de mensagem Inválida"`
  gtk_widget_set_visible(GTK_WIDGET(adivinha_text8), 0);

  gtk_widget_show(adivinha_window02);

  gtk_main();
  gtk_widget_destroy(adivinha_window02);

  //  double pontosperdidos = abs(chute - numerosecreto) / (double)2.0;
  //  pontos = pontos - pontosperdidos;

  return EXIT_SUCCESS;
}

void on_adivinha_entry1_activate(GtkEntry *entry)
{
  const gchar *texto = gtk_entry_get_text(entry);

  int num;
  num = converter_str_to_int(texto);

  // Erro de conversão ou valor negativo
  if (num >= 0)
  {
    gtk_widget_set_visible(GTK_WIDGET(adivinha_text8), 0);
    g_print("Texto inserido correto: %s\n", texto);

    if (num == numerosecreto)
    {
      printf("Legal em !!\n");
      char texto_chances[10];
      sprintf(texto_chances, "%d", num);
      gtk_label_set_text(GTK_LABEL(adivinha_text_secret), (const gchar *)texto_chances);
      gtk_entry_set_text(GTK_ENTRY(entry), "");
      resultado = 1;
      adivinhacaoScreen03(0, 0);
    }
    else if (num > numerosecreto)
    {
      printf("Seu chute foi maior que o número secreto\n");
      char texto_chances[10];
      sprintf(texto_chances, "%d ", num);

      strcat(num_maiores, texto_chances);
      printf("%s\n", num_maiores);
      gtk_label_set_text(GTK_LABEL(adivinha_num_maior), (const gchar *)num_maiores);
    }
    else
    {
      printf("Seu chute foi menor que o número secreto\n");
      char texto_chances[10];
      sprintf(texto_chances, "%d ", num);

      strcat(num_menores, texto_chances);
      printf("%s\n", num_menores);
      gtk_label_set_text(GTK_LABEL(adivinha_num_menor), (const gchar *)num_menores);
    }

    char texto_chances[10];
    tentativas++;
    sprintf(texto_chances, "%d", numero_tentativas - tentativas);
    gtk_label_set_text(GTK_LABEL(adivinha_chances), (const gchar *)texto_chances);
  }
  else
  {
    gtk_widget_set_visible(GTK_WIDGET(adivinha_text8), 1);
    g_print("Texto inserido errado: %s\n", texto);
  }
  gtk_entry_set_text(GTK_ENTRY(entry), "");
}

int converter_str_to_int(const char *string)
{
  char *endptr;

  // Converte a string para um inteiro com verificação de erro
  int numero = strtol(string, &endptr, 10);
  g_print("Texto inserido: %d\n", numero);

  // Verifica se ocorreu um erro na conversão
  if (*endptr != '\0')
    numero = -1;
  return numero;
}

GtkWidget *adivinha_window03;
int adivinhacaoScreen03(int argc, char *argv[])
{
  GtkWidget *adivinha_fixed3;
  GtkWidget *adivinha_fixed4;
  GtkWidget *adivinha_button_yes;
  GtkWidget *adivinha_button_no;
  GtkWidget *adivinha_text_end;
  GtkWidget *adivinha_text9;
  GtkBuilder *adivinha_builder;

  gtk_init(&argc, &argv); // init Gtk

  adivinha_builder = gtk_builder_new_from_file("Adivinha/AdivinhaTela03.glade");

  adivinha_window03 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_window03"));

  g_signal_connect(adivinha_window03, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(adivinha_builder, NULL);

  adivinha_fixed3 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_fixed4"));
  adivinha_fixed4 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_fixed3"));
  adivinha_button_yes = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_button_yes"));
  adivinha_button_no = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_button_no"));
  adivinha_text_end = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text_end"));
  adivinha_text9 = GTK_WIDGET(gtk_builder_get_object(adivinha_builder, "adivinha_text9"));
  gtk_widget_show(adivinha_window03);

  char texto_edit[10];
  if (resultado == 1)
  {
    sprintf(texto_edit, "Parabéns você ganhou !!\nO número secreto era: %d", numerosecreto);
  }
  else
  {
    sprintf(texto_edit, "Não foi dessa vez !!\nO número secreto era: %d", numerosecreto);
  }

  gtk_label_set_text(GTK_LABEL(adivinha_text_end), (const gchar *)texto_edit);

  gtk_main();
  gtk_widget_destroy(adivinha_window03);

  return EXIT_SUCCESS;
}

void on_adivinha_button_yes_clicked(GtkButton *b, gpointer user_data)
{
  sprintf(num_maiores, "");
  sprintf(num_menores, "");
  gtk_label_set_text(GTK_LABEL(adivinha_num_menor), (const gchar *)num_maiores);
  gtk_label_set_text(GTK_LABEL(adivinha_num_maior), (const gchar *)num_menores);

  int segundos = time(0);
  srand(segundos);
  int numerogrande = rand();
  numerosecreto = numerogrande % 100;
  printf("O número secreto é: %d\n", numerosecreto);
  gtk_label_set_text(GTK_LABEL(adivinha_text_secret), (const gchar *)"??");

  char texto_chances[10];
  tentativas = 0;
  sprintf(texto_chances, "%d", numero_tentativas - tentativas);
  gtk_label_set_text(GTK_LABEL(adivinha_chances), (const gchar *)texto_chances);

  gtk_widget_destroy(adivinha_window02);
  gtk_widget_destroy(adivinha_window03);
  adivinhacaoScreen02(0, 0, 20);
}

void on_adivinha_button_no_clicked(GtkButton *b, gpointer user_data)
{
  gtk_widget_destroy(adivinha_window02);
  gtk_widget_destroy(adivinha_window03);
}