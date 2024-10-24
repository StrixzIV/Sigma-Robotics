#include "motion.h"

void setup() {

	pinMode(EN_A, OUTPUT);
	pinMode(EN_B, OUTPUT);

	pinMode(IN_1, OUTPUT);
	pinMode(IN_2, OUTPUT);
	pinMode(IN_3, OUTPUT);
	pinMode(IN_4, OUTPUT);

    Serial.begin(9600);

	rot_left();
	delay(400);
	stop();

	delay(1500);

	rot_right();
	delay(400);
	stop();

}

void loop() {}
