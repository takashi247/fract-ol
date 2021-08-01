#include "fractol.h"

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

// need to update

t_bool
	check_input(int ac, char **av)
{
	(void)ac;
	(void)av;
	return (TRUE);
}

// need to update

void
	exit_with_error(void)
{
	exit(1);
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
	if (fractol.type == 'j')
	{
		c.real = atof(av[4]);
		c.imag = atof(av[5]);
		ft_draw_julia(fractol, c);
	}
	else if (fractol.type == 'm')
		ft_draw_mandelbrot(fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.screen.mlx_win,
		fractol.screen.img, 0, 0);
	mlx_hook(fractol.screen.mlx_win, CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK,
		ft_close_fractol, &fractol);
	mlx_hook(fractol.screen.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_key_press,
		&fractol);
	mlx_loop(fractol.mlx);
}
