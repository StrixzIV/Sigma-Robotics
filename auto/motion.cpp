#include "motion.h"

void	set_motor(int in_1, int in_2, int in_3, int in_4) {
	digitalWrite(IN_1, in_1);
	digitalWrite(IN_2, in_2);
	digitalWrite(IN_3, in_3);
	digitalWrite(IN_4, in_4);
}

void fwd(int speed) {
	set_motor(HIGH, LOW, HIGH, LOW);
	analogWrite(EN_A, speed);
	analogWrite(EN_B, speed);
}

void bwd(int speed) {
	set_motor(LOW, HIGH, LOW, HIGH);
	analogWrite(EN_A, speed);
	analogWrite(EN_B, speed);
}

void stop() {
	set_motor(LOW, LOW, LOW, LOW);
	analogWrite(EN_A, 80);
	analogWrite(EN_B, 80);
}

void	rot_left(int speed) {
	set_motor(HIGH, LOW, LOW, HIGH);
	analogWrite(EN_A, speed);
	analogWrite(EN_B, speed);
}

void	rot_right(int speed) {
	set_motor(LOW, HIGH, HIGH, LOW);
	analogWrite(EN_A, speed);
	analogWrite(EN_B, speed);
}
