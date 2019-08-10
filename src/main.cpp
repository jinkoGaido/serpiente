#include <iostream>
#include <unistd.h>
#include <time.h>

#include <ncurses.h>

#include "mapa.hpp"
#include "comida.hpp"
#include "juego.hpp"
#include "nivel.hpp"
#include "global.hpp"

using namespace std;

const char icon_serpiente = '*';
const char icon_comida = '*';

int main(int argc, char *argv[])
{
	Nivel nivel;
	Mapa *mapa_bits = nivel.obtenerMapaActual();

	Comida comida(mapa_bits, icon_comida);
	Serpiente serpiente(icon_serpiente);
	Juego juego(&nivel, &comida, &serpiente);

	nivel.enlazar(&serpiente, &comida);

	initscr();
	curs_set(0);
	noecho();
	cbreak();
	keypad(stdscr, TRUE);

	if (has_colors() == FALSE)
	{
		endwin();
		printf("Tu terminar no soporta color\n");
		exit(1);
	}
	start_color();

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(1));

	//attron(A_BOLD);

	mapa_bits->dibujarMapa();
	comida.randomXY();

	juego.iniciar();

	juego.terminarJuego();
	return 0;
}
