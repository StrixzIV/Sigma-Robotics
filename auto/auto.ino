#include "gyro.h"
#include "motion.h"

MPU6050 		mpu(Wire);
t_telemetry		telemetry;

void rot_right_90(t_telemetry *telemetry, int correction_factor) {

	float initial_angle;
	float final_angle;

	update_telemetry(telemetry, mpu);
	initial_angle = telemetry->angle_y;

	rot_right(100);
	delay(300);
	
	stop();
	delay(1000);
	update_telemetry(telemetry, mpu);
	final_angle = telemetry->angle_y;

	rot_left(100);
	delay(correction_factor * abs(initial_angle - final_angle));
	stop();
	delay(500);

}

void setup() {

	Serial.begin(9600);
	Wire.begin();
	if (mpu.begin())
		Serial.println("Gyro Error.");
	mpu.calcOffsets();

	fwd(100);
	delay(1000);
	stop();
	delay(500);
	rot_right_90(&telemetry, 125);
	
	fwd(100);
	delay(1000);
	stop();
	delay(500);
	rot_right_90(&telemetry, 125);
	
}

void loop() {
	
	
}