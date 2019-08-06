#include <iostream>
#include <string.h>
#include <vector>
#include <dirent.h>

#include <ncurses.h>

#include "mapa.hpp"
#include "serpiente.hpp"
#include "comida.hpp"

#ifndef _NIVEL_LIB
#define _NIVEL_LIB

using namespace std;

class Nivel
{
private:
    Mapa *mapa;
    Serpiente *serpiente;
    Comida *comida;
    Global global;

    typedef vector <string> directorios;
    directorios directorios_mapa;
    vector <Mapa> lista_mapa;

    int numero_nivel_juego;

public:
    Nivel();
    ~Nivel();

    void enlazar(Serpiente *, Comida *);
    Mapa *obtenerMapaActual();
    bool avanzarNivel();
};

#endif