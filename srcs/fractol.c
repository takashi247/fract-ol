#include "fractol.h"

void
	mlx_pixel_put_screen(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bpp / 8));
	*(unsigned int*)dst = color;
}

t_complex
	square_complex(t_complex z)
{
	t_complex	res;

	res.r = pow(z.r, 2.0) - pow(z.i, 2.0);
	res.i = 2.0 * z.r * z.i;
	return (res);
}

t_complex
	add_complex(t_complex z, t_complex c)
{
	t_complex	res;

	res.r = z.r + c.r;
	res.i = z.i + c.i;
	return (res);
}

double
	get_modulus(t_complex z)
{
	return (pow(z.r, 2.0) + pow(z.i, 2.0));
}

t_bool
	check_conversion(t_complex z, t_complex c)
{
	int			i;

	i = 0;
	while (i < MAX_ITERATION)
	{
		z = square_complex(z);
		z = add_complex(z, c);
		if (get_modulus(z) > THRESHOLD_RADIUS)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int
	main(int ac, char **av)
{
	void			*mlx;
	void			*mlx_win;
	static int		width = 1000;
	static int		height = 1000;
	t_screen		screen;
	int				col;
	int				row;
	t_complex		c;
	t_complex		z;

	(void)ac;
	c.r = atof(av[1]);
	c.i = atof(av[2]);
	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_win = mlx_new_window(mlx, width, height, "Hellow world!");
	if (!mlx_win)
		return (1);
	screen.img = mlx_new_image(mlx, width, height);
	if (!screen.img)
		return (1);
	screen.addr = mlx_get_data_addr(screen.img, &screen.bpp, &screen.line_length, &screen.endian);
	col = 0;
	while (col < width)
	{
		row = 0;
		while (row < height)
		{
			z.r = -2.0 + 4.0 * (double)col / (double)width;
			z.i = 2.0 - 4.0 * (double)row / (double)width;
			if (check_conversion(z, c))
				mlx_pixel_put_screen(&screen, col, row, 0x000000FF);
			row++;
		}
		col++;
	}
	mlx_put_image_to_window(mlx, mlx_win, screen.img, 0, 0);
	mlx_loop(mlx);
}
