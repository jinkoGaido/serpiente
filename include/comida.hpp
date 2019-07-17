#include "mapa.hpp"

#ifndef _COMIDA_LIB
#define _COMIDA_LIB

class Comida
{
private:
    Mapa *mapa_bits;

public:
    int x;
    int y;
    int verificar = 0;
    Comida(Mapa *mapa_bits);
    ~Comida();

    void randomXY(void);
};

#endif