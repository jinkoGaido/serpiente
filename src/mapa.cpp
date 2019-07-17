#include <iostream>
#include <ncurses.h>

#include "../include/mapa.hpp"

Mapa::Mapa(void)
{
	FILE *archivo_map;

	archivo_map = fopen("data/mapa.txt", "r");

	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			fscanf(archivo_map, "%i,", &eje.x[cont2][cont]);
		}
		fscanf(archivo_map, "\n");
	}
	rewind(archivo_map);

	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			fscanf(archivo_map, "%i,", &eje.y[cont2][cont]);
		}
		fscanf(archivo_map, "\n");
	}

	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			if (eje.x[cont2][cont] == 1 && eje.y[cont2][cont] == 1)
			{
				eje.x[cont2][cont] = cont + 1;
				eje.y[cont2][cont] = cont2 + 1;
			}
		}
	}

	fclose(archivo_map);
}

Mapa::~Mapa()
{
}

void Mapa::testMap(void)
{
	FILE *buffer_x;

	buffer_x = fopen("data/buffer_x.txt", "w");

	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			fprintf(buffer_x, "%i,", eje.x[cont2][cont]);
		}
		fprintf(buffer_x, "\n");
	}

	FILE *buffer_y;

	buffer_y = fopen("data/buffer_y.txt", "w");

	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			fprintf(buffer_y, "%i,", eje.y[cont2][cont]);
		}
		fprintf(buffer_y, "\n");
	}

	fclose(buffer_x);
	fclose(buffer_y);
}

void Mapa::dibujarMap(const char *icon)
{
	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			if (eje.x != 0 && eje.y != 0)
			{
				mvprintw(eje.y[cont2][cont], eje.x[cont2][cont], icon);
			}
		}
	}
}
