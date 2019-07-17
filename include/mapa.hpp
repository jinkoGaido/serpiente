#ifndef _MAPA_LIB
#define _MAPA_LIB

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

public:
    Mapa(void);
    ~Mapa();

    map_coordenadas eje;

    void testMap(void);
    void dibujarMap(const char *icon);
};

#endif