/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:52:09 by vkhut             #+#    #+#             */
/*   Updated: 2025/01/14 19:55:34 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, void *param)
{
	if (keycode == 53)
	{
		mlx_loop(param);
	}
	return (0);
}

void	close_hook(void *param)
{
	mlx_loop(param);
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

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2)
	{
		printf("Please type: %s <fractal_type>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	fractol = init_fractol(parse_fractal_type(argv[1]));
	if (!fractol)
		return (EXIT_FAILURE);
	setup_hooks(fractol);
	mlx_loop(fractol->mlx);
	cleanup(fractol);
	return (EXIT_SUCCESS);
}
