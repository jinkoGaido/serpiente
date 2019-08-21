#include <unistd.h>
#include <vector>

#include <ncurses.h>
#include <jsoncpp/json/json.h>

#include "global.hpp"
#include "mapa.hpp"

#ifndef _SERPIENTE_LIB
#define _SERPIENTE_LIB

//distancia base de cuadros para operar con milsegundos
const int UNIDAD_CUADROS = 1000;

class Serpiente
{

private:
	char icon;
	int largo;
	vector<int> x;
	vector<int> y;
	int largo_inicial;
	int largo_maximo;
	int vel_inicial;
	int vel_maxima;
	int aceleracion;
	int si_aumenta;
	int velocidad;

	Mapa *mapa_bits;
	Global global;
	Json::Value conf;

public:
	Serpiente(Mapa *);
	~Serpiente();

	void mover();
	void mover(int, int, int &);
	int si_come(int, int, int);
	int si_choca(map_coordenadas);
	int si_choca_con_el();
	void limite_map(int);
	bool entrar_tunel(int);
	bool salir_tunel(int);
	void cambiar_direccion(int &, int &);
	int obtenerVelocidad();
	void reiniciarVelocidad();
};
#endif