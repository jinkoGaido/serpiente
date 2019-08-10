#include "juego.hpp"

Juego::Juego(Nivel *nivel, Comida *comida, Serpiente *serpiente)
{
	this->nivel = nivel;
	this->mapa = nivel->obtenerMapaActual();
	this->comida = comida;
	this->serpiente = serpiente;
	this->continua = true;

	this->puntos = 0;
	this->vidas = 3;
}

Juego::~Juego()
{
}

void Juego::iniciar(void)
{
	bool si_nivel_avanzado;

	while (this->continua)
	{
		this->comida->mostrar();

		this->continua = this->global.capturarComando();

		this->serpiente->limite_map(this->global.comando_nuevo);

		this->serpiente->cambiar_direccion(this->global.comando_actual, this->global.comando_nuevo);

		//mover gusano
		this->serpiente->mover();

		//velocidad de desplazamiento del gusano
		this->retardo(UNIDAD_CUADROS / this->serpiente->velocidad);

		//verificar si el gusano esta en la misma posicion x y del alimento
		if (this->serpiente->si_come(this->comida->x, this->comida->y, this->puntos))
		{
			this->comida->randomXY();
			this->puntos++;
		}

		if (this->serpiente->si_choca_con_el())
		{
			global.mensaje(MAP_ALTO + 1, 35, "CHOCASTE CON TU CUERPO.", 2);
			global.mensaje(MAP_ALTO + 1, 35, "PRESIONA UNA TECLA PARA CONTINUAR.", true);
			this->vidas--;
			this->serpiente->mover(37, 18, this->global.comando_nuevo);
			this->mapa->dibujarMapa();
		}

		if (this->serpiente->si_choca(this->mapa->eje))
		{
			global.mensaje(MAP_ALTO + 1, 35, "CHOCASTE CON EL MURO.", 2);
			global.mensaje(MAP_ALTO + 1, 35, "PRESIONA UNA TECLA PARA CONTINUAR.", true);
			this->vidas--;
			this->serpiente->mover(37, 18, this->global.comando_nuevo);
			this->mapa->dibujarMapa();
		}

		if (this->vidas == 0)
		{
			this->final();
		}

		if ((this->puntos % PUNTOS_PROXIMO_NIVEL) == 0 && this->puntos != 0)
		{
			global.mensaje(MAP_ALTO + 1, 35, "NIVEL COMPLETADO.", 4);
			global.mensaje(MAP_ALTO + 1, 35, "PRESIONA UNA TECLA PARA CONTINUAR.", true);
			this->serpiente->mover(37, 18, this->global.comando_nuevo);
			this->puntos = 0;
			si_nivel_avanzado = this->nivel->avanzarNivel();

			if (!si_nivel_avanzado)
			{
				this->final();
			}
		}

		this->actualizarTablero();

		refresh();
	}
}

void Juego::final()
{
	this->continua = false;
}

void Juego::terminarJuego()
{
	global.mensaje(MAP_ALTO + 1, 35, "JUEGO TERMINADO.", 4);
	erase();
	attroff(COLOR_PAIR(1));
	endwin();
}

void Juego::retardo(int n)
{
	usleep(n * 1000);
}

void Juego::actualizarTablero()
{
	attron(A_BOLD);
	mvprintw(MAP_INI_Y - 1, 5, "Mapa: %s", this->mapa->obtenerNombre().c_str());
	mvprintw(MAP_INI_Y - 1, 35, "Puntos: %i", this->puntos);
	mvprintw(MAP_INI_Y - 1, 65, "Vidas: %i", this->vidas);

	mvprintw(MAP_ALTO + 1, 5, "Velocidad: %i cuadro/s", this->serpiente->velocidad);
	attroff(A_BOLD);
}