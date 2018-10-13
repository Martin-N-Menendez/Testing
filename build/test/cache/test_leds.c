#include "build/temp/_test_leds.c"
#include "leds.h"
#include "unity.h"


void setUp(void){

}



void tearDown(void){

}



void test_LedsOfAfterCreate(void){

 uint16_t ledsVirtuales = 0xFFFF;

 Leds_Create(&ledsVirtuales);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_HEX16);



}



void test_TurnOnLedOne(void){

 uint16_t ledsVirtuales;

 Leds_Create(&ledsVirtuales);

 Leds_TurnOn(1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

((void *)0)

), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_HEX16);



}
