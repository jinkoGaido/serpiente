#include <time.h>
#include <stdlib.h>

#include <ncurses.h>
#include <jsoncpp/json/json.h>

#include "global.hpp"
#include "mapa.hpp"

#ifndef _COMIDA_LIB
#define _COMIDA_LIB

class Comida
{
private:
    Mapa *mapa_bits;
    char icon;
    bool visible;
    
    Global global;
	Json::Value conf;

public:
    int x;
    int y;
    int verificar;
    Comida(Mapa *);
    ~Comida();

    void randomXY();
    void dibujar();
    void borrar();
    void mostrar();
    void ocultar();
};

#endif