#include "fractol.h"

static void
	draw_burning_ship(t_fractol fractol, int col, int row)
{
	t_complex	z;
	t_complex	c;
	int			num_iteration;
	int			color;

	ft_bzero(&z, sizeof(t_complex));
	c.real = fractol.min_real + (fractol.max_real - fractol.min_real)
		* (double)col / (double)SCREEN_WIDTH;
	c.imag = fractol.min_imag + (fractol.max_imag - fractol.min_imag)
		* (double)row / (double)SCREEN_HEIGHT;
	num_iteration = ft_count_iteration_b(z, c, fractol.max_iter);
	if (fractol.is_value_shift_mode)
		color = ft_get_color_v(num_iteration, fractol.base_hue,
				fractol.max_iter);
	else
		color = ft_get_color_h(num_iteration, fractol.max_iter);
	ft_mlx_pixel_put_screen(&(fractol.screen), col, row, color);
}

static void
	draw_mandelbrot(t_fractol fractol, int col, int row)
{
	t_complex	z;
	t_complex	c;
	int			num_iteration;
	int			color;

	ft_bzero(&z, sizeof(t_complex));
	c.real = fractol.min_real + (fractol.max_real - fractol.min_real)
		* (double)col / (double)SCREEN_WIDTH;
	c.imag = fractol.min_imag + (fractol.max_imag - fractol.min_imag)
		* (double)row / (double)SCREEN_HEIGHT;
	num_iteration = ft_count_iteration(z, c, fractol.max_iter);
	if (fractol.is_value_shift_mode)
		color = ft_get_color_v(num_iteration, fractol.base_hue,
				fractol.max_iter);
	else
		color = ft_get_color_h(num_iteration, fractol.max_iter);
	ft_mlx_pixel_put_screen(&(fractol.screen), col, row, color);
}

static void
	draw_julia(t_fractol fractol, int col, int row)
{
	t_complex	z;
	int			num_iteration;
	int			color;

	z.real = fractol.min_real + (fractol.max_real - fractol.min_real)
		* (double)col / SCREEN_WIDTH;
	z.imag = fractol.min_imag + (fractol.max_imag - fractol.min_imag)
		* (double)row / SCREEN_HEIGHT;
	num_iteration = ft_count_iteration(z, fractol.c, fractol.max_iter);
	if (fractol.is_value_shift_mode)
		color = ft_get_color_v(num_iteration, fractol.base_hue,
				fractol.max_iter);
	else
		color = ft_get_color_h(num_iteration, fractol.max_iter);
	ft_mlx_pixel_put_screen(&(fractol.screen), col, row, color);
}

void
	ft_draw_fractal(t_fractol fractol)
{
	int	col;
	int	row;

	col = 0;
	while (col < SCREEN_WIDTH)
	{
		row = 0;
		while (row < SCREEN_HEIGHT)
		{
			if (fractol.type == 'j')
				draw_julia(fractol, col, row);
			else if (fractol.type == 'm')
				draw_mandelbrot(fractol, col, row);
			else if (fractol.type == 'b')
				draw_burning_ship(fractol, col, row);
			row++;
		}
		col++;
	}
}
