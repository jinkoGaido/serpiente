#include "juego.hpp"

Juego::Juego(Mapa *mapa_bits, Comida *comida, Serpiente *serpiente)
{
	this->mapa_bits = mapa_bits;
	this->comida = comida;
	this->serpiente = serpiente;
}

Juego::~Juego()
{
}

void Juego::iniciar(void)
{
	while (this->continua)
	{
		this->comida->mostrar();

		this->global.capturarDireccion();

		this->continua = this->serpiente->cambiar_direccion(this->global.direccion_actual, this->global.direccion_nueva);
		
		this->serpiente->limite_map();

		//mover gusano
		this->serpiente->mover();

		//velocidad de desplazamiento del gusano
		this->global.retardo(this->serpiente->velocidad);

		//verificar si el gusano esta en la misma posicion x y del alimento
		if (this->serpiente->si_come(this->comida->x, this->comida->y))
		{
			this->comida->randomXY();
		}

		if (this->serpiente->si_choca_con_el())
		{
			this->global.direccion_nueva = FINAL;
		}

		if (this->serpiente->si_choca(this->mapa_bits->eje))
		{
			this->global.direccion_nueva = FINAL;
		}
	}
}