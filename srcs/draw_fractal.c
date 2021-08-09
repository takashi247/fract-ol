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
	while (col < fractol.screen.width)
	{
		row = 0;
		while (row < fractol.screen.height)
		{
			c.real = fractol.min_real + (fractol.max_real - fractol.min_real)
				* (double)col / (double)fractol.screen.width;
			c.imag = fractol.max_imag - (fractol.max_imag - fractol.min_imag)
				* (double)row / (double)fractol.screen.height;
			num_iteration = ft_count_iteration(z, c);
			ft_mlx_pixel_put_screen(&(fractol.screen), col, row,
				ft_get_color(num_iteration));
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
	while (col < fractol.screen.width)
	{
		row = 0;
		while (row < fractol.screen.height)
		{
			z.real = fractol.min_real + (fractol.max_real - fractol.min_real)
				* (double)col / (double)fractol.screen.width;
			z.imag = fractol.max_imag - (fractol.max_imag - fractol.min_imag)
				* (double)row / (double)fractol.screen.height;
			num_iteration = ft_count_iteration(z, fractol.c);
			ft_mlx_pixel_put_screen(&(fractol.screen), col, row,
				ft_get_color(num_iteration));
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
