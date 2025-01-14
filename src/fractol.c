/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:51:51 by vkhut             #+#    #+#             */
/*   Updated: 2025/01/13 22:51:52 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

t_fractol_type	parse_fractal_type(const char *arg)
{
	if (strcmp(arg, "mandelbrot") == 0)
		return (MANDELBROT);
	else if (strcmp(arg, "julia") == 0)
		return (JULIA);
	else
	{
		printf("Invalid fractal type. Use 'mandelbrot' or 'julia'.\n");
		exit(EXIT_FAILURE);
	}
}
