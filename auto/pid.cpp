#include "pid.h"
#include "gyro.h"
#include "motion.h"

float	feedback_error(float target_angle, t_pid_error *error_ref, t_telemetry *telemetry) {

	float error = target_angle - telemetry->angle_y;
	float d_error = error - error_ref->prev_error;

	error_ref->error_sum += error;

	return (K_P * error) + (K_I * error_ref->error_sum) + (K_D * d_error);

}