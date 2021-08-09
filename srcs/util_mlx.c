#include "fractol.h"

int
	ft_create_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
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
	else if (key == K_W)
		return (0);
	else if (key == K_A)
		return (0);
	else if (key == K_S)
		return (0);
	else if (key == K_D)
		return (0);
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
