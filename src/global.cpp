#include <unistd.h>

#include <ncurses.h>

#include "kbhit.c"

#include "global.hpp"

Global::Global()
{
}

Global::~Global()
{
}

void Global::capturarDireccion()
{
	int continua = true;

	if (kbhit())
	{
		char ctr;
		move(23, 79);
		do
		{
			ctr = getch();
			switch (ctr)
			{
			case 'W':
			case 'w':
				this->direccion_nueva = ARRIBA;
				continua = false;
				break;
			case 'S':
			case 's':
				this->direccion_nueva = ABAJO;
				continua = false;
				break;
			case 'D':
			case 'd':
				this->direccion_nueva = DERECHA;
				continua = false;
				break;
			case 'A':
			case 'a':
				this->direccion_nueva = IZQUIERDA;
				continua = false;
				break;
			case 'p':
			case 'P':
				this->direccion_nueva = FINAL;
				continua = false;
				break;

			default:
				break;
			}
		} while (continua);
	}
	//validacion de datos: no se validara un cursor inverso
	//al cursor pulsado anteriormente
	if ((this->direccion_nueva == IZQUIERDA && this->direccion_actual == DERECHA) ||
		(this->direccion_nueva == DERECHA && this->direccion_actual == IZQUIERDA))
	{
		this->direccion_nueva = this->direccion_actual;
	}
	if ((this->direccion_nueva == ARRIBA && this->direccion_actual == ABAJO) ||
		(this->direccion_nueva == ABAJO && this->direccion_actual == ARRIBA))
	{
		this->direccion_nueva = this->direccion_actual;
	}
}

void Global::retardo(int n)
{
	usleep(n * 1000);
}