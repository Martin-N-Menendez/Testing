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

 ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_HEX16);

 else

  UnityFail( (("Tren fuera de via")), (UNITY_UINT)(27));

}



void test_InsertarTrenes(void){

 uint16_t PosicionTrenes;

 int estado,i;

 Tren_Crear(&PosicionTrenes);



 for(i=1;i<=12;i++){

  estado = Tren_Insertar(i);



 if(!estado)

  UnityFail( (("Tren fuera de via")), (UNITY_UINT)(39));

 }



 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((2048)), (UNITY_INT)(UNITY_INT16)((PosicionTrenes)), (

((void *)0)

), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}



void test_TrenesColision(void){

 uint16_t PosicionTrenes;

 int estado1,estado2;

 Tren_Crear(&PosicionTrenes);



 estado1 = Tren_Insertar(1);

 estado2 = Tren_Insertar(2);



 if(estado1 == 0 || estado2 == 0)

  UnityFail( (("Tren fuera de via")), (UNITY_UINT)(54));



 Tren_Colision(PosicionTrenes);









 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((2048)), (UNITY_INT)(UNITY_INT16)((PosicionTrenes)), (

((void *)0)

), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_HEX16);

}
