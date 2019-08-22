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
	bool si_come(int, int, int);
	bool si_choca_con_muro(map_coordenadas);
	bool si_choca_con_tunel();
	bool si_choca_con_el();
	void limite_map(int);
	bool entrar_tunel(int);
	bool salir_tunel(int);
	void cambiar_direccion(int &, int &);
	int obtenerVelocidad();
	void reiniciarVelocidad();
	int obtener_pos_x();
	int obtener_pos_y();
	void dibujar();
};
#endif