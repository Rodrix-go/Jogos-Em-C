#include <stdio.h>
#include "mapa.h"
#include "ui.h"
#include "fogefoge.h"

GtkWidget *foge_window1;
GtkWidget *foge_grid1;

GtkWidget *foge_box1;
GtkWidget *foge_fixed1;
GtkWidget *foge_text_power;
GtkWidget *foge_button_up;
GtkWidget *foge_button_right;
GtkWidget *foge_button_left;
GtkWidget *foge_button_down;
GtkWidget *foge_button_bomb;

GtkWidget *foge_image0x0;
GtkWidget *foge_image0x1;
GtkWidget *foge_image0x2;
GtkWidget *foge_image0x3;
GtkWidget *foge_image0x4;
GtkWidget *foge_image0x5;
GtkWidget *foge_image1x0;
GtkWidget *foge_image1x1;
GtkWidget *foge_image1x2;
GtkWidget *foge_image1x3;
GtkWidget *foge_image1x4;
GtkWidget *foge_image1x5;
GtkWidget *foge_image2x0;
GtkWidget *foge_image2x1;
GtkWidget *foge_image2x2;
GtkWidget *foge_image2x3;
GtkWidget *foge_image2x4;
GtkWidget *foge_image2x5;
GtkWidget *foge_image3x0;
GtkWidget *foge_image3x1;
GtkWidget *foge_image3x2;
GtkWidget *foge_image3x3;
GtkWidget *foge_image3x4;
GtkWidget *foge_image3x5;
GtkWidget *foge_image4x0;
GtkWidget *foge_image4x1;
GtkWidget *foge_image4x2;
GtkWidget *foge_image4x3;
GtkWidget *foge_image4x4;
GtkWidget *foge_image4x5;
GtkWidget *foge_image5x0;
GtkWidget *foge_image5x1;
GtkWidget *foge_image5x2;
GtkWidget *foge_image5x3;
GtkWidget *foge_image5x4;
GtkWidget *foge_image5x5;
GtkWidget *foge_image6x0;
GtkWidget *foge_image6x1;
GtkWidget *foge_image6x2;
GtkWidget *foge_image6x3;
GtkWidget *foge_image6x4;
GtkWidget *foge_image6x5;
GtkWidget *foge_image7x0;
GtkWidget *foge_image7x1;
GtkWidget *foge_image7x2;
GtkWidget *foge_image7x3;
GtkWidget *foge_image7x4;
GtkWidget *foge_image7x5;
GtkWidget *foge_image8x0;
GtkWidget *foge_image8x1;
GtkWidget *foge_image8x2;
GtkWidget *foge_image8x3;
GtkWidget *foge_image8x4;
GtkWidget *foge_image8x5;
GtkWidget *foge_image9x0;
GtkWidget *foge_image9x1;
GtkWidget *foge_image9x2;
GtkWidget *foge_image9x3;
GtkWidget *foge_image9x4;
GtkWidget *foge_image9x5;

GtkWidget *widget_imagens_global[10][6];

MAPA m;
POSICAO heroi;
int tempilula = 1;

gboolean delay_atualiza_mapa(gpointer user_data)
{
	atualiza_mapa();
	return FALSE;
}

