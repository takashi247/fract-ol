#include "fractol.h"

void
	mlx_pixel_put_screen(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bpp / 8));
	*(unsigned int *)dst = color;
}

t_complex
	square_complex(t_complex z)
{
	t_complex	squared;

	squared.real = pow(z.real, 2.0) - pow(z.imag, 2.0);
	squared.imag = 2.0 * z.real * z.imag;
	return (squared);
}

t_complex
	add_complex(t_complex z, t_complex c)
{
	t_complex	added;

	added.real = z.real + c.real;
	added.imag = z.imag + c.imag;
	return (added);
}

double
	get_modulus(t_complex z)
{
	return (pow(z.real, 2.0) + pow(z.imag, 2.0));
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
		if (get_modulus(z) > pow(THRESHOLD_RADIUS, 2.0))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char
	*set_title(const char type)
{
	if (type == 'j')
		return (SCREEN_TITLE_JULIA);
	else if (type == 'm')
		return (SCREEN_TITLE_MANDELBROT);
	else
		return (NULL);
}

t_bool
	init_fractol(t_fractol *fractol, int ac, char **av)
{
	(void)ac;
	fractol->type = *av[1];
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (FALSE);
	(fractol->screen).width = atoi(av[2]);
	(fractol->screen).height = atoi(av[3]);
	(fractol->screen).title = set_title(fractol->type);
	(fractol->screen).mlx_win = mlx_new_window(fractol->mlx,
			(fractol->screen).width, (fractol->screen).height,
			(fractol->screen).title);
	if (!((fractol->screen).mlx_win))
		return (FALSE);
	(fractol->screen).img = mlx_new_image(fractol->mlx,
			(fractol->screen).width, (fractol->screen).height);
	if (!((fractol->screen).img))
		return (FALSE);
	(fractol->screen).addr = mlx_get_data_addr((fractol->screen).img,
			&(fractol->screen).bpp, &(fractol->screen).line_length,
			&(fractol->screen).endian);
	if (!((fractol->screen).addr))
		return (FALSE);
	return (TRUE);
}

/* need to update */

t_bool
	check_input(int ac, char **av)
{
	(void)ac;
	(void)av;
	return (TRUE);
}

/* need to update */

void
	exit_with_error(void)
{
	exit(1);
}

void
	draw_julia(t_fractol fractol, t_complex c)
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
				mlx_pixel_put_screen(&(fractol.screen), col, row, 0x000000FF);
			row++;
		}
		col++;
	}
}

/* need to update */

void
	draw_mandelbrot(t_fractol fractal, t_complex c)
{
	(void)fractal;
	(void)c;
}

int
	main(int ac, char **av)
{
	t_fractol		fractol;
	t_complex		c;

	if (!check_input(ac, av))
		exit_with_error();
	if (!init_fractol(&fractol, ac, av))
		exit_with_error();
	c.real = atof(av[4]);
	c.imag = atof(av[5]);
	if (fractol.type == 'j')
		draw_julia(fractol, c);
	else if (fractol.type == 'm')
		draw_mandelbrot(fractol, c);
	mlx_put_image_to_window(fractol.mlx, fractol.screen.mlx_win,
		fractol.screen.img, 0, 0);
	mlx_loop(fractol.mlx);
}
