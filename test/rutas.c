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
		*vias |= 1 << (char)(tren-1);
		return 1;
	}
	return 0;
}

int Tren_Colision(uint16_t posicion){
	uint16_t pares;
	uint16_t impares;
	
	uint16_t i,suma_i,suma_p,mask,nbits_i,nbits_p;

	nbits_p = 0;
	nbits_i = 0;
	mask = 1;

	impares = posicion & 0x555; 	// CV 1 3 5 7 9 11
	pares = posicion & 0xAAA;			// CV 2 4 6 8 10 12

	//printf("Posicion:%d \r\n", posicion);

	for(i=0;i<16;i++)
	{
		suma_i = impares & mask;
		suma_p = pares & mask;

		mask = mask << 1;
		if(suma_i != 0)
			nbits_i++;
		if(suma_p != 0)
			nbits_p++;
	}	

	printf("La ruta ascendente (%d) tiene %d tren/es circulando\r\n", impares, nbits_i);
	printf("La ruta descendente (%d) tiene %d tren/es circulando\r\n", pares, nbits_p);
		
	if(nbits_i>1)
		return 1;
	if(nbits_p>1)
		return -1;
	return 0;
}
