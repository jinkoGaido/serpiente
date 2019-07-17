#include <time.h>
#include <stdlib.h>

#include "../include/comida.hpp"

Comida::Comida(Mapa *mapa_bits)
{
    this->mapa_bits = mapa_bits;
}

Comida::~Comida()
{
}

void Comida::randomXY(void)
{
    do
    {
        x = ((random() + time(NULL)) % (MAP_ANCHO - 2)) + 1;
        y = ((random() + time(NULL)) % (MAP_ALTO - 2)) + 2;

        for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
        {
            for (int cont = 0; cont < MAP_ANCHO; cont++)
            {
                if (x == this->mapa_bits->eje.x[cont2][cont] && y == this->mapa_bits->eje.y[cont2][cont])
                {
                    verificar = 1;
                    cont2 = MAP_ALTO;
                    cont = MAP_ANCHO;
                }
            }
        }

    } while (verificar);
}