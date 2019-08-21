# Serpiente

Juego de la serpiente usando la terminal de linux como plataforma.
El desarrollo de este proyecto es con fines educativos, por tanto su licencia es y seguirá siendo libre de uso, modificación, distribución, ...

# Requerimientos

 - Sistema operativo basado en linux.
	 - Ejecutado y desarrollado en Ubuntu.
 - Librería ncurses: [sitio oficial](https://www.gnu.org/software/ncurses/)
 - Librería jsoncpp: [sitio oficial](http://open-source-parsers.github.io/jsoncpp-docs/doxygen/index.html)
 
# Instalación
 1. Descarga el repositorio.
 2. Asegurate de tener instalado el compilador g++ y las librerías ncurses y jsoncpp.
 3.  Descomprime y accede al directorio por la terminal.
 4. Ejecuta el comando: make.
 5. Para iniciar el juego solo ejecuta: ./serpiente

# Estructura del directorio del proyecto
```
serpiente
  |- makefile
  |- data/
  | |- buffer_test
  | |- mapa_1.mp
  | |- mapa_2.mp
  | |- mapa_3.mp
  |- include/
    |- comida.hpp
    |- global.hpp
    |- juego.hpp
    |- mapa.hpp
    |- nivel.hpp
    |- serpiente.hpp
  |- object/
  |- src/
    |- comida.cpp
    |- global.cpp
    |- juego.cpp
    |- kbhit.c
    |- main.cpp
    |- mapa.cpp
    |- nivel.cpp
    |- serpiente.cpp
```

 
  

