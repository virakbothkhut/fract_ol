#include "fractol.h"

int get_color(int iter, int max_iterate, int color_scheme) {
    double t = (double)iter / (double)max_iterate;
    int r, g, b;

    if (color_scheme == 1) {
        // Red to Blue gradient
        r = (int)(255 * 9 * (1 - t) * t * t * t);
        g = (int)(255 * 15 * (1 - t) * (1 - t) * t * t);
        b = (int)(255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t);
    } else if (color_scheme == 2) {
        // Yellow to Red gradient
        r = (int)(255 * 15 * (1 - t) * t * t * t);
        g = (int)(255 * 8.5 * (1 - t) * (1 - t) * t * t);
        b = (int)(255 * 9 * (1 - t) * (1 - t) * (1 - t) * t);
    } else {
        // Default: Soft blue-green gradient
        r = (int)(255 * 8.5 * (1 - t) * t * t * t);
        g = (int)(255 * 9 * (1 - t) * (1 - t) * t * t);
        b = (int)(255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t);
    }

    return (r << 16) | (g << 8) | b; // Combine RGB into a single integer
}


void draw_julia(t_fractol *fractol)
{
    int x, y, iter;
    t_complex z, temp;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            z.re = (x - WIDTH / 2.0) * 4.0 / WIDTH / fractol->zoom + fractol->offset_x;
            z.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / fractol->zoom + fractol->offset_y;
            iter = 0;
            while (z.re * z.re + z.im * z.im <= 4 && iter < fractol->max_iterate)
            {
                temp.re = z.re * z.re - z.im * z.im + fractol->julia_constant.re;
                temp.im = 2 * z.re * z.im + fractol->julia_constant.im;
                z = temp;
                iter++;
            }
            mlx_put_pixel(fractol->img, x, y, get_color(iter, fractol->max_iterate, fractol->color_scheme));
        }
    }
}

