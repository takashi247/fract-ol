#include "fractol.h"

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
		return (0);
	else if (key == K_AR_D)
		return (0);
	else if (key == K_AR_L)
		return (0);
	else if (key == K_AR_R)
		return (0);
	return (0);
}
