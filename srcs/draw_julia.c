#include "fractol.h"

void
	ft_draw_julia(t_fractol fractol, t_complex c)
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
			z.real = -2.0 + 4.0 * (double)col / (double)fractol.screen.width;
			z.imag = 2.0 - 4.0 * (double)row / (double)fractol.screen.height;
			num_iteration = ft_count_iteration(z, c);
			ft_mlx_pixel_put_screen(&(fractol.screen), col, row,
				ft_get_color(num_iteration));
			row++;
		}
		col++;
	}
}
