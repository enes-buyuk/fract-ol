#include "../include/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xFCBE11;
	fractal->zoom = 200;
	fractal->offset_x = -2.3;
	fractal->offset_y = -1.7;
	fractal->max_iterations = 50;
}