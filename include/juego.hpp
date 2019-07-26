#include "global.hpp"
#include "mapa.hpp"
#include "comida.hpp"
#include "serpiente.hpp"

#ifndef _JUEGO_LIB
#define _JUEGO_LIB

class Juego
{
private:
	Mapa *mapa_bits;
	Comida *comida;
	Serpiente *serpiente;
	Global global;

	bool continua;

	int control();
	void retardo(int);

public:
	Juego(Mapa *, Comida *, Serpiente *);
	~Juego();

	void iniciar();
	void final();
};
#endif