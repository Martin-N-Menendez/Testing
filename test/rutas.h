#include <stdint.h>
#include <stdio.h>

#define SIN_TRENES 0x000
#define CON_TRENES 0xFFF
#define SIN_COLISION 0
#define MAX_TRENES_POR_RUTA 1
#define TREN_FUERA_MSG "Tren fuera de via"	//Mensaje de error si el tren se va de las vias
#define CV_MAX 12														//Maxima cantidad de circuitos de via

#define EXITO 1
#define ERROR 0
#define CHOQUE_IMPAR 1
#define CHOQUE_PAR 	-1

#define MASCARA_IMPAR	0x555
#define MASCARA_PAR		0xAAA

#define RUTA_IMPAR_MSG "La ruta ascendente (%d) tiene %d tren/es circulando\r\n"
#define RUTA_PAR_MSG 		"La ruta descendente (%d) tiene %d tren/es circulando\r\n"

void Tren_Crear(uint16_t* posicion);

int Tren_Insertar(uint8_t tren);

int Tren_Colision(uint16_t posicion);
