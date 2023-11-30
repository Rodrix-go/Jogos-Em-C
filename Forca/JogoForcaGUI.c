#include "JogoForcaGUI.h"
#include "gtk/gtk.h"

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

GtkWidget *forca_window01;
GtkWidget *forca_fixed01;
GtkWidget *forca_image01;
GtkWidget *forca_text_theme;
GtkWidget *button_A;

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
  forca_image01 = GTK_WIDGET(gtk_builder_get_object(builder, "forca_image01"));
  button_A = GTK_WIDGET(gtk_builder_get_object(builder, "button_A"));

  gtk_widget_show(forca_window01);

  gtk_main();

  return EXIT_SUCCESS;
}
