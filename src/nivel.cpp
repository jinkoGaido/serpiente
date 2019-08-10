#include "nivel.hpp"

Nivel::Nivel()
{
    this->numero_nivel_juego = 0;

    this->conf = this->global.configuracion("nivel");
    this->dir_mapa_base = (this->conf["ruta_base"].isString()) ? this->conf["ruta_base"].asCString() : "data/";

    DIR *directorios = opendir(this->dir_mapa_base.c_str());
    dirent *archivo = readdir(directorios);
    int nivel_mapa = 0;

    if (directorios != NULL)
    {
        while (archivo)
        {
            string nombre_archivo = archivo->d_name;
            if (nombre_archivo.find(".mp") != string::npos)
            {
                int pos = nombre_archivo.find(".");
                string nombre = nombre_archivo.substr(0, pos);
                pos = nombre.find("_");
                nivel_mapa = atoi(nombre_archivo.substr(pos + 1, nombre_archivo.size()).c_str());
                if (nivel_mapa)
                {
                    directorios::iterator it = lower_bound(directorios_mapa.begin(), directorios_mapa.end(), nombre_archivo);
                    directorios_mapa.insert(it, nombre_archivo);
                }
            }
            archivo = readdir(directorios);
        }

        this->mapa = new Mapa(this->dir_mapa_base + directorios_mapa.at(this->numero_nivel_juego));
    }
}

Nivel::~Nivel()
{
    delete this->mapa;
}

void Nivel::enlazar(Serpiente *serpiente, Comida *comida)
{
    this->serpiente = serpiente;
    this->comida = comida;
}

Mapa *Nivel::obtenerMapaActual()
{
    return this->mapa;
}

bool Nivel::avanzarNivel()
{
    this->numero_nivel_juego++;
    bool si_nivel_avanzado = true;

    if (this->mapa != NULL)
    {
        try
        {
            this->mapa->cargarMapa(this->dir_mapa_base + this->directorios_mapa.at(this->numero_nivel_juego));
            this->mapa->dibujarMapa();
        }
        catch (const std::exception &e)
        {
            this->global.mensaje(MAP_ALTO + 1, 35, "NO QUEDAN MAPAS", 2);
            si_nivel_avanzado = false;
        }
    }
    refresh();

    return si_nivel_avanzado;
}