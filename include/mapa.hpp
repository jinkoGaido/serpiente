#include <iostream>
#include <vector>

#include <ncurses.h>
#include <jsoncpp/json/json.h>

#include "global.hpp"

#ifndef _MAPA_LIB
#define _MAPA_LIB

using namespace std;

const int MAP_INI_X = 0;
const int MAP_INI_Y = 1;
const int MAP_ANCHO = 79;
const int MAP_ALTO = 22;

const int TUNEL_INI_X = 34;
const int TUNEL_INI_Y = 17;
const int TUNEL_ANCHO = 7;
const int TUNEL_ALTO = 4;

const int ZONA_PORTAL_ENTRADA = -1;
const int ZONA_PORTAL_SALIDA = 1;

const int ENTRADA_PORTAL_SUPERIOR = MAP_INI_Y - ZONA_PORTAL_ENTRADA;
const int SALIDA_PORTAL_INFERIOR = MAP_ALTO + MAP_INI_Y - ZONA_PORTAL_SALIDA;

const int ENTRADA_PORTAL_INFERIOR = MAP_ALTO + MAP_INI_Y + ZONA_PORTAL_ENTRADA - 1;
const int SALIDA_PORTAL_SUPERIOR = MAP_INI_Y + ZONA_PORTAL_SALIDA - 1;

const int ENTRADA_PORTAL_IZQUIERDA = MAP_INI_X - ZONA_PORTAL_ENTRADA;
const int SALIDA_PORTAL_DERECHA = MAP_ANCHO + MAP_INI_X - ZONA_PORTAL_SALIDA;

const int ENTRADA_PORTAL_DERECHA = MAP_ANCHO + MAP_INI_X + ZONA_PORTAL_ENTRADA - 1;
const int SALIDA_PORTAL_IZQUIERDA = MAP_INI_X + ZONA_PORTAL_SALIDA;

const int SALIDA_TUNEL = MAP_ALTO * 10;

struct map_coordenadas
{
	int x[MAP_ALTO][MAP_ANCHO];
	int y[MAP_ALTO][MAP_ANCHO];
};

class Mapa
{
private:
	int x_tunel[TUNEL_ALTO][TUNEL_ANCHO];
	int y_tunel[TUNEL_ALTO][TUNEL_ANCHO];
	char icon_tunel[TUNEL_ALTO][TUNEL_ANCHO];

	int buffer_map[MAP_ALTO][MAP_ANCHO];

	char icon_muro;
	char icon_borde;
	string nombre;

	Global global;
	Json::Value conf;

public:
	Mapa(string);
	~Mapa();

	vector<int> x_tunel_portal;
	int y_tunel_portal;
	bool tunel_visto;
	map_coordenadas eje;

	void cargarMapa(string);
	void dibujarMapa();
	void borrarMapa();

	void dibujarBorde();

	void cargarTunel();
	void dibujarTunel();
	void borrarTunel();

	string obtenerNombre();
};

#endif