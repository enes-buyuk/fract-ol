#include "../include/fractol.h"

void	*draw_tricorn(void *fractal)
{
	t_fractal	*f;

	f = (t_fractal *)fractal;
	f->name = "tricorn";
	f->x = 0;
	f->y = 0;
	while (f->x < SIZE)
	{
		while (f->y < SIZE)
		{
			calculate_tricorn(f);
			f->y++;
		}
		f->x++;
		f->y = 0;
	}
	return (NULL);
}

void	calculate_tricorn(t_fractal *f)
{
	int		i;
	double	tmp;

	f->zr = 0;
	f->zi = 0;
	f->cr = (f->x / f->zoom) + f->offset_x;
	f->ci = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (f->zr * f->zr + f->zi * f->zi < 4 && i < f->max_iterations)
	{
		tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
		f->zi = -2 * f->zi * tmp + f->ci;
		i++;
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, f->color * i);
}
