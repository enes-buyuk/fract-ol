#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <pthread.h>

# define SIZE 600 // EKSI DEĞER VERINCE PATLIYOR !!!!!!!
					// width ve height olarak ayrılabilir
// # define ITERATION 100

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

// MOUSECODES
# define SCROLL_UP 4
# define SCROLL_DOWN 5

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
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	int		color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
	int		argc;
	char	**argv;
	int julia_params_set; // Julia parametreleri ayarlandı mı?
}			t_fractal;

int			key_hook(int key_code, t_fractal *fractal);
void		init_fractal(t_fractal *fractal);
int			draw_fractal(t_fractal *fractal, char *fractal_name);
void		*draw_mandelbrot(t_fractal *fractal);
int			key_hook(int key_code, t_fractal *fractal);
void		init_mlx(t_fractal *fractal);
void		calculate_mandelbrot(t_fractal *fractal);
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
void		zoom(t_fractal *fractal, int x, int y, int zoom);
int			mouse_hook(int mouse_code, int x, int y, t_fractal *fractal);
void		calculate_julia(t_fractal *fractal);
void		draw_julia(t_fractal *fractal);
void		init_julia(t_fractal *fractal);
double		ft_atof(const char *str);
void		*draw_tricorn(t_fractal *fractal);
void		calculate_tricorn(t_fractal *fractal);
int			exit_fractal(t_fractal *fractal);
int			is_valid_fractal(char *name);
int			error_message(void);
#endif