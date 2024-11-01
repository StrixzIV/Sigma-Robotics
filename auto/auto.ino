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

	forward_and_rotate(mpu, &telemetry, 900, 100, RIGHT);
	forward_and_rotate(mpu, &telemetry, 1350, 100, RIGHT);
	forward_and_rotate(mpu, &telemetry, 725, 200, LEFT);
	forward_and_rotate(mpu, &telemetry, 750, 200, LEFT);
	forward_and_rotate(mpu, &telemetry, 1300, 250, LEFT);
	forward_and_rotate(mpu, &telemetry, 1300, 200, RIGHT);
	forward_and_rotate(mpu, &telemetry, 750, 200, RIGHT);
	forward_and_rotate(mpu, &telemetry, 850, 150, LEFT);
	forward_and_rotate(mpu, &telemetry, 750, 200, LEFT);

	fwd(100);
	delay(800);
	stop();

}

void loop() {
	
	
}