#include "gyro.h"
#include "motion.h"

#define DESTINATION 1

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
	bwd(100);
	delay(800);

	forward_and_rotate(mpu, &telemetry, 1600, 100, RIGHT);
	bwd(100);
	delay(800);

	forward_and_rotate(mpu, &telemetry, 900, 200, LEFT);
	bwd(100);
	delay(800);

	forward_and_rotate(mpu, &telemetry, 900, 0, LEFT);
	bwd(100);
	delay(800);

	forward_and_rotate(mpu, &telemetry, 1600, 235, LEFT);
	bwd(100);
	delay(1500);

	forward_and_rotate(mpu, &telemetry, 1450, 0, RIGHT);
	bwd(100);
	delay(1000);

	forward_and_rotate(mpu, &telemetry, 800, 225, RIGHT);
	forward_and_rotate(mpu, &telemetry, 700, 200, LEFT);
	bwd(100);
	delay(800);

	switch (DESTINATION) {

		case 1:
			forward_and_rotate(mpu, &telemetry, 1400, 300, LEFT);
			forward_and_rotate(mpu, &telemetry, 1400, 200, RIGHT);
			bwd(100);
			delay(800);
			
			forward_and_rotate(mpu, &telemetry, 1000, 200, RIGHT);
			bwd(100);
			delay(800);

			fwd(200);
			delay(1500);
			stop();
			
			break;

		case 2:

			forward_and_rotate(mpu, &telemetry, 1400, 200, RIGHT);

			fwd(120);
			delay(800);
			stop();

			break;
	
	}


}

void loop() {
	
	
}