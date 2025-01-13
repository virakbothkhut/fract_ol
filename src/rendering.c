#include "fractol.h"

void draw_fractal(t_fractol *fractol)
{
    if (fractol->type == MANDELBROT)
        draw_mandelbrot(fractol);
    else if (fractol->type == JULIA)
        draw_julia(fractol);
    mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}
