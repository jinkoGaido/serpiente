#include <ncurses.h>

#include "juego.hpp"

Juego::Juego(Mapa *mapa_bits, Comida *comida)
{
	this->mapa_bits = mapa_bits;
	this->comida = comida;
}

Juego::~Juego()
{
}

void Juego::iniciar(void)
{
	while (final)
	{
		this->comida->mostrar();

		this->global.capturarDireccion();

		switch (this->global.direccion_nueva)
		{
		case FINAL:
			final = 0;
			break;
		case ARRIBA:
			this->global.direccion_actual = this->global.direccion_nueva;
			y_serpiente[0]--;
			break;
		case ABAJO:
			this->global.direccion_actual = this->global.direccion_nueva;
			y_serpiente[0]++;
			break;
		case DERECHA:
			this->global.direccion_actual = this->global.direccion_nueva;
			x_serpiente[0]++;
			break;
		case IZQUIERDA:
			this->global.direccion_actual = this->global.direccion_nueva;
			x_serpiente[0]--;
			break;
		default:
			if (this->global.direccion_actual == ARRIBA)
				y_serpiente[0]--;
			if (this->global.direccion_actual == ABAJO)
				y_serpiente[0]++;
			if (this->global.direccion_actual == DERECHA)
				x_serpiente[0]++;
			if (this->global.direccion_actual == IZQUIERDA)
				x_serpiente[0]--;
		}
		//limites para que el gusano
		//traspase la pantalla
		if (x_serpiente[0] == MAP_INI_X)
			x_serpiente[0] = MAP_ANCHO;

		if (x_serpiente[0] == MAP_ANCHO)
			x_serpiente[0] = MAP_INI_X;

		if (y_serpiente[0] == MAP_INI_Y)
			y_serpiente[0] = MAP_ALTO;

		if (y_serpiente[0] == MAP_ALTO)
			y_serpiente[0] = MAP_INI_Y;

		mvprintw(y_serpiente[largo_g], x_serpiente[largo_g], " "); //borrar el ultimo segmento del gusano
		//traspazo de datos en cola
		//para tener la trayectoria del gusano
		for (int cont = LARGO_MAX_G; cont > 0; cont--)
		{
			x_serpiente[cont] = x_serpiente[cont - 1];
			y_serpiente[cont] = y_serpiente[cont - 1];
		}
		//mostrar gusano
		mvprintw(y_serpiente[0], x_serpiente[0], "*");
		refresh();

		//velocidad de desplazamiento del gusano
		this->global.retardo(velocidad);

		//verificar si el gusano esta en la misma posicion x y del alimento
		if ((x_serpiente[0] == this->comida->x) && (y_serpiente[0] == this->comida->y))
		{
			largo_g++;
			if (velocidad > VEL_MAX)
				velocidad -= ACELERACION;

			this->comida->randomXY();
		}

		//revisar el funcionamiento de este bloque
		for (int cont = 0; cont < largo_g; cont++)
		{
			if (largo_g == largo_g + 1)
			{
				if ((x_serpiente[0] == x_serpiente[cont + 1] && y_serpiente[0] == y_serpiente[cont + 1]) && cont > 0)
				{
					this->global.direccion_nueva = 0;
					break;
				}
			}
		}

		for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
		{
			for (int cont = 0; cont < MAP_ANCHO; cont++)
				if (x_serpiente[0] == this->mapa_bits->eje.x[cont2][cont] && y_serpiente[0] == this->mapa_bits->eje.y[cont2][cont])
				{
					this->global.direccion_nueva = 0;
					break;
				}
		}
	}
}