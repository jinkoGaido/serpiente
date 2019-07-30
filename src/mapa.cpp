#include <iostream>
#include <ncurses.h>

#include "mapa.hpp"

Mapa::Mapa(char icon)
{
	this->icon = icon;

	FILE *archivo_map;
	int ch;
	int cont_x = 0;
	int cont_y = 0;

	archivo_map = fopen("data/mapa1_lv1.mp", "r");

	while ((ch = fgetc(archivo_map)) != EOF)
	{
		if (cont_x < MAP_ANCHO && cont_y < MAP_ALTO)
		{
			this->buffer_map[cont_y][cont_x] = ch;
			cont_x++;
		}
		else
		{
			cont_x = 0;
			cont_y++;
		}
	}

	for (int cont_y = 0; cont_y < MAP_ALTO; cont_y++)
	{
		for (int cont_x = 0; cont_x < MAP_ANCHO; cont_x++)
		{
			if (this->buffer_map[cont_y][cont_x] != 48)
			{
				eje.x[cont_y][cont_x] = cont_x + MAP_INI_X;
				eje.y[cont_y][cont_x] = cont_y + MAP_INI_Y;
			}
			else
			{
				eje.x[cont_y][cont_x] = 0;
				eje.y[cont_y][cont_x] = 0;
			}
		}
	}

	fclose(archivo_map);
}

Mapa::~Mapa()
{
}

void Mapa::dibujarMap()
{
	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			if (eje.x != 0 && eje.y != 0)
			{
				mvaddch(eje.y[cont2][cont], eje.x[cont2][cont], this->icon);
			}
		}
	}
}
