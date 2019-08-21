#include "mapa.hpp"

Mapa::Mapa(string ruta)
{
	this->conf = this->global.configuracion("mapa");

	this->icon_muro = (this->conf["icon_muro"].isString()) ? this->conf["icon_muro"].asCString()[0] : '#';
	this->icon_borde = (this->conf["icon_borde"].isString()) ? this->conf["icon_borde"].asCString()[0] : '.';

	for (int i = 0; i < TUNEL_ANCHO - 1; i++)
	{
		this->x_tunel_portal.push_back(TUNEL_INI_X + i + 1);
	}

	this->y_tunel_portal = TUNEL_INI_Y;

	this->cargarTunel();
	this->cargarMapa(ruta);
}

Mapa::~Mapa()
{
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

void Mapa::dibujarMapa()
{
	for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
	{
		for (int cont = 0; cont < MAP_ANCHO; cont++)
		{
			if (this->eje.x != 0 && this->eje.y != 0)
			{
				mvaddch(this->eje.y[cont2][cont], this->eje.x[cont2][cont], this->icon_muro);
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

void Mapa::dibujarBorde()
{
	for (int i = 0; i < MAP_ANCHO; i++)
	{
		mvaddch(MAP_INI_Y, MAP_INI_X + i, this->icon_borde);
		mvaddch(MAP_INI_Y + MAP_ALTO - 1, MAP_INI_X + i, this->icon_borde);
	}

	for (int i = 0; i < MAP_ALTO; i++)
	{
		mvaddch(MAP_INI_Y + i, MAP_INI_X, this->icon_borde);
		mvaddch(MAP_INI_Y + i, MAP_INI_X + MAP_ANCHO, this->icon_borde);
	}
}

void Mapa::cargarTunel()
{
	FILE *archivo_tunel;
	char ch;
	int cont_x = 0;
	int cont_y = 0;

	archivo_tunel = fopen("data/tunel.sp", "r");

	if (archivo_tunel != NULL)
	{
		while ((ch = fgetc(archivo_tunel)) != EOF)
		{
			if (cont_x < TUNEL_ANCHO && cont_y < TUNEL_ALTO)
			{
				this->icon_tunel[cont_y][cont_x] = (ch != '0') ? ch : ' ';
				cont_x++;
			}
			else
			{
				cont_x = 0;
				cont_y++;
			}
		}

		for (int cont_y = 0; cont_y < TUNEL_ALTO; cont_y++)
		{
			for (int cont_x = 0; cont_x < TUNEL_ANCHO; cont_x++)
			{
				this->x_tunel[cont_y][cont_x] = cont_x + TUNEL_INI_X;
				this->y_tunel[cont_y][cont_x] = cont_y + TUNEL_INI_Y;
			}
		}
	}

	fclose(archivo_tunel);
}

void Mapa::dibujarTunel()
{
	for (int cont2 = 0; cont2 < TUNEL_ALTO; cont2++)
	{
		for (int cont = 0; cont < TUNEL_ANCHO; cont++)
		{
			mvaddch(this->y_tunel[cont2][cont], this->x_tunel[cont2][cont], this->icon_tunel[cont2][cont]);
		}
	}

	this->tunel_visto = true;
	refresh();
}

void Mapa::borrarTunel()
{
	for (int cont2 = 0; cont2 < TUNEL_ALTO; cont2++)
	{
		for (int cont = 0; cont < TUNEL_ANCHO; cont++)
		{
			mvaddch(this->y_tunel[cont2][cont], this->x_tunel[cont2][cont], ' ');
		}
	}

	this->tunel_visto = false;
	refresh();
}

string Mapa::obtenerNombre()
{
	return this->nombre;
}