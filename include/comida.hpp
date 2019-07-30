#include "mapa.hpp"

#ifndef _COMIDA_LIB
#define _COMIDA_LIB

class Comida
{
private:
    Mapa *mapa_bits;
    char icon;

public:
    int x;
    int y;
    int verificar;
    Comida(Mapa *, char);
    ~Comida();

    void randomXY();
    void mostrar();
};

#endif