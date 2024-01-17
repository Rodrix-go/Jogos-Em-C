#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

extern MAPA m;
extern POSICAO heroi;
extern int tempilula;

int acabou()
{
	POSICAO pos;

	int resultado = 0;
	resultado = (!encontramapa(&m, &pos, HEROI) ? 1 : 0);
	resultado = (!encontramapa(&m, &pos, FANTASMA) ? 2 : 0);

	return resultado;
}

int ehdirecao(char direcao)
{
	return direcao == ESQUERDA ||
		   direcao == CIMA ||
		   direcao == BAIXO ||
		   direcao == DIREITA;
}

void move(char direcao)
{

	int proximox = heroi.x;
	int proximoy = heroi.y;

	switch (direcao)
	{
	case ESQUERDA:
		proximoy--;
		break;
	case CIMA:
		proximox--;
		break;
	case BAIXO:
		proximox++;
		break;
	case DIREITA:
		proximoy++;
		break;
	}

	if (!podeandar(&m, HEROI, proximox, proximoy))
		return;

	if (ehpersonagem(&m, PILULA, proximox, proximoy))
	{
		tempilula++;
	}

	andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;
}

int praondefantasmavai(int xatual, int yatual,
					   int *xdestino, int *ydestino)
{

	int opcoes[4][2] = {
		{xatual, yatual + 1},
		{xatual + 1, yatual},
		{xatual, yatual - 1},
		{xatual - 1, yatual}};

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int posicao = rand() % 4;

		if (podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1]))
		{
			*xdestino = opcoes[posicao][0];
			*ydestino = opcoes[posicao][1];
			return 1;
		}
	}

	return 0;
}

void fantasmas()
{
	MAPA copia;

	copiamapa(&copia, &m);

	for (int i = 0; i < copia.linhas; i++)
	{
		for (int j = 0; j < copia.colunas; j++)
		{
			if (copia.matriz[i][j] == FANTASMA)
			{

				int xdestino;
				int ydestino;

				int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);

				if (encontrou)
				{
					andanomapa(&m, i, j, xdestino, ydestino);
				}
			}
		}
	}

	liberamapa(&copia);
}

void explodepilula2(int x, int y, int somax, int somay, int qtd, char efeito)
{

	if (qtd == 0)
		return;

	int novox = x + somax;
	int novoy = y + somay;

	if (!ehvalida(&m, novox, novoy))
		return;
	if (ehparede(&m, novox, novoy))
		return;

	m.matriz[novox][novoy] = efeito;
	explodepilula2(novox, novoy, somax, somay, qtd - 1, efeito);
}

void delay(int seconds)
{
	int mili_seconds = 1000 * seconds;

	clock_t start_time = clock();

	while (clock() < start_time + mili_seconds)
	{
		printf("%d\n", clock());
	};
}

void explodepilula()
{
	if (!tempilula)
		return;

	explodepilula2(heroi.x, heroi.y, 0, 1, 3, EXPLOSAO);
	explodepilula2(heroi.x, heroi.y, 0, -1, 3, EXPLOSAO);
	explodepilula2(heroi.x, heroi.y, 1, 0, 3, EXPLOSAO);
	explodepilula2(heroi.x, heroi.y, -1, 0, 3, EXPLOSAO);
	tempilula--;
}

void mapa_pos_explosao()
{
	explodepilula2(heroi.x, heroi.y, 0, 1, 3, VAZIO);
	explodepilula2(heroi.x, heroi.y, 0, -1, 3, VAZIO);
	explodepilula2(heroi.x, heroi.y, 1, 0, 3, VAZIO);
	explodepilula2(heroi.x, heroi.y, -1, 0, 3, VAZIO);
}

void jogo_foge()
{
	lemapa(&m);
	encontramapa(&m, &heroi, HEROI);

	do
	{
		printf("Pílula: %s\n", (tempilula ? "SIM" : "NÃO"));
		imprimemapa(&m);
		char comando;
		scanf(" %c", &comando);

		if (ehdirecao(comando))
			move(comando);
		if (comando == BOMBA)
			explodepilula();

		fantasmas();

	} while (!acabou());

	liberamapa(&m);
}