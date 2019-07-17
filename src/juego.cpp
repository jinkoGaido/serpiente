#include <ncurses.h>
#include <unistd.h>

#include "../src/kbhit.c"

#include "../include/juego.hpp"

Juego::Juego(Mapa *mapa_bits, Comida *comida)
{
    this->mapa_bits = mapa_bits;
    this->comida = comida;
}

Juego::~Juego()
{
}

int Juego::control(void)
{
    char ctr;
    do
    {
        move(23, 79);
        ctr = getch();
        if (ctr == 'A')
            return 1;
        if (ctr == 'B')
            return 2;
        if (ctr == 'C')
            return 3;
        if (ctr == 'D')
            return 4;
        if ((ctr == 'W') || (ctr == 'w'))
            return 10;
        if ((ctr == 'S') || (ctr == 's'))
            return 11;
        if ((ctr == 'D') || (ctr == 'd'))
            return 12;
        if ((ctr == 'A') || (ctr == 'a'))
            return 13;
        if (ctr == 'p')
            return 0;
    } while (1);
}

void Juego::retardo(int n)
{
    usleep(n * 1000);
}

void Juego::iniciar(void)
{
    while (final)
    {
        this->comida->verificar = 0;
        mvprintw(this->comida->y, this->comida->x, "*");

        if (kbhit())
        {
            t_control = control();
            //validacion de datos: no se validara un cursor inverso
            //al cursor pulsado anteriormente
            if ((t_control == 4 && aux == 3) || (t_control == 3 && aux == 4))
            {
                t_control = aux;
            }
            if ((t_control == 1 && aux == 2) || (t_control == 2 && aux == 1))
            {
                t_control = aux;
            }
        }

        switch (t_control)
        {
        case 0:
            final = 0;
            break;
        case 1:
            aux = t_control;
            y_serpiente[0]--;
            break;
        case 2:
            aux = t_control;
            y_serpiente[0]++;
            break;
        case 3:
            aux = t_control;
            x_serpiente[0]++;
            break;
        case 4:
            aux = t_control;
            x_serpiente[0]--;
            break;
        default:
            if (aux == 1)
                y_serpiente[0]--;
            if (aux == 2)
                y_serpiente[0]++;
            if (aux == 3)
                x_serpiente[0]++;
            if (aux == 4)
                x_serpiente[0]--;
        }
        //limites para que el gusano
        //traspase la pantalla
        if (x_serpiente[0] == 0)
            x_serpiente[0] = 78;
        if (x_serpiente[0] == 79)
            x_serpiente[0] = 1;
        if (y_serpiente[0] == 0)
            y_serpiente[0] = 23;
        if (y_serpiente[0] == 24)
            y_serpiente[0] = 1;

        mvprintw(y_serpiente[largo_g], x_serpiente[largo_g], " "); //borrar el ultimo segmento del gusano
        //traspazo de datos en cola
        //para tener la trayectoria del gusano
        for (int cont = LARGO_MAX_G; cont > 0; cont--)
        {
            x_serpiente[cont] = x_serpiente[cont - 1];
            y_serpiente[cont] = y_serpiente[cont - 1];
        }
        //mostrar gusano
        mvprintw(y_serpiente[0], x_serpiente[0], "*");
        refresh();

        //velocidad de desplazamiento del gusano
        retardo(velocidad);

        //verificar si el gusano esta en la misma posicion x y del alimento
        if ((x_serpiente[0] == this->comida->x) && (y_serpiente[0] == this->comida->y))
        {
            largo_g++;
            if (velocidad > VEL_MAX)
                velocidad -= ACELERACION;

            this->comida->randomXY();
        }

        //revisar el funcionamiento de este bloque
        for (int cont = 0; cont < largo_g; cont++)
        {
            if (largo_g == largo_g + 1)
            {
                if ((x_serpiente[0] == x_serpiente[cont + 1] && y_serpiente[0] == y_serpiente[cont + 1]) && cont > 0)
                {
                    t_control = 0;
                    break;
                }
            }
        }

        for (int cont2 = 0; cont2 < MAP_ALTO; cont2++)
        {
            for (int cont = 0; cont < MAP_ANCHO; cont++)
                if (x_serpiente[0] == this->mapa_bits->eje.x[cont2][cont] && y_serpiente[0] == this->mapa_bits->eje.y[cont2][cont])
                {
                    t_control = 0;
                    break;
                }
        }
    }
}