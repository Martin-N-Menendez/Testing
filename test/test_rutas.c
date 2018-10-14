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

void test_InsertarTrenes(void){
	uint16_t PosicionTrenes;
	int estado,i;
	Tren_Crear(&PosicionTrenes);

	for(i=1;i<=12;i++){
		estado = Tren_Insertar(i);

	if(!estado)
		TEST_FAIL_MESSAGE("Tren fuera de via");
	}

	TEST_ASSERT_EQUAL_HEX16(2048,PosicionTrenes);	
}

void test_TrenesColision(void){
	uint16_t PosicionTrenes;
	int estado1,estado2;
	Tren_Crear(&PosicionTrenes);

	estado1 = Tren_Insertar(1);
	estado2 = Tren_Insertar(2);

	if(estado1 == 0 || estado2 == 0)
		TEST_FAIL_MESSAGE("Tren fuera de via");

	Tren_Colision(PosicionTrenes);


	

	TEST_ASSERT_EQUAL_HEX16(2048,PosicionTrenes);	
}

