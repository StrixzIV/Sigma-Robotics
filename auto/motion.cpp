#include "motion.h"

void	initialize_motor(const int *motor_pins) {
	for (unsigned short idx = 0; idx < 4; idx++) {
		pinMode(motor_pins[idx], OUTPUT);
	}
}

void	set_motor(int in_1, int in_2, int in_3, int in_4) {
	digitalWrite(motor_control[0], in_1);
	digitalWrite(motor_control[1], in_2);
	digitalWrite(motor_control[2], in_3);
	digitalWrite(motor_control[3], in_4);
}

void fwd(int speed) {
	set_motor(HIGH, LOW, HIGH, LOW);
	analogWrite(EN_A, speed);
	analogWrite(EN_B, speed + 1);
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

void rot_right_90(MPU6050 &imu, t_telemetry *telemetry, int correction_factor) {

	float initial_angle;
	float final_angle;

	update_telemetry(telemetry, imu);
	initial_angle = telemetry->angle_y;

	rot_right(100);
	delay(300);
	
	stop();
	delay(1000);
	update_telemetry(telemetry, imu);
	final_angle = telemetry->angle_y;

	rot_left(100);
	delay(correction_factor * abs(initial_angle - final_angle));
	stop();
	delay(500);

}

void rot_left_90(MPU6050 &imu, t_telemetry *telemetry, int correction_factor) {

	float initial_angle;
	float final_angle;

	update_telemetry(telemetry, imu);
	initial_angle = telemetry->angle_y;

	rot_left(100);
	delay(300);
	
	stop();
	delay(1000);
	update_telemetry(telemetry, imu);
	final_angle = telemetry->angle_y;

	rot_right(100);
	delay(correction_factor * abs(initial_angle - final_angle));
	stop();
	delay(500);

}

void forward_and_rotate(MPU6050 &imu, t_telemetry *telemetry, int forward_duration, int correction_factor, t_direction direction) {

	fwd(100);
	delay(forward_duration);
	stop();
	delay(800);

	switch (direction) {

		case LEFT:
			rot_left_90(imu, telemetry, correction_factor);
			break ;

		case RIGHT:
			rot_right_90(imu, telemetry, correction_factor);
			break ;

	}

}
