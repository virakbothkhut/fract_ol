/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:51:51 by vkhut             #+#    #+#             */
/*   Updated: 2025/01/14 19:55:24 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_hooks(t_fractol *fractol)
{
	mlx_close_hook(fractol->mlx, close_hook, fractol);
	mlx_scroll_hook(fractol->mlx, &handle_mouse, fractol);
	mlx_key_hook(fractol->mlx, &handle_keyboard, fractol);
}

void	draw_fractol_update(t_fractol *fractol)
{
	draw_fractal(fractol);
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}

void	draw_fractal(t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
		draw_mandelbrot(fractol);
	else if (fractol->type == JULIA)
		draw_julia(fractol);
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}

t_fractol	*init_fractol(t_fractol_type type)
{
	t_fractol	*fractol;

	fractol = init_fract_struc(type);
	if (!fractol)
		return (NULL);
	if (!init_mlx(fractol))
	{
		free(fractol);
		return (NULL);
	}
	draw_fractol_update(fractol);
	return (fractol);
}

int	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", true);
	if (!fractol->mlx)
		return (0);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
	{
		mlx_terminate(fractol->mlx);
		return (0);
	}
	return (1);
}
