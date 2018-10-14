#include "rutas.h"

static uint16_t* vias;

void Tren_Crear(uint16_t* posicion){
	vias = posicion;
	*vias = SIN_TRENES;
}

int Tren_Insertar(uint8_t tren){
	if(tren<=CV_MAX)
	{
		*vias |= 1 << (char)(tren-1);
		return EXITO;
	}
	return ERROR;
}

int Tren_Colision(uint16_t posicion){
	uint16_t pares;
	uint16_t impares;
	
	uint16_t i,suma_i,suma_p,mask,nbits_i,nbits_p;

	nbits_p = 0;
	nbits_i = 0;
	mask = 1;

	impares = posicion & MASCARA_IMPAR; 	// CV 1 3 5 7 9 11
	pares = posicion & MASCARA_PAR;			// CV 2 4 6 8 10 12

	//printf("Posicion:%d \r\n", posicion);

	for(i=0;i<CV_MAX;i++)
	{
		suma_i = impares & mask;
		suma_p = pares & mask;

		mask = mask << 1;
		if(suma_i)
			nbits_i++;
		if(suma_p)
			nbits_p++;
	}	

	printf(RUTA_IMPAR_MSG, impares, nbits_i);
	printf(RUTA_PAR_MSG, pares, nbits_p);
		
	if(nbits_i>MAX_TRENES_POR_RUTA)
		return CHOQUE_IMPAR;
	if(nbits_p>MAX_TRENES_POR_RUTA)
		return CHOQUE_PAR;
	return ERROR;
}
