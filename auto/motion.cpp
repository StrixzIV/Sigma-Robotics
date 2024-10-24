#include "motion.h"

void	set_motor(int in_1, int in_2, int in_3, int in_4) {
	digitalWrite(IN_1, in_1);
	digitalWrite(IN_2, in_2);
	digitalWrite(IN_3, in_3);
	digitalWrite(IN_4, in_4);
}

void fwd() {

	set_motor(HIGH, LOW, HIGH, LOW);

	for (int en = 40; en < 100; en++) {
		analogWrite(EN_A, en);
		analogWrite(EN_B, en);
		delay(10);
	}
	
	delay(500);

}

void bwd() {

	set_motor(LOW, HIGH, LOW, HIGH);

	for (int en = 40; en < 100; en++) {
		analogWrite(EN_A, en);
		analogWrite(EN_B, en);
		delay(10);
	}

	delay(500);

}

void stop() {
	set_motor(LOW, LOW, LOW, LOW);
	analogWrite(EN_A, 0);
	analogWrite(EN_B, 0);
}

void	rot_left() {
	set_motor(HIGH, LOW, LOW, HIGH);
	analogWrite(EN_A, 100);
	analogWrite(EN_B, 100);
}

void	rot_right() {
	set_motor(LOW, HIGH, HIGH, LOW);
	analogWrite(EN_A, 100);
	analogWrite(EN_B, 100);
}
