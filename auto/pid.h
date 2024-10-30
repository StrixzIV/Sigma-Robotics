#ifndef PID_H

# include <Arduino.h>

# define K_P 2.0
# define K_I 0.005
# define K_D 1.0

typedef struct s_pid_error {
	float	error_sum;
	float	prev_error;
}	t_pid_error;

#endif