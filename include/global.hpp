#ifndef _GLOBAL_LIB
#define _GLOBAL_LIB

const int COMANDO_ARRIBA = 1;
const int COMANDO_ABAJO = 2;
const int COMANDO_DERECHA = 3;
const int COMANDO_IZQUIERDA = 4;

const int FINAL = 0;

const int TECLA_ARRIBA = 259;
const int TECLA_ABAJO = 258;
const int TECLA_DERECHA = 261;
const int TECLA_IZQUIERDA = 260;

const int TECLA_ARRIBA_W = 119;
const int TECLA_ABAJO_S = 115;
const int TECLA_DERECHA_D = 100;
const int TECLA_IZQUIERDA_A = 970;

const int TECLA_FINAL = 112;

//aun no responden
const int TECLA_ARRIBA_MW = 870;
const int TECLA_ABAJO_MS = 830;
const int TECLA_DERECHA_MD = 680;
const int TECLA_IZQUIERDA_MA = 650;

const int TECLA_FINAL_M = 800;

class Global
{
private:
    /* data */
public:
    Global();
    ~Global();

    int direccion_actual;
    int direccion_nueva;

    void capturarDireccion();
    void retardo(int);
};

#endif