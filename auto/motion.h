#ifndef MOTION_H

# include <Arduino.h>

# define EN_A 3
# define EN_B 9

# define IN_1 4
# define IN_2 5
# define IN_3 10
# define IN_4 11

void	stop();

void	fwd();
void	bwd();

void	rot_left();
void	rot_right();

#endif