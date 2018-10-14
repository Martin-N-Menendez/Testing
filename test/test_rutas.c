#include "unity.h"
#include "rutas.h"

void setUp(void){
}

void tearDown(void){
}

void test_CrearRutas(void){
	uint16_t PosicionTrenes = SIN_TRENES;
	Tren_Crear(&PosicionTrenes);
	TEST_ASSERT_EQUAL_HEX16(0,PosicionTrenes);
}

void test_InsertarTren(void){
	uint16_t PosicionTrenes;
	int estado;
	Tren_Crear(&PosicionTrenes);

	estado = Tren_Insertar(1);

	if(estado)
		TEST_ASSERT_EQUAL_HEX16(1,PosicionTrenes);
	else
		TEST_FAIL_MESSAGE(TREN_FUERA_MSG);
}

void test_InsertarTrenes(void){
	uint16_t PosicionTrenes;
	int estado,i;
	Tren_Crear(&PosicionTrenes);

	for(i=1;i<=CV_MAX;i++){
		estado = Tren_Insertar(i);

	if(!estado)
		TEST_FAIL_MESSAGE(TREN_FUERA_MSG);
	}

	TEST_ASSERT_EQUAL_HEX16(CON_TRENES,PosicionTrenes);	
}

void test_TrenesColision(void){
	uint16_t PosicionTrenes;
	int estado_colision;
	Tren_Crear(&PosicionTrenes);

	if(!Tren_Insertar(1))
		TEST_FAIL_MESSAGE(TREN_FUERA_MSG);

	if(!Tren_Insertar(2))
		TEST_FAIL_MESSAGE(TREN_FUERA_MSG);

	estado_colision = Tren_Colision(PosicionTrenes);

	TEST_ASSERT_EQUAL_HEX16(SIN_COLISION,estado_colision);	
}

