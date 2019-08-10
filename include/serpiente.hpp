#include <unistd.h>

#include <ncurses.h>
#include <jsoncpp/json/json.h>

#include "global.hpp"
#include "mapa.hpp"

#ifndef _SERPIENTE_LIB
#define _SERPIENTE_LIB

const int LARGO_INI_SERPIENTE = 2;
const int LARGO_MAX_SERPIENTE = 99;

//cuadros por segundo
const int VEL_INI = 5;
const int VEL_MAX = 20;

//distancia base de cuadros para operar con milsegundos
const int UNIDAD_CUADROS = 1000;

//aceleracion de un cuadro por segundo al cuadrado
const int ACELERACION = 1;

//condicion del largo de la serpiente para la proxima aceleración
const int SI_AUMENTA = 2;

class Serpiente
{
private:
	char icon;
	int largo = LARGO_INI_SERPIENTE;
	int x[LARGO_MAX_SERPIENTE + 1] = {37};
	int y[LARGO_MAX_SERPIENTE + 1] = {18};
	
	Global global;
	Json::Value conf;

public:
	int velocidad = VEL_INI;

	Serpiente(char);
	~Serpiente();

	void mover();
	void mover(int, int, int &);
	int si_come(int, int, int);
	int si_choca(map_coordenadas);
	int si_choca_con_el();
	void limite_map(int &);
	void cambiar_direccion(int &, int &);
};
#endif