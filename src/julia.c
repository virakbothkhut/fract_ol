/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:52:03 by vkhut             #+#    #+#             */
/*   Updated: 2025/01/13 23:15:00 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_fractol *fractol)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = map_complex_plan(x, y, fractol);
			iter = iter_frac(&z, fractol);
			mlx_put_pixel(fractol->img, x, y,
				get_color(iter, fractol->max_iterate, fractol->color_scheme));
			x++;
		}
		y++;
	}
}

t_complex	map_complex_plan(int x, int y, t_fractol *fractol)
{
	t_complex	z;

	z.re = (x - WIDTH / 2.0) * 4.0 / WIDTH / fractol->zoom
		+fractol->offset_x;
	z.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / fractol->zoom
		+fractol->offset_y;
	return (z);
}

int	iter_frac(t_complex *z, t_fractol *fractol)
{
	int			iter;
	t_complex	tmp;

	iter = 0;
	while (z->re * z->re + z->im * z->im <= 4 && iter < fractol->max_iterate)
	{
		tmp.re = z->re * z->re - z->im * z->im + fractol->julia_constant.re;
		tmp.im = 2 * z->re * z->im + fractol->julia_constant.im;
		*z = tmp;
		iter++;
	}
	return (iter);
}

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
	fractol->color_scheme = 4.5;
	fractol->mlx = NULL;
	fractol->img = NULL;
	if (type == JULIA)
	{
		rand_julia_const(fractol);
	}
	return (fractol);
}

void	rand_julia_const(t_fractol *fractol)
{
	int	choice;

	choice = rand() % 3;
	if (choice == 0)
	{
		fractol->julia_constant.re = -0.8;
		fractol->julia_constant.im = 0.156;
	}
	else if (choice == 1)
	{
		fractol->julia_constant.re = 0.285;
		fractol->julia_constant.im = 0.01;
	}
	else if (choice == 2)
	{
		fractol->julia_constant.re = -0.70176;
		fractol->julia_constant.im = -0.3842;
	}
	else if (choice == 3)
	{
		fractol->julia_constant.re = -0.701;
		fractol->julia_constant.im = 0.27015;
	}
}
