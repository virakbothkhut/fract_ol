#include "fractol.h"

void handle_mouse(double xdelta, double ydelta, void *param)
{
    t_fractol *fractol = (t_fractol *)param;
    (void)xdelta;

    if (ydelta > 0)
        fractol->zoom *= 1.1;
    else if (ydelta < 0)
        fractol->zoom /= 1.1;
    draw_fractal(fractol);
}

void handle_keyboard(mlx_key_data_t keydata, void *param)
{
    t_fractol *fractol = (t_fractol *)param;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        mlx_close_window(fractol->mlx);
    else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
        fractol->offset_y -= 0.1 / fractol->zoom;
    else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
        fractol->offset_y += 0.1 / fractol->zoom;
    else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
        fractol->offset_x -= 0.1 / fractol->zoom;
    else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
        fractol->offset_x += 0.1 / fractol->zoom;
    else if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS) // '+' key
        fractol->zoom *= 1.1;
    else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS) // '-' key
        fractol->zoom /= 1.1;
    draw_fractal(fractol);
}