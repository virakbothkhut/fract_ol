#include "fractol.h"

void	handle_mouse(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	double		x_ratio;
	double		y_ratio;

	fractol = (t_fractol *)param;
	x_ratio = (xdelta - WIDTH / 2) / (double)WIDTH;
	y_ratio = (ydelta - HEIGHT / 2) / (double)HEIGHT;
	if (ydelta > 0)
	{
		fractol->zoom *= 1.1;
		fractol->offset_x += x_ratio * 0.1 / fractol->zoom;
		fractol->offset_y += y_ratio * 0.1 / fractol->zoom;
	}
	else if (ydelta < 0)
	{
		fractol->zoom /= 1.1;
		fractol->offset_x -= x_ratio * 0.1 / fractol->zoom;
		fractol->offset_y -= y_ratio * 0.1 / fractol->zoom;
	}
	draw_fractal(fractol);
}

void	handle_keyboard(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fractol->mlx);
	keys_handle_move(keydata, fractol);
	keys_handle_zoom(keydata, fractol);
	key_handle_random_julia(keydata, fractol);
	draw_fractal(fractol);
}

void	keys_handle_move(mlx_key_data_t keydata, t_fractol *fractol)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		fractol->offset_y -= 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		fractol->offset_y += 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		fractol->offset_x -= 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		fractol->offset_x += 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		fractol->offset_y -= 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		fractol->offset_y += 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		fractol->offset_x -= 0.1 / fractol->zoom;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		fractol->offset_x += 0.1 / fractol->zoom;
}

void	keys_handle_zoom(mlx_key_data_t keydata, t_fractol *fractol)
{
	if (keydata.key == MLX_KEY_EQUAL && keydata.action == MLX_PRESS)
		fractol->zoom *= 1.1;
	else if (keydata.key == MLX_KEY_MINUS && keydata.action == MLX_PRESS)
		fractol->zoom /= 1.1;
}

void	key_handle_random_julia(mlx_key_data_t keydata, t_fractol *fractol)
{
	if (keydata.key == MLX_KEY_R)
	{
		rand_julia_const(fractol);
		draw_fractal(fractol);
	}
}
