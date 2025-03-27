#include "../include/fractol.h"

#include <stdio.h>

int	draw_fractal(t_fractal *fractal, char *fractal_name)
{
	if (ft_strncmp(fractal_name, "mandelbrot", 10) == 0)
		draw_mandelbrot(fractal);
	else if (ft_strncmp(fractal_name, "julia", 5) == 0)
		init_julia(fractal);
	else if (ft_strncmp(fractal_name, "tricorn", 7) == 0)
		draw_tricorn(fractal);
	
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image, 0, 0);
	return (0);
}

void	init_julia(t_fractal *fractal)
{
	if (fractal->julia_params_set != 1)
	{
		if (fractal->argc == 4)
		{
			fractal->cr = ft_atof(fractal->argv[2]);
			fractal->ci = ft_atof(fractal->argv[3]);
		}
		else
		{
			fractal->cr = -0.745429;
			fractal->ci = 0.05;
		}
		fractal->julia_params_set = 1;
	}
	draw_julia(fractal);
}
