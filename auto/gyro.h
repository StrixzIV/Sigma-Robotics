#ifndef GYRO_H
# define GYRO_H

# include <Wire.h>
# include <Arduino.h>
# include <MPU6050_light.h>

typedef struct s_telemetry {
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	gyro_x;
	float	gyro_y;
	float	gyro_z;
}	t_telemetry;

void	update_telemetry(t_telemetry *telemetry, MPU6050 &imu);
void	print_telemetry(t_telemetry *telemetry);

#endif