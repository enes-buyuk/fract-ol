#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2 || !is_valid_fractal(argv[1]))
		return (error_message());
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (1);
	init_fractal(fractal);
	fractal->argc = argc;
	fractal->argv = argv;
	fractal->julia_params_set = 0;
	fractal->name = argv[1];
	init_mlx(fractal);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_fractal, fractal);
	draw_fractal(fractal, fractal->name);
	mlx_loop(fractal->mlx);
	return (0);
}
