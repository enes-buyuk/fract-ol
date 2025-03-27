#include "../include/fractol.h"

void	init_fractal(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->color = 0xF3E8CB;  // 0x7B68EE, 0xAFD5AA, 0xF3E8CB, 0x1E90FF
	
	// SIZE değerine göre dinamik zoom değeri
	fractal->zoom = SIZE / 4;
	
	// Mandelbrot setinin tamamını görmek için ideal ofset değerleri
	fractal->offset_x = -2.0;  
	fractal->offset_y = -2.0;
	
	fractal->max_iterations = 100;
}

void	init_mlx(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel, &fractal->size_line, &fractal->endian);
}