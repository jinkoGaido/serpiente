#include "comida.hpp"

Comida::Comida(Mapa *mapa_bits)
{
	this->conf = this->global.configuracion("comida");
	this->icon = (this->conf["icon"].isString()) ? this->conf["icon"].asCString()[0] : '*';
	this->mapa_bits = mapa_bits;
	this->mostrar();
}

Comida::~Comida()
{
}

void Comida::randomXY()
{
	do
	{
		this->verificar = 0;

		this->x = ((random() + time(NULL)) % (MAP_ANCHO - 2)) + MAP_INI_X;
		this->y = ((random() + time(NULL)) % (MAP_ALTO - 2)) + MAP_INI_Y;

		for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
		{
			for (int cont = 0; cont < MAP_ANCHO; cont++)
			{
				if (this->x == this->mapa_bits->eje.x[cont2][cont] && this->y == this->mapa_bits->eje.y[cont2][cont])
				{
					this->verificar = 1;
					cont2 = MAP_ALTO;
					cont = MAP_ANCHO;
				}
			}
		}

	} while (verificar);
}

void Comida::dibujar()
{
	if (this->visible)
	{
		attron(A_BOLD);
		mvaddch(this->y, this->x, this->icon);
		attroff(A_BOLD);
	}
}

void Comida::borrar()
{
	this->x = 0;
	this->y = 0;
	mvaddch(this->y, this->x, ' ');
}

void Comida::mostrar()
{
	this->visible = true;
}

void Comida::ocultar()
{
	this->visible = false;
	this->borrar();
}