#include "mapa.hpp"

#ifndef _COMIDA_LIB
#define _COMIDA_LIB

class Comida
{
private:
    Mapa *mapa_bits;
    const char *icon;

public:
    int x;
    int y;
    int verificar = 0;
    Comida(Mapa *, const char *);
    ~Comida();

    void randomXY();
    void mostrar();
};

#endif