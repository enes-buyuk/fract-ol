#include "include/fractol.h"

int main(int argc, char **argv)
{
    t_fractal *fractal;

	if (argc != 2) // buraya düzgün usage message ekle 
	{
		ft_putendl_fd("Usage: ./fractol <fractal>", 1);
		ft_putendl_fd("Available fractals: mandelbrot, julia, burningship", 1);
		return (0);
	}
    fractal = malloc(sizeof(t_fractal));
    init_fractal(fractal);
    mlx_key_hook(fractal->window, key_hook, fractal);
}