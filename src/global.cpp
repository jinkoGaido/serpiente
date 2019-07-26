#include <unistd.h>

#include <ncurses.h>

#include "kbhit.c"

#include "global.hpp"

Global::Global()
{
	this->comando_nuevo = COMANDO_DERECHA;
}

Global::~Global()
{
}

bool Global::capturarComando()
{
	bool continuar_juego = true;

	if (kbhit())
	{
		int ctr;
		move(23, 79);

		ctr = getch();
		switch (ctr)
		{
		case TECLA_ARRIBA:
			this->comando_nuevo = COMANDO_ARRIBA;
			break;
		case TECLA_ABAJO:
			this->comando_nuevo = COMANDO_ABAJO;
			break;
		case TECLA_DERECHA:
			this->comando_nuevo = COMANDO_DERECHA;
			break;
		case TECLA_IZQUIERDA:
			this->comando_nuevo = COMANDO_IZQUIERDA;
			break;
		case TECLA_FINAL:
			continuar_juego = false;
			break;

		default:
			//this->comando_nuevo = this->comando_actual;
			break;
		}
		//validacion de datos: no se validara un cursor inverso
		//al cursor pulsado anteriormente
		if ((this->comando_nuevo == COMANDO_IZQUIERDA && this->comando_actual == COMANDO_DERECHA) ||
			(this->comando_nuevo == COMANDO_DERECHA && this->comando_actual == COMANDO_IZQUIERDA))
		{
			this->comando_nuevo = this->comando_actual;
		}
		if ((this->comando_nuevo == COMANDO_ARRIBA && this->comando_actual == COMANDO_ABAJO) ||
			(this->comando_nuevo == COMANDO_ABAJO && this->comando_actual == COMANDO_ARRIBA))
		{
			this->comando_nuevo = this->comando_actual;
		}
	}

	return continuar_juego;
}

void Global::retardo(int n)
{
	usleep(n * 1000);
}