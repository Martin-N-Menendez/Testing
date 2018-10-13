#include "build/temp/_test_rutas.c"
#include "rutas.h"
#include "unity.h"


void setUp(void){

}



void tearDown(void){

}



void test_CrearRutas(void){

 uint16_t PosicionTrenes = 0x000;

 Tren_Crear(&PosicionTrenes);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((PosicionTrenes)), (

((void *)0)

), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_HEX16);



}



void test_InsertarTren(void){

 uint16_t PosicionTrenes;

 int estado;

 Tren_Crear(&PosicionTrenes);

 estado = Tren_Insertar(1);



 if(estado)

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((PosicionTrenes)), (

 ((void *)0)

 ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_HEX16);

 else

  UnityFail( (("Tren fuera de via")), (UNITY_UINT)(26));



}
