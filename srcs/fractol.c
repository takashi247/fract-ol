#include "fractol.h"

static t_bool
	init_fractol(t_fractol *fractol, char **av)
{
	fractol->type = *av[1];
	fractol->min_real = MIN_REAL;
	fractol->max_real = MAX_REAL;
	fractol->min_imag = MIN_IMAG;
	fractol->max_imag = MAX_IMAG;
	fractol->is_value_shift_mode = TRUE;
	fractol->base_hue = BLUE;
	if (fractol->type == 'j')
	{
		fractol->c.real = ft_atof(av[2]);
		fractol->c.imag = ft_atof(av[3]);
	}
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (FALSE);
	(fractol->screen).mlx_win = mlx_new_window(fractol->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
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

// need to update

static t_bool
	check_input(int ac, char **av)
{
	if (2 <= ac && !ft_strncmp(av[1], "m", 2))
		return (TRUE);
	else if (2 <= ac && !ft_strncmp(av[1], "b", 2))
		return (TRUE);
	else if (4 <= ac && !ft_strncmp(av[1], "j", 2))
		return (TRUE);
	else
		return (FALSE);
}

static void
	exit_with_instruction(void)
{
	const int	fd = open(PATH_TO_README, O_RDONLY);
	int			len;
	char		buf[BUF_SIZE];

	if (fd < 0)
		exit(1);
	while (1)
	{
		len = read(fd, buf, BUF_SIZE);
		if (!len)
			break ;
		write(STDOUT_FILENO, buf, len);
	}
	close(fd);
	exit(0);
}

int
	main(int ac, char **av)
{
	t_fractol		fractol;

	if (!check_input(ac, av))
		exit_with_instruction();
	if (!init_fractol(&fractol, av))
		exit_with_instruction();
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
}
