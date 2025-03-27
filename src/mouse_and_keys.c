#include "../include/fractol.h"

int	key_hook(int key_code, t_fractal *fractal)
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

void	zoom(t_fractal *f, int x, int y, int zoom_direction)
{
	double	zoom_level;
	double	new_zoom;

	zoom_level = 1.50;   
	
	if (zoom_direction == 1)                
		new_zoom = f->zoom * zoom_level; 
	else if (zoom_direction == -1)         
		new_zoom = f->zoom / zoom_level; 
	else
		return ;                           
	
	// Fare konumuna göre offset değerleri güncelle
	f->offset_x += (double)x / f->zoom - (double)x / new_zoom;
	f->offset_y += (double)y / f->zoom - (double)y / new_zoom;
	f->zoom = new_zoom;
}

int	mouse_hook(int mouse_code, int x, int y, t_fractal *fractal)
{
	if (mouse_code == SCROLL_UP)
		zoom(fractal, x, y, 1);
	else if (mouse_code == SCROLL_DOWN)
		zoom(fractal, x, y, -1);
	draw_fractal(fractal, fractal->name);
	return (0);
}