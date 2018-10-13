#include "unity.h"
#include "leds.h"

void setUp(void){
}

void tearDown(void){
}

void test_LedsOfAfterCreate(void){
	uint16_t ledsVirtuales = 0xFFFF;
	Leds_Create(&ledsVirtuales);
	TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
	//TEST_FAIL_MESSAGE("Empezamos");
}

void test_TurnOnLedOne(void){
	uint16_t ledsVirtuales;
	Leds_Create(&ledsVirtuales);
	Leds_TurnOn(1);
	TEST_ASSERT_EQUAL_HEX16(1,ledsVirtuales);

}
