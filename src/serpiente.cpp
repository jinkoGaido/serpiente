#include "serpiente.hpp"

Serpiente::Serpiente(Mapa *mapa_bits)
{
    this->mapa_bits = mapa_bits;

    this->conf = this->global.configuracion("serpiente");
    this->icon = (this->conf["icon"].isString()) ? this->conf["icon"].asCString()[0] : '*';
    this->vel_inicial = (this->conf["vel_inicial"].isInt()) ? this->conf["vel_inicial"].asInt() : 5;
    this->vel_maxima = (this->conf["vel_maxima"].isInt()) ? this->conf["vel_maxima"].asInt() : 20;
    this->largo_inicial = (this->conf["largo_inicial"].isInt()) ? this->conf["largo_inicial"].asInt() : 2;
    this->largo_maximo = (this->conf["largo_maximo"].isInt()) ? this->conf["largo_maximo"].asInt() : 99;
    this->aceleracion = (this->conf["aceleracion"].isInt()) ? this->conf["aceleracion"].asInt() : 1;
    this->si_aumenta = (this->conf["si_aumenta"].isInt()) ? this->conf["si_aumenta"].asInt() : 4;

    this->velocidad = this->vel_inicial;
    this->largo = this->largo_inicial;

    for (int i = 0; i < this->largo_inicial + 1; i++)
    {
        this->x.push_back(37);
        this->y.push_back(18);
    }
}

Serpiente::~Serpiente()
{
}

void Serpiente::mover()
{
    mvprintw(this->y.at(this->largo), this->x.at(this->largo), " "); //borrar el ultimo segmento del gusano

    //traspazo de datos en cola
    //para tener la trayectoria del gusano
    for (int cont = this->largo; cont > 0; cont--)
    {
        this->x.at(cont) = this->x.at(cont - 1);
        this->y.at(cont) = this->y.at(cont - 1);
    }

    mvaddch(this->y.at(0), this->x.at(0), this->icon);
}

void Serpiente::mover(int x_serpiente, int y_serpiente, int &comando_nuevo)
{
    for (int i = 0; i < this->largo; i++)
    {
        mvprintw(this->y.at(i), this->x.at(i), " "); //borrar el gusano
    }

    for (int i = 0; i < this->largo; i++)
    {
        this->y.at(i) = y_serpiente;
        this->x.at(i) = x_serpiente--;
    }

    comando_nuevo = COMANDO_ARRIBA;
}

int Serpiente::si_come(int x_comida, int y_comida, int puntos)
{
    int comio = false;

    if ((this->x.at(0) == x_comida) && (this->y.at(0) == y_comida))
    {
        this->largo++;
        this->x.push_back(37);
        this->y.push_back(18);
        if (this->velocidad < this->vel_maxima && puntos != 0 && (puntos + 1) % this->si_aumenta == 0)
        {
            this->velocidad += this->aceleracion;
        }

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
            if (this->x.at(0) == map_eje.x[cont2][cont] && this->y.at(0) == map_eje.y[cont2][cont])
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
        if ((this->x.at(0) == this->x.at(cont + 1) && this->y.at(0) == this->y.at(cont + 1)) && cont > 1)
        {
            choco = true;
            break;
        }
    }

    return choco;
}

void Serpiente::limite_map(int comando_nuevo)
{
    //limites para que el gusano
    //traspase la pantalla
    if (this->x.at(0) == ENTRADA_PORTAL_DERECHA && comando_nuevo == COMANDO_DERECHA)
        this->x.at(0) = SALIDA_PORTAL_IZQUIERDA;

    if (this->x.at(0) == ENTRADA_PORTAL_IZQUIERDA && comando_nuevo == COMANDO_IZQUIERDA)
        this->x.at(0) = SALIDA_PORTAL_DERECHA;

    if (this->y.at(0) == ENTRADA_PORTAL_SUPERIOR && comando_nuevo == COMANDO_ARRIBA)
        this->y.at(0) = SALIDA_PORTAL_INFERIOR;

    if (this->y.at(0) == ENTRADA_PORTAL_INFERIOR && comando_nuevo == COMANDO_ABAJO)
        this->y.at(0) = SALIDA_PORTAL_SUPERIOR;
}

bool Serpiente::entrar_tunel(int comando_nuevo)
{
    bool entro_tunel = false;

    for (unsigned int i = 0; i < this->mapa_bits->x_tunel_portal.size(); i++)
    {
        if ((this->x.at(0) == this->mapa_bits->x_tunel_portal.at(i) && this->y.at(0) == this->mapa_bits->y_tunel_portal) && comando_nuevo == COMANDO_ABAJO)
            this->y.at(0) = SALIDA_TUNEL;

        if ((this->x.at(this->x.size() - 1) == this->mapa_bits->x_tunel_portal.at(i) && this->y.at(this->y.size() - 1) == this->mapa_bits->y_tunel_portal) && comando_nuevo == COMANDO_ABAJO)
        {
            entro_tunel = true;
        }
    }

    return entro_tunel;
}

bool Serpiente::salir_tunel(int comando_nuevo)
{
    bool salio_tunel = false;

    for (unsigned int i = 0; i < this->mapa_bits->x_tunel_portal.size(); i++)
    {
        if ((this->x.at(this->x.size() - 1) == this->mapa_bits->x_tunel_portal.at(i) && this->y.at(this->y.size() - 1) == this->mapa_bits->y_tunel_portal) && comando_nuevo == COMANDO_ARRIBA)
        {
            salio_tunel = true;
        }
    }

    return salio_tunel;
}

void Serpiente::cambiar_direccion(int &comando_actual, int &comando_nuevo)
{
    switch (comando_nuevo)
    {
    case COMANDO_ARRIBA:
        comando_actual = comando_nuevo;
        this->y.at(0)--;
        break;
    case COMANDO_ABAJO:
        comando_actual = comando_nuevo;
        this->y.at(0)++;
        break;
    case COMANDO_DERECHA:
        comando_actual = comando_nuevo;
        this->x.at(0)++;
        break;
    case COMANDO_IZQUIERDA:
        comando_actual = comando_nuevo;
        this->x.at(0)--;
        break;
    default:
        if (comando_actual == COMANDO_ARRIBA)
            this->y.at(0)--;
        if (comando_actual == COMANDO_ABAJO)
            this->y.at(0)++;
        if (comando_actual == COMANDO_DERECHA)
            this->x.at(0)++;
        if (comando_actual == COMANDO_IZQUIERDA)
            this->x.at(0)--;
    }
}

int Serpiente::obtenerVelocidad()
{
    return this->velocidad;
}

void Serpiente::reiniciarVelocidad()
{
    this->velocidad = this->vel_inicial;
}
