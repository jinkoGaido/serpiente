CC = g++
CFLAGS  = -Wall #-O
INCLUDESG = -I./include
DEBUG = #-g
SRC_DIR = ./src/
OBJ_DIR = ./object/

default: main

main:  mapa.o comida.o juego.o 
	$(CC) $(CFLAGS) $(DEBUG) $(SRC_DIR)main.cpp -o serpiente $(OBJ_DIR)juego.o $(OBJ_DIR)nivel.o $(OBJ_DIR)comida.o $(OBJ_DIR)serpiente.o $(OBJ_DIR)mapa.o $(OBJ_DIR)global.o -lncurses $(INCLUDESG)

juego.o: object mapa.o comida.o global.o serpiente.o nivel.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)juego.cpp -o $(OBJ_DIR)juego.o $(INCLUDESG)

nivel.o: object mapa.o comida.o global.o serpiente.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)nivel.cpp -o $(OBJ_DIR)nivel.o $(INCLUDESG)

comida.o: object mapa.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)comida.cpp -o $(OBJ_DIR)comida.o $(INCLUDESG)

serpiente.o: object 
	$(CC) $(CFLAGS) -c $(SRC_DIR)serpiente.cpp -o $(OBJ_DIR)serpiente.o $(INCLUDESG)

mapa.o: object
	$(CC) $(CFLAGS) -c $(SRC_DIR)mapa.cpp -o $(OBJ_DIR)mapa.o $(INCLUDESG)

global.o: object
	$(CC) $(CFLAGS) -c $(SRC_DIR)global.cpp -o $(OBJ_DIR)global.o $(INCLUDESG)

object: 
	mkdir object

clean: 
	$(RM) object/* serpiente