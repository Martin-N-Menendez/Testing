#include "leds.h"

static uint16_t* puerto;

#define LEDS_OFF 0x00

void Leds_Create(uint16_t* direccion){
	puerto = direccion ;
	*puerto = LEDS_OFF ;
}

void Leds_TurnOn(uint8_t* led){
	*puerto = 1 << (char)(led-1);
}
