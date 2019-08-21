#include "global.hpp"
#include "kbhit.c"

Global::Global()
{
	this->comando_nuevo = COMANDO_ARRIBA;
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

		ctr = getch();

		switch (ctr)
		{
		case KEY_UP:
			this->comando_nuevo = COMANDO_ARRIBA;
			break;
		case KEY_DOWN:
			this->comando_nuevo = COMANDO_ABAJO;
			break;
		case KEY_RIGHT:
			this->comando_nuevo = COMANDO_DERECHA;
			break;
		case KEY_LEFT:
			this->comando_nuevo = COMANDO_IZQUIERDA;
			break;
		case TECLA_PAUSA:
			this->pausa();
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

void Global::pausa()
{
	int ctrPausa;
	do
	{
		mvprintw(10, 36, "PAUSADO");
		ctrPausa = getch();

	} while (ctrPausa != TECLA_PAUSA);

	mvprintw(10, 36, "       ");
}

void Global::mensaje(int y, int x, const char *msg, bool opt)
{
	attron(A_BOLD);
	mvprintw(y, x, MENSAJE_BLANCO);
	mvprintw(y, x, msg);
	refresh();

	if (opt)
		getch();

	mvprintw(y, x, MENSAJE_BLANCO);
	refresh();
	attroff(A_BOLD);
}

void Global::mensaje(int y, int x, const char *msg, int seg)
{
	attron(A_BOLD);
	mvprintw(y, x, MENSAJE_BLANCO);
	mvprintw(y, x, msg);
	refresh();
	sleep(seg);
	mvprintw(y, x, MENSAJE_BLANCO);
	refresh();
	attroff(A_BOLD);
}

Json::Value Global::configuracion(string nombre)
{
	ifstream ifs("configuracion.json");
	Json::Reader reader;
	Json::Value configuracion;
	Json::Value conf;

	reader.parse(ifs, configuracion);

	conf = (nombre != "") ? configuracion[nombre] : configuracion;

	return conf;
}