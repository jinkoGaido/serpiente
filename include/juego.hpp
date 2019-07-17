#include "mapa.hpp"
#include "comida.hpp"

#ifndef _JUEGO_LIB
#define _JUEGO_LIB

const int LARGO_INI_G = 2;
const int LARGO_MAX_G = 99;
const int VEL_INI = 200;
const int VEL_MAX = 100;
const int ACELERACION = 10;

class Juego
{
private:
    Mapa *mapa_bits;
    Comida *comida;

    int control(void);
    void retardo(int n);

public:
    int final = 1;
    int aux;
    int t_control = 4;
    int velocidad = VEL_INI;
    int largo_g = LARGO_INI_G;
    int x_serpiente[100] = {37};
    int y_serpiente[100] = {18};

    Juego(Mapa *mapa_bits, Comida *comida);
    ~Juego();

    void iniciar(void);
};
#endif