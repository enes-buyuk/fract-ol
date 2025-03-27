#include "../include/fractol.h"

double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		sign;
	int		i;

	result = 0.0;
	decimal = 0.0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	decimal = 0.1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result += (str[i++] - '0') * decimal;
		decimal *= 0.1;
	}
	return (result * sign);
}
void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	char	*pixel;

	pixel = fractal->pointer_to_image + (y * fractal->size_line + x * 4);
	*(unsigned int *)pixel = color;
}
int	exit_fractal(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}
int	is_valid_fractal(char *name)
{
	if (ft_strncmp(name, "mandelbrot", 10) == 0 || 
		ft_strncmp(name, "julia", 5) == 0 || 
		ft_strncmp(name, "tricorn", 7) == 0)
		return (1);
	return (0);
}
int	error_message(void)
{
	ft_putendl_fd("Usage: ./fractol <fractal>", 1);
	ft_putendl_fd("Available fractals: mandelbrot, julia, tricorn", 1);
	ft_putendl_fd("For julia set: ./fractol julia [real] [imaginary]", 1);
	ft_putendl_fd("Example: ./fractol julia -0.7 0.27015", 1);
	return (0);
}
