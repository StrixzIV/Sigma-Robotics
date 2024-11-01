#ifndef MOTION_H
# define MOTION_H

# include <Arduino.h>
# include "gyro.h"

# define EN_A 3
# define EN_B 9

# define IN_1 4
# define IN_2 5
# define IN_3 10
# define IN_4 11

const int motor_control[] = {4, 5, 10, 11};

// # define MIN_SPEED 100

void	initialize_motor(const int *motor_pins);

void	stop();

void	fwd(int speed);
void	bwd(int speed);

void	rot_left(int speed);
void	rot_right(int speed);

void 	rot_right_90(MPU6050 &imu, t_telemetry *telemetry, int correction_factor);
void 	rot_left_90(MPU6050 &imu, t_telemetry *telemetry, int correction_factor);

#endif