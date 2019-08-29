#include <unistd.h>
#include <fstream>

#include <ncurses.h>
#include <jsoncpp/json/json.h>
#include <panel.h>

#include "global.hpp"
#include "nivel.hpp"
#include "mapa.hpp"
#include "comida.hpp"
#include "serpiente.hpp"

#ifndef _JUEGO_LIB
#define _JUEGO_LIB

using namespace std;

class Juego
{
private:
	Nivel *nivel;
	Mapa *mapa;
	Comida *comida;
	Serpiente *serpiente;
	ifstream *fichero;
	string mensaje;
	PANEL *local_panel;

	Global global;
	Json::Value conf;

	int puntos;
	int vidas;
	int puntos_proximo_nivel;

	bool continua;

	int control();
	void actualizarTablero();
	void retardo(int);

public:
	Juego(Nivel *, Comida *, Serpiente *);
	~Juego();

	void iniciar();
	void final();
	void terminarJuego();
	void mensajefinal();
};
#endif