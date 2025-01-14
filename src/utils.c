/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:20:57 by vkhut             #+#    #+#             */
/*   Updated: 2025/01/14 19:54:56 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*init_fract_struc(t_fractol_type type)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (NULL);
	fractol->type = type;
	fractol->zoom = 1.0;
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->max_iterate = 200;
	fractol->color_scheme = 4;
	fractol->mlx = NULL;
	fractol->img = NULL;
	if (type == JULIA)
	{
		rand_julia_const(fractol);
	}
	return (fractol);
}

void	cleanup(t_fractol *fractol)
{
	if (fractol)
	{
		if (fractol->mlx)
		{
			if (fractol->img)
			{
				mlx_delete_image(fractol->mlx, fractol->img);
			}
			mlx_terminate(fractol->mlx);
		}
		free(fractol);
	}
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

t_fractol_type	parse_fractal_type(const char *arg)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
		return (MANDELBROT);
	else if (ft_strcmp(arg, "julia") == 0)
		return (JULIA);
	else
	{
		printf("Invalid fractal type. Use 'mandelbrot' or 'julia'.\n");
		exit(EXIT_FAILURE);
	}
}
