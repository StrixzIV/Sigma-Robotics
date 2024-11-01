#ifndef MOTION_H
# define MOTION_H

# include <Arduino.h>
# include "gyro.h"

# define EN_A 3
# define EN_B 9

const int motor_control[] = {4, 5, 10, 11};

typedef enum e_direction {
	LEFT,
	RIGHT
}	t_direction;

void	initialize_motor(const int *motor_pins);

void	stop();

void	fwd(int speed);
void	bwd(int speed);

void	rot_left(int speed);
void	rot_right(int speed);

void 	rot_right_90(MPU6050 &imu, t_telemetry *telemetry, int correction_factor);
void 	rot_left_90(MPU6050 &imu, t_telemetry *telemetry, int correction_factor);

void	forward_and_rotate(MPU6050 &imu, t_telemetry *telemetry,
	int forward_duration, int correction_factor, t_direction direction);

#endif