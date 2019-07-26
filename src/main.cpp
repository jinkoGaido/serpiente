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

int main(void)
{
	mapa_bits.testMap();

	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr, TRUE);
	mapa_bits.dibujarMap();
	mapa_bits.testMap();
	comida.randomXY();
	attron(A_BOLD);
	refresh();

	juego.iniciar();

	erase();
	mvprintw(10, 32, "JUEGO TERMINADO");
	attroff(A_BOLD);
	getch();
	endwin();
	return 0;
}
