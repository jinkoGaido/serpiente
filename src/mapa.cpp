#include "mapa.hpp"

Mapa::Mapa(string ruta)
{
	this->conf = this->global.configuracion("mapa");

    this->icon = (this->conf["icon"].isString()) ? this->conf["icon"].asCString()[0] : '#';

	this->cargarMapa(ruta);
}

Mapa::~Mapa()
{
}

void Mapa::dibujarMapa()
{
	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			if (this->eje.x != 0 && this->eje.y != 0)
			{
				mvaddch(this->eje.y[cont2][cont], this->eje.x[cont2][cont], this->icon);
			}
		}
	}
	refresh();
}

void Mapa::borrarMapa()
{
	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			if (this->eje.x != 0 && this->eje.y != 0)
			{
				mvaddch(this->eje.y[cont2][cont], this->eje.x[cont2][cont], ' ');
			}
		}
	}
	refresh();
}

void Mapa::cargarMapa(string ruta)
{
	FILE *archivo_map;
	int ch;
	int cont_x = 0;
	int cont_y = 0;

	archivo_map = fopen(ruta.c_str(), "r");

	if (archivo_map != NULL)
	{
		this->borrarMapa();

		int pos = ruta.find("/");
		this->nombre = ruta.substr(pos + 1, ruta.size());
		pos = this->nombre.find(".");
		this->nombre = this->nombre.substr(0, pos);

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
					this->eje.x[cont_y][cont_x] = cont_x + MAP_INI_X;
					this->eje.y[cont_y][cont_x] = cont_y + MAP_INI_Y;
				}
				else
				{
					this->eje.x[cont_y][cont_x] = 0;
					this->eje.y[cont_y][cont_x] = 0;
				}
			}
		}
	}

	fclose(archivo_map);
}

string Mapa::obtenerNombre()
{
	return this->nombre;
}