#include "fractol.h"

static void
	draw_mandelbrot(t_fractol fractol)
{
	int			col;
	int			row;
	t_complex	z;
	t_complex	c;
	int			num_iteration;

	ft_bzero(&z, sizeof(t_complex));
	col = 0;
	while (col < SCREEN_WIDTH)
	{
		row = 0;
		while (row < SCREEN_HEIGHT)
		{
			c.real = fractol.min_real + (fractol.max_real - fractol.min_real)
				* (double)col / (double)SCREEN_WIDTH;
			c.imag = fractol.max_imag - (fractol.max_imag - fractol.min_imag)
				* (double)row / (double)SCREEN_HEIGHT;
			num_iteration = ft_count_iteration(z, c, MAX_ITERATION_M);
			ft_mlx_pixel_put_screen(&(fractol.screen), col, row,
				ft_get_color(num_iteration, MAX_ITERATION_M));
			row++;
		}
		col++;
	}
}

static void
	draw_julia(t_fractol fractol)
{
	int			col;
	int			row;
	t_complex	z;
	int			num_iteration;

	col = 0;
	while (col < SCREEN_WIDTH)
	{
		row = 0;
		while (row < SCREEN_HEIGHT)
		{
			z.real = fractol.min_real + (fractol.max_real - fractol.min_real)
				* (double)col / SCREEN_WIDTH;
			z.imag = fractol.max_imag - (fractol.max_imag - fractol.min_imag)
				* (double)row / SCREEN_HEIGHT;
			num_iteration = ft_count_iteration(z, fractol.c, MAX_ITERATION_J);
			ft_mlx_pixel_put_screen(&(fractol.screen), col, row,
				ft_get_color(num_iteration, MAX_ITERATION_J));
			row++;
		}
		col++;
	}
}

void
	ft_draw_fractal(t_fractol fractol)
{
	if (fractol.type == 'j')
		draw_julia(fractol);
	else if (fractol.type == 'm')
		draw_mandelbrot(fractol);
}
