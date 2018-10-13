#include "build/temp/_test_routes.c"
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



void test_TurnOnLedOne(void){

 uint16_t ledsVirtuales;

 Tren_Crear(&ledsVirtuales);

 Leds_TurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_HEX16);



}
