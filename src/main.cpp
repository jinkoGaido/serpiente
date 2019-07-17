#include <iostream>
#include <unistd.h>
#include <time.h>

#include <ncurses.h>

#include "../include/mapa.hpp"
#include "../include/comida.hpp"
#include "../include/juego.hpp"

using namespace std;

int *randomComidaXY(int *, int *);

Mapa mapa_bits;
Comida comida(&mapa_bits);
Juego juego(&mapa_bits, &comida);

int main(void)
{
	mapa_bits.testMap();

	initscr();
	curs_set(0);
	noecho();

	mapa_bits.dibujarMap("#");
	comida.randomXY();

	refresh();

	juego.iniciar();

	erase();
	mvprintw(10, 32, "JUEGO TERMINADO");
	getch();
	endwin();
	return 0;
}
