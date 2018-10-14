#include "rutas.h"

static uint16_t* vias;

#define SIN_TREN 0x00

void Tren_Crear(uint16_t* posicion){
	vias = posicion;
	*vias = SIN_TREN;
}

int Tren_Insertar(uint8_t tren){
	if(tren<=12)
	{
		*vias = 1 << (char)(tren-1);
		return 1;
	}
	return 0;
}

void Tren_Colision(uint16_t posicion){
	uint16_t pares;
	uint16_t impares;

	impares = posicion & 0x555; // CV 1 3 5 7 9 11
	pares = posicion & 0xAAA;		// CV 2 4 6 8 10 12

	
	 


}
