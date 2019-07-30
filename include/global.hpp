#ifndef _GLOBAL_LIB
#define _GLOBAL_LIB

const int COMANDO_ARRIBA = 1;
const int COMANDO_ABAJO = 2;
const int COMANDO_DERECHA = 3;
const int COMANDO_IZQUIERDA = 4;

const int TECLA_PAUSA = 112;
const int TECLA_FINAL = 113;

class Global
{
private:
    void pausa();

public:
    Global();
    ~Global();

    int comando_actual;
    int comando_nuevo;

    bool capturarComando();
    void retardo(int);
};

#endif