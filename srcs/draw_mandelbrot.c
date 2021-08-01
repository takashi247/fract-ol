#include "fractol.h"

static t_bool
	check_conversion(t_complex z, t_complex c)
{
	int			i;

	i = 0;
	while (i < MAX_ITERATION)
	{
		z = ft_square_complex(z);
		z = ft_add_complex(z, c);
		if (ft_get_modulus(z) > pow(THRESHOLD_RADIUS, 2.0))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void
	ft_draw_mandelbrot(t_fractol fractol)
{
	int			col;
	int			row;
	t_complex	z;
	t_complex	c;

	z.real = 0.0;
	z.imag = 0.0;
	col = 0;
	while (col < fractol.screen.width)
	{
		row = 0;
		while (row < fractol.screen.height)
		{
			c.real = -2.5 + 3.5 * (double)col / (double)fractol.screen.width;
			c.imag = 1.0 - 2.0 * (double)row / (double)fractol.screen.height;
			if (check_conversion(z, c))
				ft_mlx_pixel_put_screen(&(fractol.screen), col, row, BLUE);
			row++;
		}
		col++;
	}
}
