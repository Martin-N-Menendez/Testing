#include "unity.h"
#include "rutas.h"

void setUp(void){
}

void tearDown(void){
}

void test_CrearRutas(void){
	uint16_t PosicionTrenes = 0x000;
	Tren_Crear(&PosicionTrenes);
	TEST_ASSERT_EQUAL_HEX16(0,PosicionTrenes);
	//TEST_FAIL_MESSAGE("Empezamos");
}

void test_InsertarTren(void){
	uint16_t PosicionTrenes;
	int estado;
	Tren_Crear(&PosicionTrenes);
	estado = Tren_Insertar(1);

	if(estado)
		TEST_ASSERT_EQUAL_HEX16(1,PosicionTrenes);
	else
		TEST_FAIL_MESSAGE("Tren fuera de via");

}
