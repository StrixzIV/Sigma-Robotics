#ifndef MOTION_H

# include <Arduino.h>

# define EN_A 3
# define EN_B 9

# define IN_1 4
# define IN_2 5
# define IN_3 10
# define IN_4 11

// # define MIN_SPEED 100

void	stop();

void	fwd(int speed);
void	bwd(int speed);

void	rot_left(int speed);
void	rot_right(int speed);

#endif