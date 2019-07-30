#include <iostream>
#include <unistd.h>
#include <time.h>

#include <ncurses.h>

#include "mapa.hpp"
#include "comida.hpp"
#include "juego.hpp"

using namespace std;

const char icon_serpiente = '*';
const char icon_comida = '*';
const char icon_mapa = '#';

Mapa mapa_bits(icon_mapa);
Comida comida(&mapa_bits, icon_comida);
Serpiente serpiente(icon_serpiente);
Juego juego(&mapa_bits, &comida, &serpiente);

int main(int argc, char *argv[])
{
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

	mapa_bits.dibujarMap();
	comida.randomXY();
	attron(A_BOLD);
	refresh();

	juego.iniciar();

	juego.terminarJuego();
	return 0;
}
