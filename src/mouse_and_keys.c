#include "../include/fractol.h"

int key_hook(int key_code, t_fractal *fractal)
{
    if (key_code == ESC)
        exit(1);
    else if (key_code == LEFT)
        fractal->offset_x -= 50 / fractal->zoom;
    else if (key_code == RIGHT)
        fractal->offset_x += 50 / fractal->zoom;
    else if (key_code == UP)
        fractal->offset_y -= 50 / fractal->zoom;
    else if (key_code == DOWN)
        fractal->offset_y += 50 / fractal->zoom;
    else if (key_code == R)
        init_fractal(fractal);
    else if (key_code == C)
        fractal->color += (255 * 255 * 255) / 10;
    // else if (key_code == J)
	// 	set_random_julia(&fractal->cx, &fractal->cx);
	// else if (key_code == M || key_code == P)
	// 	change_iterations(fractal, key_code);
    draw_fractal(fractal, fractal->name);
    return (0);
}