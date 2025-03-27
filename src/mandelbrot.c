#include "../include/fractol.h"

void *draw_mandelbrot(t_fractal *fractal)
{
    fractal->x = 0;
    fractal->y = 0;
    while (fractal->x < SIZE)
    {
        while (fractal->y < SIZE)
        {
            calculate_mandelbrot(fractal);
            fractal->y++;
        }
        fractal->x++;
        fractal->y = 0;
    }
    return (NULL);
}

void	calculate_mandelbrot(t_fractal *f)
{
	int		i;
	double	tmp;

	// f->name = "mandelbrot"; // Bu satırı kaldır, zaten main'de set ediliyor
	f->zr = 0;
	f->zi = 0;
	f->cr = (f->x / f->zoom) + f->offset_x;
	f->ci = (f->y / f->zoom) + f->offset_y;
	i = 0;
	while (f->zr * f->zr + f->zi * f->zi < 4
		&& i < f->max_iterations)
	{
		tmp = f->zr;
		f->zr = f->zr * f->zr - f->zi * f->zi
			+ f->cr;
		f->zi = 2 * f->zi * tmp + f->ci;
		i++;
	}
	if (i == f->max_iterations)
		put_color_to_pixel(f, f->x, f->y, 0x000000);
	else
		put_color_to_pixel(f, f->x, f->y, f->color * i);
}
