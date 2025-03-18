#include "../include/fractol.h"

int draw_fractal(t_fractal *fractal, char *fractal_name)
{
    if (ft_strncmp(fractal_name, "mandelbrot", 10) == 0)
        mandelbrot_pthread(fractal);
    // buraya diğer fractallar da eklenecek
}

void	mandelbrot_pthread(t_fractal *fractal)
{
	pthread_t	thread[THREAD_NUMBER];
	t_fractal	tab[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)fractal, sizeof(t_fractal));
		tab[i].y = THREAD_WIDTH * i;
		pthread_create(&thread[i], NULL, draw_mandelbrot, &tab[i]); // (*start_routine)(arg); Bu, draw_mandelbrot(&tab[i]) şeklinde çalışır.
		i++;                         // 4. parametre 3. parametredi fonksiyona argüman olarak gönderilir. pthread_create tanımlanması gereği        
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->image,
		0, 0);
}

void *draw_mandelbrot(void *fractal_void)  // pthread_create tanımlanması gereği void pointer alıyor 
{
    t_fractal *fractal;
    int end_y;
    
    fractal = (t_fractal *)fractal_void;
    end_y = fractal->y + THREAD_WIDTH;
    if (end_y > SIZE)
        end_y = SIZE;
    
    fractal->x = 0;
    while (fractal->x < SIZE)
    {
        fractal->y = THREAD_WIDTH * (fractal->y / THREAD_WIDTH); // Başlangıç y değeri
        while (fractal->y < end_y)
        {
            calculate_mandelbrot(fractal);
            fractal->y++;
        }
        fractal->x++;
    }
    return (NULL);
}
