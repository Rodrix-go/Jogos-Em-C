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
#include "../Adivinha/jogoadivin.h"
#include "../Forca/jogoForca.h"
#include "../Pega-Pega/jogoPega.h"
#include "../Forca/JogoForcaGUI.h"

/*
    Código desenvolvido no curso
    : "C: conhecendo a Linguagem das Linguagens" pela Alura...
*/

// Make them global

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *button_advin;
GtkWidget *button_forca;
GtkWidget *button_pega;
GtkWidget *text1;
GtkBuilder *builder;

int main(int argc, char *argv[])
{

  gtk_init(&argc, &argv); // init Gtk

  builder = gtk_builder_new_from_file("Menu/TelaMenu.glade");

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  gtk_builder_connect_signals(builder, NULL);

  fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
  button_advin = GTK_WIDGET(gtk_builder_get_object(builder, "button_advin"));
  button_forca = GTK_WIDGET(gtk_builder_get_object(builder, "button_forca"));
  button_pega = GTK_WIDGET(gtk_builder_get_object(builder, "button_pega"));
  text1 = GTK_WIDGET(gtk_builder_get_object(builder, "text1"));

  gtk_widget_show(window);

  gtk_main();

  return EXIT_SUCCESS;
}

void on_button_adivin_clicked(GtkButton *b, gpointer user_data)
{
  // Destruir a janela principal
  gtk_widget_destroy(window);
  adivinhacaoScreen01(0, 0);
}

void on_button_forca_clicked(GtkButton *b, gpointer user_data)
{
  gtk_widget_destroy(window);
  forcaWindow01(0, 0);
  // jogo_forca();
}

void on_button_pega_clicked(GtkButton *b)
{
  jogoPega();
}
