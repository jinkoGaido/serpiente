#ifndef _MAPA_LIB
#define _MAPA_LIB

const int MAP_INI_X = 0;
const int MAP_INI_Y = 0;
const int MAP_ANCHO = 78;
const int MAP_ALTO = 23;

struct map_coordenadas
{
	int x[MAP_ALTO][MAP_ANCHO];
	int y[MAP_ALTO][MAP_ANCHO];
};

class Mapa
{
private:
	char icon;

public:
	Mapa(char);
	~Mapa();

	map_coordenadas eje;

	void testMap();
	void dibujarMap();
};

#endif