int FogeWindow1(int argc, char *argv[])
{
	lemapa(&m);
	encontramapa(&m, &heroi, HEROI);

	GtkBuilder *builder;
	gtk_init(&argc, &argv); // init Gtk

	builder = gtk_builder_new_from_file("Foge/FogeWindow1.glade");

	foge_window1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_window1"));
	g_signal_connect(foge_window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	foge_box1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_box1"));
	foge_grid1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_grid1"));
	foge_text_power = GTK_WIDGET(gtk_builder_get_object(builder, "foge_text_power"));
	foge_image0x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image0x0"));
	foge_image0x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image0x1"));
	foge_image0x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image0x2"));
	foge_image0x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image0x3"));
	foge_image0x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image0x4"));
	foge_image0x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image0x5"));
	foge_image1x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image1x0"));
	foge_image1x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image1x1"));
	foge_image1x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image1x2"));
	foge_image1x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image1x3"));
	foge_image1x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image1x4"));
	foge_image1x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image1x5"));
	foge_image2x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image2x0"));
	foge_image2x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image2x1"));
	foge_image2x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image2x2"));
	foge_image2x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image2x3"));
	foge_image2x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image2x4"));
	foge_image2x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image2x5"));
	foge_image3x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image3x0"));
	foge_image3x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image3x1"));
	foge_image3x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image3x2"));
	foge_image3x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image3x3"));
	foge_image3x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image3x4"));
	foge_image3x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image3x5"));
	foge_image4x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image4x0"));
	foge_image4x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image4x1"));
	foge_image4x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image4x2"));
	foge_image4x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image4x3"));
	foge_image4x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image4x4"));
	foge_image4x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image4x5"));
	foge_image5x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image5x0"));
	foge_image5x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image5x1"));
	foge_image5x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image5x2"));
	foge_image5x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image5x3"));
	foge_image5x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image5x4"));
	foge_image5x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image5x5"));
	foge_image6x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image6x0"));
	foge_image6x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image6x1"));
	foge_image6x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image6x2"));
	foge_image6x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image6x3"));
	foge_image6x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image6x4"));
	foge_image6x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image6x5"));
	foge_image7x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image7x0"));
	foge_image7x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image7x1"));
	foge_image7x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image7x2"));
	foge_image7x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image7x3"));
	foge_image7x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image7x4"));
	foge_image7x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image7x5"));
	foge_image8x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image8x0"));
	foge_image8x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image8x1"));
	foge_image8x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image8x2"));
	foge_image8x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image8x3"));
	foge_image8x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image8x4"));
	foge_image8x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image8x5"));
	foge_image9x0 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image9x0"));
	foge_image9x1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image9x1"));
	foge_image9x2 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image9x2"));
	foge_image9x3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image9x3"));
	foge_image9x4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image9x4"));
	foge_image9x5 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_image9x5"));

	foge_box1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_box1"));
	foge_fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_fixed1"));
	foge_text_power = GTK_WIDGET(gtk_builder_get_object(builder, "foge_text_power"));
	foge_button_up = GTK_WIDGET(gtk_builder_get_object(builder, "foge_button_up"));
	foge_button_right = GTK_WIDGET(gtk_builder_get_object(builder, "foge_button_right"));
	foge_button_left = GTK_WIDGET(gtk_builder_get_object(builder, "foge_button_left"));
	foge_button_down = GTK_WIDGET(gtk_builder_get_object(builder, "foge_button_down"));
	foge_button_bomb = GTK_WIDGET(gtk_builder_get_object(builder, "foge_button_bomb"));

	GtkWidget *widget_imagens[10][6] = {
		{foge_image0x0, foge_image0x1, foge_image0x2, foge_image0x3, foge_image0x4, foge_image0x5},
		{foge_image1x0, foge_image1x1, foge_image1x2, foge_image1x3, foge_image1x4, foge_image1x5},
		{foge_image2x0, foge_image2x1, foge_image2x2, foge_image2x3, foge_image2x4, foge_image2x5},
		{foge_image3x0, foge_image3x1, foge_image3x2, foge_image3x3, foge_image3x4, foge_image3x5},
		{foge_image4x0, foge_image4x1, foge_image4x2, foge_image4x3, foge_image4x4, foge_image4x5},
		{foge_image5x0, foge_image5x1, foge_image5x2, foge_image5x3, foge_image5x4, foge_image5x5},
		{foge_image6x0, foge_image6x1, foge_image6x2, foge_image6x3, foge_image6x4, foge_image6x5},
		{foge_image7x0, foge_image7x1, foge_image7x2, foge_image7x3, foge_image7x4, foge_image7x5},
		{foge_image8x0, foge_image8x1, foge_image8x2, foge_image8x3, foge_image8x4, foge_image8x5},
		{foge_image9x0, foge_image9x1, foge_image9x2, foge_image9x3, foge_image9x4, foge_image9x5},
	};
	memcpy(widget_imagens_global, widget_imagens, sizeof(widget_imagens));

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			char str_tmp[40];

			switch (m.matriz[j][i])
			{
			case FANTASMA:
				sprintf(str_tmp, "Foge/imgs/monstro_1.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens[i][j]), str_tmp);
				break;
			case HEROI:
				sprintf(str_tmp, "Foge/imgs/pac.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens[i][j]), str_tmp);
				break;
			case PILULA:
				sprintf(str_tmp, "Foge/imgs/fruta.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens[i][j]), str_tmp);
				break;
			case PAREDE_VERTICAL:
				sprintf(str_tmp, "Foge/imgs/parede.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens[i][j]), str_tmp);
				break;
			case PAREDE_HORIZONTAL:
				sprintf(str_tmp, "Foge/imgs/parede.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens[i][j]), str_tmp);
				break;
			case VAZIO:
				sprintf(str_tmp, "Foge/imgs/mapa.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens[i][j]), str_tmp);
				break;
			}
		}
	}
	char texto_edit[10];
	sprintf(texto_edit, "Poderes: %d", tempilula);

	gtk_label_set_text(GTK_LABEL(foge_text_power), (const gchar *)texto_edit);

	gtk_widget_show(foge_window1);

	gtk_main();

	return EXIT_SUCCESS;
}

char *parede = "Foge/imgs/parede.png";

char desenhoparede[4][7] = {
	{"......"},
	{"......"},
	{"......"},
	{"......"}};

char desenhofantasma[4][7] = {
	{" .-.  "},
	{"| OO| "},
	{"|   | "},
	{"'^^^' "}};

char desenhoheroi[4][7] = {
	{" .--. "},
	{"/ _.-'"},
	{"\\  '-."},
	{" '--' "}};

char desenhopilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}};

char desenhovazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}};

void atualiza_mapa()
{
	char texto_edit[10];
	sprintf(texto_edit, "Poderes: %d", tempilula);
	gtk_label_set_text(GTK_LABEL(foge_text_power), (const gchar *)texto_edit);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			char str_tmp[40];

			switch (m.matriz[j][i])
			{
			case FANTASMA:
				sprintf(str_tmp, "Foge/imgs/monstro_1.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens_global[i][j]), str_tmp);
				break;
			case HEROI:
				sprintf(str_tmp, "Foge/imgs/pac.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens_global[i][j]), str_tmp);
				break;
			case PILULA:
				sprintf(str_tmp, "Foge/imgs/fruta.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens_global[i][j]), str_tmp);
				break;
			case PAREDE_VERTICAL:
				sprintf(str_tmp, "Foge/imgs/parede.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens_global[i][j]), str_tmp);
				break;
			case PAREDE_HORIZONTAL:
				sprintf(str_tmp, "Foge/imgs/parede.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens_global[i][j]), str_tmp);
				break;
			case VAZIO:
				sprintf(str_tmp, "Foge/imgs/mapa.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens_global[i][j]), str_tmp);
				break;
			case EXPLOSAO:
				sprintf(str_tmp, "Foge/imgs/explosao.png");
				gtk_image_set_from_file(GTK_IMAGE(widget_imagens_global[i][j]), str_tmp);
				break;
			}
		}
	}

	POSICAO pos;
	if (!encontramapa(&m, &pos, HEROI))
	{
		FogeWindow2(0, 0, 2);
	}
	if (!encontramapa(&m, &pos, FANTASMA))
	{
		FogeWindow2(0, 0, 1);
	}
}
void on_foge_button_left_clicked(GtkButton *b, gpointer user_data)
{
	move(ESQUERDA);
	fantasmas();
	atualiza_mapa();
}

void on_foge_button_right_clicked(GtkButton *b, gpointer user_data)
{
	move(DIREITA);
	fantasmas();
	atualiza_mapa();
}

void on_foge_button_up_clicked(GtkButton *b, gpointer user_data)
{
	move(CIMA);
	fantasmas();
	atualiza_mapa();
}

void on_foge_button_down_clicked(GtkButton *b, gpointer user_data)
{
	move(BAIXO);
	fantasmas();
	atualiza_mapa();
}

void on_foge_button_bomb_clicked(GtkButton *b, gpointer user_data)
{
	explodepilula();
	atualiza_mapa();

	mapa_pos_explosao();
	g_timeout_add(500, delay_atualiza_mapa, NULL);
}

void imprimeparte(char desenho[4][7], int parte)
{
	printf("%s", desenho[parte]);
}

void imprimemapa(MAPA *m)
{
	for (int i = 0; i < 5; i++)
	{

		for (int parte = 0; parte < 4; parte++)
		{
			for (int j = 0; j < m->colunas; j++)
			{

				switch (m->matriz[i][j])
				{
				case FANTASMA:
					imprimeparte(desenhofantasma, parte);
					break;
				case HEROI:
					imprimeparte(desenhoheroi, parte);
					break;
				case PILULA:
					imprimeparte(desenhopilula, parte);
					break;
				case PAREDE_VERTICAL:
				case PAREDE_HORIZONTAL:
					imprimeparte(desenhoparede, parte);
					break;
				case VAZIO:
					imprimeparte(desenhovazio, parte);
					break;
				}
			}
			printf("\n");
		}
	}
}

GtkWidget *foge_window02;
int FogeWindow2(int argc, char *argv[], int resultado)
{
	GtkWidget *foge_fixed3;
	GtkWidget *foge_fixed4;
	GtkWidget *foge_button_yes;
	GtkWidget *foge_button_no;
	GtkWidget *foge_text_end;
	GtkWidget *foge_text_num;
	GtkWidget *foge_text9;
	GtkBuilder *builder;

	gtk_init(&argc, &argv); // init Gtk

	builder = gtk_builder_new_from_file("Foge/FogeWindow2.glade");

	foge_window02 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_window02"));

	g_signal_connect(foge_window02, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_builder_connect_signals(builder, NULL);

	foge_fixed3 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_fixed4"));
	foge_fixed4 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_fixed3"));
	foge_button_yes = GTK_WIDGET(gtk_builder_get_object(builder, "foge_button_yes"));
	foge_button_no = GTK_WIDGET(gtk_builder_get_object(builder, "foge_button_no"));
	foge_text_end = GTK_WIDGET(gtk_builder_get_object(builder, "foge_text_end"));
	foge_text_num = GTK_WIDGET(gtk_builder_get_object(builder, "foge_text_num"));
	foge_text9 = GTK_WIDGET(gtk_builder_get_object(builder, "foge_text9"));

	gtk_widget_set_name(foge_button_yes, "foge_button_yes");
	gtk_widget_set_name(foge_button_no, "foge_button_no");

	add_estilo("Foge/estilo_foge.css", foge_button_yes);
	add_estilo("Foge/estilo_foge.css", foge_button_no);

	gtk_widget_show(foge_window02);

	char texto_edit[10];
	if (resultado == 1)
	{
		sprintf(texto_edit, "Parabéns você ganhou !! \n Derrotou todos os monstros");
	}
	else
	{

		sprintf(texto_edit, "Não foi dessa vez !!\nInfelizmente o monstro te pegou");
	}

	gtk_label_set_text(GTK_LABEL(foge_text_end), (const gchar *)texto_edit);

	gtk_main();
	gtk_widget_destroy(foge_window02);

	return EXIT_SUCCESS;
}

void on_foge_button_yes_clicked(GtkButton *b, gpointer user_data)
{
	tempilula = 1;
	gtk_widget_destroy(foge_window1);
	gtk_widget_destroy(foge_window02);
	FogeWindow1(0, 0);
}

void on_foge_button_no_clicked(GtkButton *b, gpointer user_data)
{
	gtk_widget_destroy(foge_window1);
	gtk_widget_destroy(foge_window02);
}