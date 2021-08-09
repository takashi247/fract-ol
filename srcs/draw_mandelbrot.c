#include "fractol.h"

void
	ft_draw_mandelbrot(t_fractol fractol)
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
			c.real = -2.5 + 4.0 * (double)col / (double)fractol.screen.width;
			c.imag = 2.0 - 4.0 * (double)row / (double)fractol.screen.height;
			num_iteration = ft_count_iteration(z, c);
			ft_mlx_pixel_put_screen(&(fractol.screen), col, row,
				ft_get_color(num_iteration));
			row++;
		}
		col++;
	}
}
