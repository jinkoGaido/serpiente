#include <ncurses.h>

#include "serpiente.hpp"

Serpiente::Serpiente(char icon)
{
    this->icon = icon;
}

Serpiente::~Serpiente()
{
}

void Serpiente::mover()
{
    mvprintw(this->y[this->largo], this->x[this->largo], " "); //borrar el ultimo segmento del gusano

    //traspazo de datos en cola
    //para tener la trayectoria del gusano
    for (int cont = LARGO_MAX_SERPIENTE; cont > 0; cont--)
    {
        this->x[cont] = this->x[cont - 1];
        this->y[cont] = this->y[cont - 1];
    }

    //mostrar gusano
    mvaddch(this->y[0], this->x[0], this->icon);

    refresh();
}

int Serpiente::si_come(int x_comida, int y_comida)
{
    int comio = false;

    if ((this->x[0] == x_comida) && (this->y[0] == y_comida))
    {
        this->largo++;
        if (this->velocidad > VEL_MAX)
            this->velocidad -= ACELERACION;

        comio = true;
    }
    return comio;
}

int Serpiente::si_choca(map_coordenadas map_eje)
{
    int choco = false;

    for (int cont2 = false; cont2 < MAP_ALTO; cont2++)
    {
        for (int cont = false; cont < MAP_ANCHO; cont++)
            if (this->x[0] == map_eje.x[cont2][cont] && this->y[0] == map_eje.y[cont2][cont])
            {
                choco = true;
                break;
            }
    }

    return choco;
}

int Serpiente::si_choca_con_el()
{
    int choco = false;

    //revisar el funcionamiento de este bloque
    for (int cont = false; cont < this->largo; cont++)
    {
        if ((this->x[0] == this->x[cont + 1] && this->y[0] == this->y[cont + 1]) && cont > 1)
        {
            choco = true;
            break;
        }
    }

    return choco;
}

void Serpiente::limite_map()
{
    //limites para que el gusano
    //traspase la pantalla
    if (this->x[0] == MAP_INI_X)
        this->x[0] = MAP_ANCHO + 1;

    if (this->x[0] == MAP_ANCHO + 2)
        this->x[0] = MAP_INI_X;

    if (this->y[0] == MAP_INI_Y)
        this->y[0] = MAP_ALTO + 1;

    if (this->y[0] == MAP_ALTO + 2)
        this->y[0] = MAP_INI_Y;
}

void Serpiente::cambiar_direccion(int &comando_actual, int &comando_nuevo)
{
    switch (comando_nuevo)
    {
    case COMANDO_ARRIBA:
        comando_actual = comando_nuevo;
        this->y[0]--;
        break;
    case COMANDO_ABAJO:
        comando_actual = comando_nuevo;
        this->y[0]++;
        break;
    case COMANDO_DERECHA:
        comando_actual = comando_nuevo;
        this->x[0]++;
        break;
    case COMANDO_IZQUIERDA:
        comando_actual = comando_nuevo;
        this->x[0]--;
        break;
    default:
        if (comando_actual == COMANDO_ARRIBA)
            this->y[0]--;
        if (comando_actual == COMANDO_ABAJO)
            this->y[0]++;
        if (comando_actual == COMANDO_DERECHA)
            this->x[0]++;
        if (comando_actual == COMANDO_IZQUIERDA)
            this->x[0]--;
    }
}
