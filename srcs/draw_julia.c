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
	ft_draw_julia(t_fractol fractol, t_complex c)
{
	int			col;
	int			row;
	t_complex	z;

	col = 0;
	while (col < fractol.screen.width)
	{
		row = 0;
		while (row < fractol.screen.height)
		{
			z.real = -2.0 + 4.0 * (double)col / (double)fractol.screen.width;
			z.imag = 2.0 - 4.0 * (double)row / (double)fractol.screen.height;
			if (check_conversion(z, c))
				ft_mlx_pixel_put_screen(&(fractol.screen), col, row, BLUE);
			row++;
		}
		col++;
	}
}
