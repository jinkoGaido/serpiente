#ifndef _GLOBAL_LIB
#define _GLOBAL_LIB

const int ARRIBA = 1;
const int ABAJO = 2;
const int DERECHA = 3;
const int IZQUIERDA = 4;

const int FINAL = 0;

class Global
{
private:
    /* data */
public:
    Global();
    ~Global();

    int direccion_actual = DERECHA;
    int direccion_nueva = DERECHA;

    void capturarDireccion();
    void retardo(int);
};

#endif