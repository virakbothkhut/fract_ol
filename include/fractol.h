#ifndef FRACTOL_H
# define FRACTOL_H

// #define JULIA 1
// #define MANDELBROT 2

#define WIDTH 750
#define HEIGHT 750 

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include "MLX42/MLX42.h"

typedef enum e_fractol_type
{
    MANDELBROT,
    JULIA, 
}t_fractol_type;

typedef struct s_complex
{
    double re; // Real part
    double im; // Imaginary part
} t_complex;


typedef struct s_fractol
{
    mlx_t *mlx;                 // MLX instance
    mlx_image_t *img;           // Image to render the fractal
    t_fractol_type type;        // Type of fractal
    double zoom;                // Zoom level
    double offset_x;            // Horizontal offset
    double offset_y;            // Vertical offset
    int max_iterate;            // Maximum iterations for fractal calculation
    int color_scheme;           // Color scheme identifier
    t_complex julia_constant;   // Constant for Julia set calculations
} t_fractol;

// fractol
t_fractol *init_fractol(t_fractol_type type);
void	setup_hooks(t_fractol *fractol);
void 	cleanup(t_fractol *fractol);
t_fractol_type parse_fractal_type(const char *arg);

// mandelbrot
void	draw_mandelbrot(t_fractol *fractol);

//julia
int		get_color(int iter, int max_iterate, int color_scheme);
void	draw_julia(t_fractol *fractol);

//rendering
void	draw_fractal(t_fractol *fractol);

//input
void	handle_mouse(double xdelta, double ydelta, void *param);
void	handle_keyboard(mlx_key_data_t keydata, void *param);

void	fill_background(mlx_image_t *img, int color);

//main 
int		key_hook(int keycode, void *param);
void	close_hook(void *param);

int		calculate_mandelbrot(t_fractol *fractol, int x, int y)
#endif