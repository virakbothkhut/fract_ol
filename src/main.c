/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:52:09 by vkhut             #+#    #+#             */
/*   Updated: 2025/01/13 23:03:53 by vkhut            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc != 2)
	{
		printf("Usage: %s <fractal_type>\n", argv[0]);
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
