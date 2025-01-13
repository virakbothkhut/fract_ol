#include "fractol.h"

t_fractol *init_fractol(t_fractol_type type)
{
    t_fractol *fractol;

    fractol = (t_fractol *)malloc(sizeof(t_fractol));
    if (!fractol)
        return (NULL);

    fractol->mlx = mlx_init(WIDTH, HEIGHT, "Fract-ol", true);
    if (!fractol->mlx)
    {
        free(fractol);
        return (NULL);
    }

    fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
    if (!fractol->img)
    {
        mlx_terminate(fractol->mlx);
        free(fractol);
        return (NULL);
    }

    fractol->type = type;
    fractol->zoom = 1.0;
    fractol->offset_x = 0.0;
    fractol->offset_y = 0.0;
    fractol->max_iterate = 100;
    fractol->color_scheme = 0;
    fractol->julia_constant = (t_complex){.re = -0.7, .im = 0.27015};

    mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
    draw_fractal(fractol);

    return (fractol);
}

void setup_hooks(t_fractol *fractol)
{
    mlx_close_hook(fractol->mlx, close_hook, fractol);
    mlx_scroll_hook(fractol->mlx, &handle_mouse, fractol);
    mlx_key_hook(fractol->mlx, &handle_keyboard, fractol);
}

void cleanup(t_fractol *fractol)
{
    if (fractol)
    {
        if (fractol->mlx)
        {
            mlx_delete_image(fractol->mlx, fractol->img);
            mlx_terminate(fractol->mlx);
        }
        free(fractol);
    }
}

t_fractol_type parse_fractal_type(const char *arg)
{
    if (strcmp(arg, "mandelbrot") == 0)
        return (MANDELBROT);
    else if (strcmp(arg, "julia") == 0)
        return (JULIA);
    else
    {
        fprintf(stderr, "Invalid fractal type. Use 'mandelbrot' or 'julia'.\n");
        exit(EXIT_FAILURE);
    }
}

