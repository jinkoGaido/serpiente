#include "comida.hpp"

Comida::Comida(Mapa *mapa_bits, char icon)
{
	this->conf = this->global.configuracion("comida");
    this->icon = (this->conf["icon"].isString()) ? this->conf["icon"].asCString()[0] : '*';
	this->mapa_bits = mapa_bits;
}

Comida::~Comida()
{
}

void Comida::randomXY()
{
	do
	{
		this->verificar = 0;

		this->x = ((random() + time(NULL)) % (MAP_ANCHO - 2)) + 1;
		this->y = ((random() + time(NULL)) % (MAP_ALTO - 2)) + 2;

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

void Comida::mostrar()
{
	attron(A_BOLD);
	mvaddch(this->y, this->x, this->icon);
	attroff(A_BOLD);
}