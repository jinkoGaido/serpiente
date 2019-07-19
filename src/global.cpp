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
	int seg = 1;

	if (kbhit())
	{
		char ctr;
		//move(23, 79);
		do
		{
			ctr = getch();
			switch (ctr)
			{
			case 'W':
			case 'w':
				this->direccion_nueva = ARRIBA;
				seg = 0;
				break;
			case 'S':
			case 's':
				this->direccion_nueva = ABAJO;
				seg = 0;
				break;
			case 'D':
			case 'd':
				this->direccion_nueva = DERECHA;
				seg = 0;
				break;
			case 'A':
			case 'a':
				this->direccion_nueva = IZQUIERDA;
				seg = 0;
				break;
			case 'p':
			case 'P':
				this->direccion_nueva = FINAL;
				seg = 0;
				break;

			default:
				break;
			}
		} while (seg);
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