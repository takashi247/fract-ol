#include "fractol.h"

int
	ft_create_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

int
	ft_put_image_to_window(t_fractol *fractol)
{
	return (mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
			fractol->screen.img, 0, 0));
}

void
	ft_mlx_pixel_put_screen(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bpp / 8));
	*(unsigned int *)dst = color;
}

int
	ft_close_fractol(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, (fractol->screen).img);
	mlx_destroy_window(fractol->mlx, (fractol->screen).mlx_win);
	mlx_destroy_display(fractol->mlx);
	exit(EXIT_SUCCESS);
}

int
	ft_key_press(int key, t_fractol *fractol)
{
	if (key == K_ESC)
		ft_close_fractol(fractol);
	else if (key == K_C)
		return (ft_change_color_mode(fractol));
	else if (key == K_R)
		return (ft_make_red(fractol));
	else if (key == K_G)
		return (ft_make_green(fractol));
	else if (key == K_B)
		return (ft_make_blue(fractol));
	else if (key == K_AR_U)
		return (ft_shift_window_up(fractol));
	else if (key == K_AR_D)
		return (ft_shift_window_down(fractol));
	else if (key == K_AR_L)
		return (ft_shift_window_left(fractol));
	else if (key == K_AR_R)
		return (ft_shift_window_right(fractol));
	return (0);
}
