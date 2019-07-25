#include <unistd.h>

#include <ncurses.h>

#include "kbhit.c"

#include "global.hpp"

Global::Global()
{
	this->direccion_nueva = COMANDO_DERECHA;
}

Global::~Global()
{
}

void Global::capturarDireccion()
{
	int continua = true;

	if (kbhit())
	{
		int ctr;
		move(23, 79);
		do
		{
			ctr = getch();
			switch (ctr)
			{
			case TECLA_ARRIBA:
			case TECLA_ARRIBA_W:
			case TECLA_ARRIBA_MW:
				this->direccion_nueva = COMANDO_ARRIBA;
				continua = false;
				break;
			case TECLA_ABAJO:
			case TECLA_ABAJO_S:
			case TECLA_ABAJO_MS:
				this->direccion_nueva = COMANDO_ABAJO;
				continua = false;
				break;
			case TECLA_DERECHA:
			case TECLA_DERECHA_D:
			case TECLA_DERECHA_MD:
				this->direccion_nueva = COMANDO_DERECHA;
				continua = false;
				break;
			case TECLA_IZQUIERDA:
			case TECLA_IZQUIERDA_A:
			case TECLA_IZQUIERDA_MA:
				this->direccion_nueva = COMANDO_IZQUIERDA;
				continua = false;
				break;
			case TECLA_FINAL:
			case TECLA_FINAL_M:
				this->direccion_nueva = FINAL;
				continua = false;
				break;

			default:
				this->direccion_nueva = this->direccion_actual;
				continua = false;
				break;
			}
		} while (continua);
	}
	//validacion de datos: no se validara un cursor inverso
	//al cursor pulsado anteriormente
	if ((this->direccion_nueva == COMANDO_IZQUIERDA && this->direccion_actual == COMANDO_DERECHA) ||
		(this->direccion_nueva == COMANDO_DERECHA && this->direccion_actual == COMANDO_IZQUIERDA))
	{
		this->direccion_nueva = this->direccion_actual;
	}
	if ((this->direccion_nueva == COMANDO_ARRIBA && this->direccion_actual == COMANDO_ABAJO) ||
		(this->direccion_nueva == COMANDO_ABAJO && this->direccion_actual == COMANDO_ARRIBA))
	{
		this->direccion_nueva = this->direccion_actual;
	}
}

void Global::retardo(int n)
{
	usleep(n * 1000);
}