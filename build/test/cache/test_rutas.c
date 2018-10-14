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



void test_InsertarTrenes(void){

 uint16_t PosicionTrenes;

 int estado,i;

 Tren_Crear(&PosicionTrenes);



 for(i=1;i<=12;i++){

  estado = Tren_Insertar(i);



 if(!estado)

  UnityFail( (("Tren fuera de via")), (UNITY_UINT)(38));

 }



 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFF)), (UNITY_INT)(UNITY_INT16)((PosicionTrenes)), (

((void *)0)

), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TrenesColision(void){

 uint16_t PosicionTrenes;

 int estado_colision;

 Tren_Crear(&PosicionTrenes);



 if(!Tren_Insertar(1))

  UnityFail( (("Tren fuera de via")), (UNITY_UINT)(50));



 if(!Tren_Insertar(2))

  UnityFail( (("Tren fuera de via")), (UNITY_UINT)(53));



 estado_colision = Tren_Colision(PosicionTrenes);



 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((estado_colision)), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX16);

}
