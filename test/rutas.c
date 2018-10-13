#include "rutas.h"

static uint16_t* vias;

#define SIN_TREN 0x00

void Tren_Crear(uint16_t* posicion){
	vias = posicion;
	*vias = SIN_TREN;
}

int Tren_Insertar(uint8_t tren){
	if(tren<12)
	{
		*vias = 1 << (char)(tren-1);
		return 1;
	}
	return 0;
}
