#include "gyro.h"
#include "motion.h"

MPU6050 		mpu(Wire);
t_telemetry		telemetry;

void setup() {

	Serial.begin(9600);

	initialize_motor(motor_control);

	Wire.begin();
	if (mpu.begin())
		Serial.println("Gyro Error.");
	mpu.calcOffsets();

	fwd(100);
	delay(900);
	stop();
	delay(800);
	rot_right_90(mpu, &telemetry, 100);
	
	fwd(100);
	delay(1350);
	stop();
	delay(800);
	rot_right_90(mpu, &telemetry, 100);
	
	fwd(100);
	delay(725);
	stop();
	delay(800);
	rot_left_90(mpu, &telemetry, 200);
	
	fwd(100);
	delay(750);
	stop();
	delay(800);
	rot_left_90(mpu, &telemetry, 200);
	
	fwd(100);
	delay(1300);
	stop();
	delay(800);
	rot_left_90(mpu, &telemetry, 250);
	
	fwd(100);
	delay(1300);
	stop();
	delay(800);
	rot_right_90(mpu, &telemetry, 200);
	
	fwd(100);
	delay(750);
	stop();
	delay(800);
	rot_right_90(mpu, &telemetry, 200);
	
	fwd(100);
	delay(850);
	stop();
	delay(800);
	rot_left_90(mpu, &telemetry, 150);
	
	fwd(100);
	delay(750);
	stop();
	delay(800);
	rot_right_90(mpu, &telemetry, 200);
	
	fwd(100);
	delay(800);
	stop();

}

void loop() {
	
	
}