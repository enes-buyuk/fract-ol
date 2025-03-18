#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <pthread.h>

# define SIZE 600              // width ve height olarak ayrılabilir
# define ITERATION 100
# define THREAD_NUMBER 16  
# define THREAD_WIDTH (SIZE / THREAD_NUMBER)      

// KEYCODES
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define R 114
# define C 99
# define H 104
# define J 106
# define P 112
# define M 109

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	void	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

int			key_hook(int key_code, t_fractal *fractal);
void		init_fractal(t_fractal *fractal);
int			draw_fractal(t_fractal *fractal, char *fractal_name);

#endif