#include "global.hpp"
#include "mapa.hpp"

#ifndef _SERPIENTE_LIB
#define _SERPIENTE_LIB

const int LARGO_INI_SERPIENTE = 2;
const int LARGO_MAX_SERPIENTE = 99;
const int VEL_INI = 180;
const int VEL_MAX = 80;
const int ACELERACION = 10;

class Serpiente
{
private:
	char icon;
	int largo = LARGO_INI_SERPIENTE;
	int x[LARGO_MAX_SERPIENTE + 1] = {37};
	int y[LARGO_MAX_SERPIENTE + 1] = {18};

public:
	int velocidad = VEL_INI;

	Serpiente(char);
	~Serpiente();

	void mover();

	int si_come(int, int);

	int si_choca(map_coordenadas);

	int si_choca_con_el();

	void limite_map();

	void cambiar_direccion(int &, int &);
};
#endif