#include <ncurses.h>

#include <unistd.h>

#include "global.hpp"
#include "nivel.hpp"
#include "mapa.hpp"
#include "comida.hpp"
#include "serpiente.hpp"

#ifndef _JUEGO_LIB
#define _JUEGO_LIB

const int PUNTOS_PROXIMO_NIVEL = 3;

class Juego
{
private:
	Nivel *nivel;
	Mapa *mapa;
	Comida *comida;
	Serpiente *serpiente;
	Global global;

	int puntos;
	int vidas;

	bool continua;

	int control();
	void retardo(int);
	void actualizarTablero();

public:
	Juego(Nivel *, Comida *, Serpiente *);
	~Juego();

	void iniciar();
	void final();
	void terminarJuego();
	void pausa();
};
#endif