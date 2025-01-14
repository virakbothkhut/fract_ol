#include "fractol.h"

void	draw_fractal(t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
		draw_mandelbrot(fractol);
	else if (fractol->type == JULIA)
		draw_julia(fractol);
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}

int	get_color(int iter, int max_iterate, int color_scheme)
{
	double	t;
	int		r;
	int		g;
	int		b;

	t = (double)iter / (double)max_iterate;
	if (color_scheme == 1)
	{
		r = (int)(255 * 9 * (1 - t) * t * t * t);
		g = (int)(255 * 15 * (1 - t) * (1 - t) * t * t);
		b = (int)(255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t);
	}
	else if (color_scheme == 2)
	{
		r = (int)(255 * 15 * (1 - t) * t * t * t);
		g = (int)(255 * 8.5 * (1 - t) * (1 - t) * t * t);
		b = (int)(255 * 9 * (1 - t) * (1 - t) * (1 - t) * t);
	}
	else
	{
		r = (int)(255 * 8.5 * (1 - t) * t * t * t);
		g = (int)(255 * 9 * (1 - t) * (1 - t) * t * t);
		b = (int)(255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t);
	}
	return ((r << 16) | (g << 8) | b);
}

void	cleanup(t_fractol *fractol)
{
	if (fractol)
	{
		if (fractol->mlx)
		{
			mlx_delete_image(fractol->mlx, fractol->img);
			mlx_terminate(fractol->mlx);
		}
		free(fractol);
	}
}
