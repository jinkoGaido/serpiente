#include <iostream>
#include <unistd.h>
#include <time.h>

#include <ncurses.h>

#include "mapa.hpp"
#include "comida.hpp"
#include "juego.hpp"

using namespace std;

int *randomComidaXY(int *, int *);

const char icon_serpiente = '*';
const char icon_comida = '*';
const char icon_mapa = '#';

Mapa mapa_bits(icon_mapa);
Comida comida(&mapa_bits, icon_comida);
Serpiente serpiente(icon_serpiente);
Juego juego(&mapa_bits, &comida, &serpiente);

int main(void)
{
	mapa_bits.testMap();

	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	attron(A_BOLD);
	mapa_bits.dibujarMap();
	comida.randomXY();

	refresh();

	juego.iniciar();

	erase();
	mvprintw(10, 32, "JUEGO TERMINADO");
	attroff(A_BOLD);
	getch();
	endwin();
	return 0;
}
