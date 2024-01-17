#include "JogoForcaGUI.h"
#include "jogoForca.h"

#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>

// Make them global
int existe = 0;
GtkWidget *forca_window01;
GtkWidget *forca_fixed01;
GtkWidget *forca_image01;
GtkWidget *forca_text_theme;
GtkWidget *forca_text_string;
GtkWidget *button_A;
GtkWidget *button_B;
GtkWidget *button_C;
GtkWidget *button_D;
GtkWidget *button_E;
GtkWidget *button_F;
GtkWidget *button_G;
GtkWidget *button_H;
GtkWidget *button_I;
GtkWidget *button_J;
GtkWidget *button_K;
GtkWidget *button_L;
GtkWidget *button_M;
GtkWidget *button_N;
GtkWidget *button_O;
GtkWidget *button_P;
GtkWidget *button_Q;
GtkWidget *button_R;
GtkWidget *button_S;
GtkWidget *button_T;
GtkWidget *button_U;
GtkWidget *button_V;
GtkWidget *button_W;
GtkWidget *button_X;
GtkWidget *button_Y;
GtkWidget *button_Z;

int forcaWindow01(int argc, char *argv[])
{
  gtk_init(&argc, &argv); // init Gtk

  GtkBuilder *builder;

  //---------------------------------------------------------------------
  // establish contact with xml code used to adjust widget settings
  //---------------------------------------------------------------------

  builder = gtk_builder_new_from_file("Forca/ForcaWindow01.glade");

  forca_window01 = GTK_WIDGET(gtk_builder_get_object(builder, "forca_window01"));

  g_signal_connect(forca_window01, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(builder, NULL);

  forca_fixed01 = GTK_WIDGET(gtk_builder_get_object(builder, "forca_fixed01"));
  forca_text_theme = GTK_WIDGET(gtk_builder_get_object(builder, "forca_text_theme"));
  forca_text_string = GTK_WIDGET(gtk_builder_get_object(builder, "forca_text_string"));
  forca_image01 = GTK_WIDGET(gtk_builder_get_object(builder, "forca_image01"));
  button_A = GTK_WIDGET(gtk_builder_get_object(builder, "button_A"));
  button_B = GTK_WIDGET(gtk_builder_get_object(builder, "button_B"));
  button_C = GTK_WIDGET(gtk_builder_get_object(builder, "button_C"));
  button_D = GTK_WIDGET(gtk_builder_get_object(builder, "button_D"));
  button_E = GTK_WIDGET(gtk_builder_get_object(builder, "button_E"));
  button_F = GTK_WIDGET(gtk_builder_get_object(builder, "button_F"));
  button_G = GTK_WIDGET(gtk_builder_get_object(builder, "button_G"));
  button_H = GTK_WIDGET(gtk_builder_get_object(builder, "button_H"));
  button_I = GTK_WIDGET(gtk_builder_get_object(builder, "button_I"));
  button_J = GTK_WIDGET(gtk_builder_get_object(builder, "button_J"));
  button_K = GTK_WIDGET(gtk_builder_get_object(builder, "button_K"));
  button_L = GTK_WIDGET(gtk_builder_get_object(builder, "button_L"));
  button_M = GTK_WIDGET(gtk_builder_get_object(builder, "button_M"));
  button_N = GTK_WIDGET(gtk_builder_get_object(builder, "button_N"));
  button_O = GTK_WIDGET(gtk_builder_get_object(builder, "button_O"));
  button_P = GTK_WIDGET(gtk_builder_get_object(builder, "button_P"));
  button_Q = GTK_WIDGET(gtk_builder_get_object(builder, "button_Q"));
  button_R = GTK_WIDGET(gtk_builder_get_object(builder, "button_R"));
  button_S = GTK_WIDGET(gtk_builder_get_object(builder, "button_S"));
  button_T = GTK_WIDGET(gtk_builder_get_object(builder, "button_T"));
  button_U = GTK_WIDGET(gtk_builder_get_object(builder, "button_U"));
  button_V = GTK_WIDGET(gtk_builder_get_object(builder, "button_V"));
  button_W = GTK_WIDGET(gtk_builder_get_object(builder, "button_W"));
  button_X = GTK_WIDGET(gtk_builder_get_object(builder, "button_X"));
  button_Y = GTK_WIDGET(gtk_builder_get_object(builder, "button_Y"));
  button_Z = GTK_WIDGET(gtk_builder_get_object(builder, "button_Z"));

  // Ajustar o tema
  char text_tmp[10];
  escolhetema();
  gtk_label_set_text(GTK_LABEL(forca_text_theme), (const gchar *)tema);

  // Ajustar a quantidade de letras
  sprintf(text_tmp, "");
  escolhepalavra();

  for (int i = 0; i < strlen(palavrasecreta); i++)
  {
    strcat(text_tmp, "_ ");
  }

  gtk_label_set_text(GTK_LABEL(forca_text_string), (const gchar *)text_tmp);

  gtk_widget_show(forca_window01);

  gtk_main();

  return EXIT_SUCCESS;
}

void desenhaforca()
{

  int erros = chuteserrados();

  char str_tmp[40];
  sprintf(str_tmp, "Forca/img/%d.gif", erros + 1);
  gtk_image_set_from_file(GTK_IMAGE(forca_image01), str_tmp);

  sprintf(str_tmp, " ");

  for (int i = 0; i < strlen(palavrasecreta); i++)
  {

    if (jachutou(palavrasecreta[i]))
    {
      char letra[3];
      sprintf(letra, "%c ", palavrasecreta[i]);
      strcat(str_tmp, letra);
    }
    else
    {
      strcat(str_tmp, "_ ");
    }
  }
  gtk_label_set_text(GTK_LABEL(forca_text_string), (const gchar *)str_tmp);

  if ((ganhou()) || (enforcou()))
  {
    forcaWindow02(0, 0, ganhou());
  }
}

GtkWidget *forca_window02;

int forcaWindow02(int argc, char *argv[], int resultado)
{
  GtkWidget *forca_fixed2;
  GtkWidget *forca_fixed3;
  GtkWidget *forca_button_yes;
  GtkWidget *forca_button_no;
  GtkWidget *forca_text_end;
  GtkWidget *forca_text_opc;
  GtkBuilder *forca_builder;

  gtk_init(&argc, &argv); // init Gtk

  forca_builder = gtk_builder_new_from_file("Forca/ForcaWindow02.glade");

  forca_window02 = GTK_WIDGET(gtk_builder_get_object(forca_builder, "forca_window02"));

  g_signal_connect(forca_window02, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(forca_builder, NULL);

  forca_fixed3 = GTK_WIDGET(gtk_builder_get_object(forca_builder, "forca_fixed3"));
  forca_fixed2 = GTK_WIDGET(gtk_builder_get_object(forca_builder, "forca_fixed2"));
  forca_button_yes = GTK_WIDGET(gtk_builder_get_object(forca_builder, "forca_button_yes"));
  forca_button_no = GTK_WIDGET(gtk_builder_get_object(forca_builder, "forca_button_no"));
  forca_text_end = GTK_WIDGET(gtk_builder_get_object(forca_builder, "forca_text_end"));
  forca_text_opc = GTK_WIDGET(gtk_builder_get_object(forca_builder, "forca_text_ppc"));
  gtk_widget_show(forca_window02);

  char texto_edit[10];
  if (resultado)
    sprintf(texto_edit, "Parabéns você ganhou !!\nO número secreto era: %s", palavrasecreta);
  else
    sprintf(texto_edit, "Infelizmente você perdeu\nA palavra secreta era: %s", palavrasecreta);

  gtk_label_set_text(GTK_LABEL(forca_text_end), (const gchar *)texto_edit);

  gtk_widget_set_name(forca_button_yes, "forca_button_yes");
  gtk_widget_set_name(forca_button_no, "forca_button_no");
  add_estilo("Forca/estilo_forca.css", forca_button_yes);
  add_estilo("Forca/estilo_forca.css", forca_button_no);

  gtk_main();
  gtk_widget_destroy(forca_window02);

  return EXIT_SUCCESS;
}

void on_forca_button_yes_clicked(GtkButton *b, gpointer user_data)
{

  gtk_widget_destroy(forca_window01);
  gtk_widget_destroy(forca_window02);

  memset(chutes, 0, sizeof(chutes));
  chutesdados = 0;
  forcaWindow01(0, 0);
}
void on_forca_button_no_clicked(GtkButton *b, gpointer user_data)
{
  gtk_widget_destroy(forca_window02);
  gtk_widget_destroy(forca_window01);
}

void on_button_A_clicked(GtkButton *b)
{

  chuta('A');
  gtk_widget_destroy(button_A);
  desenhaforca();
}
void on_button_B_clicked(GtkButton *b)
{
  chuta('B');
  gtk_widget_destroy(button_B);
  desenhaforca();
}
void on_button_C_clicked(GtkButton *b)
{
  chuta('C');
  gtk_widget_destroy(button_C);
  desenhaforca();
}
void on_button_D_clicked(GtkButton *b)
{
  chuta('D');
  gtk_widget_destroy(button_D);
  desenhaforca();
}
void on_button_E_clicked(GtkButton *b)
{
  chuta('E');
  gtk_widget_destroy(button_E);
  desenhaforca();
}
void on_button_F_clicked(GtkButton *b)
{
  chuta('F');
  gtk_widget_destroy(button_F);
  desenhaforca();
}
void on_button_G_clicked(GtkButton *b)
{
  chuta('G');
  gtk_widget_destroy(button_G);
  desenhaforca();
}
void on_button_H_clicked(GtkButton *b)
{
  chuta('H');
  gtk_widget_destroy(button_H);
  desenhaforca();
}
void on_button_I_clicked(GtkButton *b)
{
  chuta('I');
  gtk_widget_destroy(button_I);
  desenhaforca();
}
void on_button_J_clicked(GtkButton *b)
{
  chuta('J');
  gtk_widget_destroy(button_J);
  desenhaforca();
}
void on_button_K_clicked(GtkButton *b)
{
  chuta('K');
  gtk_widget_destroy(button_K);
  desenhaforca();
}
void on_button_L_clicked(GtkButton *b)
{
  chuta('L');
  gtk_widget_destroy(button_L);
  desenhaforca();
}
void on_button_M_clicked(GtkButton *b)
{
  chuta('M');
  gtk_widget_destroy(button_M);
  desenhaforca();
}
void on_button_N_clicked(GtkButton *b)
{
  chuta('N');
  gtk_widget_destroy(button_N);
  desenhaforca();
}
void on_button_O_clicked(GtkButton *b)
{
  chuta('O');
  gtk_widget_destroy(button_O);
  desenhaforca();
}
void on_button_P_clicked(GtkButton *b)
{
  chuta('P');
  gtk_widget_destroy(button_P);
  desenhaforca();
}
void on_button_Q_clicked(GtkButton *b)
{
  chuta('Q');
  gtk_widget_destroy(button_Q);
  desenhaforca();
}
void on_button_R_clicked(GtkButton *b)
{
  chuta('R');
  gtk_widget_destroy(button_R);
  desenhaforca();
}
void on_button_S_clicked(GtkButton *b)
{
  chuta('S');
  gtk_widget_destroy(button_S);
  desenhaforca();
}
void on_button_T_clicked(GtkButton *b)
{
  chuta('T');
  gtk_widget_destroy(button_T);
  desenhaforca();
}
void on_button_U_clicked(GtkButton *b)
{
  chuta('U');
  gtk_widget_destroy(button_U);
  desenhaforca();
}
void on_button_V_clicked(GtkButton *b)
{
  chuta('V');
  gtk_widget_destroy(button_V);
  desenhaforca();
}
void on_button_W_clicked(GtkButton *b)
{
  chuta('W');
  gtk_widget_destroy(button_W);
  desenhaforca();
}
void on_button_X_clicked(GtkButton *b)
{
  chuta('X');
  gtk_widget_destroy(button_X);
  desenhaforca();
}
void on_button_Y_clicked(GtkButton *b)
{
  chuta('Y');
  gtk_widget_destroy(button_Y);
  desenhaforca();
}
void on_button_Z_clicked(GtkButton *b)
{
  chuta('Z');
  gtk_widget_destroy(button_Z);
  desenhaforca();
}