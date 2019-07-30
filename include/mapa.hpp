#ifndef _MAPA_LIB
#define _MAPA_LIB

const int MAP_INI_X = 0;
const int MAP_INI_Y = 2;
const int MAP_ANCHO = 78;
const int MAP_ALTO = 23;

const int ZONA_PORTAL_ENTRADA = 1;
const int ZONA_PORTAL_SALIDA = 0;

const int ENTRADA_PORTAL_SUPERIOR = MAP_INI_Y - ZONA_PORTAL_ENTRADA;
const int SALIDA_PORTAL_INFERIOR = MAP_ALTO + MAP_INI_Y - ZONA_PORTAL_SALIDA;

const int ENTRADA_PORTAL_INFERIOR = MAP_ALTO + MAP_INI_Y + ZONA_PORTAL_ENTRADA;
const int SALIDA_PORTAL_SUPERIOR = MAP_INI_Y + ZONA_PORTAL_SALIDA;

const int ENTRADA_PORTAL_IZQUIERDA = MAP_INI_X - ZONA_PORTAL_ENTRADA;
const int SALIDA_PORTAL_DERECHA = MAP_ANCHO + MAP_INI_X - ZONA_PORTAL_SALIDA;

const int ENTRADA_PORTAL_DERECHA = MAP_ANCHO + MAP_INI_X + ZONA_PORTAL_ENTRADA;
const int SALIDA_PORTAL_IZQUIERDA = MAP_INI_X + ZONA_PORTAL_SALIDA;

struct map_coordenadas
{
	int x[MAP_ALTO][MAP_ANCHO];
	int y[MAP_ALTO][MAP_ANCHO];
};

class Mapa
{
private:
	char icon;
	int buffer_map[MAP_ALTO][MAP_ANCHO];

public:
	Mapa(char);
	~Mapa();

	map_coordenadas eje;

	void dibujarMap();
};

#endif