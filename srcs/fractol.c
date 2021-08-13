#include "fractol.h"

static void
	set_initial_values(t_fractol *fractol, char **av)
{
	ft_bzero(fractol, sizeof(t_fractol));
	fractol->min_real = MIN_REAL;
	fractol->max_real = MAX_REAL;
	fractol->min_imag = MIN_IMAG;
	fractol->max_imag = MAX_IMAG;
	fractol->is_value_shift_mode = FALSE;
	fractol->base_hue = BLUE;
	fractol->type = *av[1];
}

static t_bool
	init_fractol(t_fractol *fractol, char **av)
{
	set_initial_values(fractol, av);
	if (fractol->type == 'j')
	{
		fractol->c.real = ft_atof(av[2]);
		fractol->c.imag = ft_atof(av[3]);
	}
	if (isinf(fractol->c.real) || isinf(fractol->c.imag))
		return (FALSE);
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (FALSE);
	(fractol->screen).mlx_win = mlx_new_window(fractol->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, PROGRAM_NAME);
	if (!((fractol->screen).mlx_win))
		return (FALSE);
	(fractol->screen).img = mlx_new_image(fractol->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!((fractol->screen).img))
		return (FALSE);
	(fractol->screen).addr = mlx_get_data_addr((fractol->screen).img,
			&(fractol->screen).bpp, &(fractol->screen).line_length,
			&(fractol->screen).endian);
	if (!((fractol->screen).addr))
		return (FALSE);
	return (TRUE);
}

static t_bool
	check_input(int ac, char **av)
{
	if (2 <= ac && !ft_strncmp(av[1], "m", 2))
		return (TRUE);
	else if (2 <= ac && !ft_strncmp(av[1], "b", 2))
		return (TRUE);
	else if (4 <= ac && !ft_strncmp(av[1], "j", 2) && ft_isnumeric(av[2])
		&& ft_isnumeric(av[3]))
		return (TRUE);
	else
		return (FALSE);
}

static void
	exit_with_instruction(t_fractol *fractol)
{
	int			fd;
	int			len;
	char		buf[BUF_SIZE];

	fd = open(PATH_TO_README, O_RDONLY);
	if (fd < 0)
	{
		perror(PROGRAM_NAME);
		ft_close_fractol(fractol, EXIT_FAILURE);
	}
	while (1)
	{
		len = read(fd, buf, BUF_SIZE);
		if (!len)
			break ;
		write(STDOUT_FILENO, buf, len);
	}
	close(fd);
	ft_close_fractol(fractol, EXIT_SUCCESS);
}

int
	main(int ac, char **av)
{
	t_fractol		fractol;

	if (!check_input(ac, av))
		exit_with_instruction(NULL);
	if (!init_fractol(&fractol, av))
		exit_with_instruction(&fractol);
	ft_draw_fractal(fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.screen.mlx_win,
		fractol.screen.img, 0, 0);
	mlx_hook(fractol.screen.mlx_win, CLIENT_MESSAGE, STRUCTURE_NOTIFY_MASK,
		ft_close_fractol, &fractol);
	mlx_hook(fractol.screen.mlx_win, KEY_PRESS, KEY_PRESS_MASK, ft_key_press,
		&fractol);
	mlx_hook(fractol.screen.mlx_win, BUTTON_PRESS, BUTTON_PRESS_MASK,
		ft_zoom_w_mouse, &fractol);
	mlx_hook(fractol.screen.mlx_win, FOCUS_IN, FOCUS_CHANGE_MASK,
		ft_put_image_to_window, &fractol);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
}
