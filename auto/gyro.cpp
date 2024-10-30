#include "gyro.h"

void	update_telemetry(t_telemetry *telemetry, MPU6050 &imu) {
	
	imu.update();

	telemetry->angle_x = imu.getAngleX();
	telemetry->angle_y = imu.getAngleY();
	telemetry->angle_z = imu.getAngleZ();

	telemetry->gyro_x = imu.getGyroX();
	telemetry->gyro_y = imu.getGyroY();
	telemetry->gyro_z = imu.getGyroZ();

}

void	print_telemetry(t_telemetry *telemetry) {
	
	Serial.print("Angle X ");
	Serial.print(telemetry->angle_x);
	Serial.println(" Degree");
	Serial.print("Angle Y ");
	Serial.print(telemetry->angle_y);
	Serial.println(" Degree");
	Serial.print("Angle Z ");
	Serial.print(telemetry->angle_z);
	Serial.println(" Degree");
	Serial.println();

	Serial.print("Angular velocity X ");
	Serial.print(telemetry->gyro_x);
	Serial.println(" Degree/s");
	Serial.print("Angular velocity Y ");
	Serial.print(telemetry->gyro_y);
	Serial.println(" Degree/s");
	Serial.print("Angular velocity Z ");
	Serial.print(telemetry->gyro_z);
	Serial.println(" Degree/s");
	Serial.println();

}
