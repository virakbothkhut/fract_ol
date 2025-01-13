#include "fractol.h"

void draw_mandelbrot(t_fractol *fractol)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	while (y < HEIGHT)
    {
		x = 0;
		while (x < WIDTH)
		{
			iter = calculate_mandelbrot(fractol, x, y);
			mlx_put_pixel(fractol->img, x, y,
			get_color(iter, fractol->max_iterate, fractol->color_scheme));
			x++;
		}
		y++;
	}
}

int calculate_mandelbrot(t_fractol *fractol, int x, int y)
{
    t_complex c, z, temp;
    int iter = 0;

    // Use fractol->zoom, fractol->offset_x, and fractol->offset_y
    c.re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * fractol->zoom) + fractol->offset_x;
    c.im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * fractol->zoom) + fractol->offset_y;

    // Initialize z to 0 (complex number)
    z.re = 0;
    z.im = 0;

    // Iterate to check if the point escapes the Mandelbrot set
    while (z.re * z.re + z.im * z.im <= 4 && iter < fractol->max_iterate)
    {
        temp.re = z.re * z.re - z.im * z.im + c.re;
        temp.im = 2 * z.re * z.im + c.im;
        z = temp;
        iter++;
    }

    // Return the iteration count for coloring the pixel
    return iter;
}