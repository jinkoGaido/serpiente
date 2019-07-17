CC = g++
CFLAGS  = -Wall

default: serpiente

serpiente:  mapa.o comida.o juego.o 
	$(CC) $(CFLAGS) src/main.cpp -o serpiente object/juego.o object/comida.o object/mapa.o -lncurses

juego.o: mapa.o comida.o
	$(CC) $(CFLAGS) -c src/juego.cpp -o object/juego.o


comida.o:  mapa.o
	$(CC) $(CFLAGS) -c src/comida.cpp -o object/comida.o


mapa.o:  
	$(CC) $(CFLAGS) -c src/mapa.cpp -o object/mapa.o

clean: 
	$(RM) object/* serpiente