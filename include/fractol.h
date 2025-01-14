/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhut <vkhut@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 22:46:39 by vkhut             #+#    #+#             */
/*   Updated: 2025/01/14 19:55:47 by vkhut            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 750
# define HEIGHT 750

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <memory.h>
# include "MLX42/MLX42.h"

typedef enum e_fractol_type
{
	MANDELBROT,
	JULIA,
}	t_fractol_type;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractol
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fractol_type	type;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				max_iterate;
	int				color_scheme;
	t_complex		julia_constant;
}	t_fractol;

// fractol
int				init_mlx(t_fractol *fractol);
void			setup_hooks(t_fractol *fractol);
void			draw_fractal(t_fractol *fractol);
void			draw_fractol_update(t_fractol *fractol);
t_fractol		*init_fractol(t_fractol_type type);

// mandelbrot
void			draw_mandelbrot(t_fractol *fractol);
int				calculate_mandelbrot(t_fractol *fractol, int x, int y);

//julia
void			draw_julia(t_fractol *fractol);
t_complex		map_complex_plan(int x, int y, t_fractol *fractol);
int				iter_frac(t_complex *z, t_fractol *fractol);
void			rand_julia_const(t_fractol *fractol);

//rendering
void			handle_mouse(double xdelta, double ydelta, void *param);
void			handle_keyboard(mlx_key_data_t keydata, void *param);
void			keys_handle_move(mlx_key_data_t keydata, t_fractol *fractol);
void			keys_handle_zoom(mlx_key_data_t keydata, t_fractol *fractol);
void			key_handle_rd_julia(mlx_key_data_t keydata, t_fractol *fractol);

//utils
void			cleanup(t_fractol *fractol);
int				ft_strcmp(const char *s1, const char *s2);
t_fractol		*init_fract_struc(t_fractol_type type);
t_fractol_type	parse_fractal_type(const char *arg);

//main 
int				key_hook(int keycode, void *param);
void			close_hook(void *param);
int				get_color(int iter, int max_iterate, int color_scheme);

#endif