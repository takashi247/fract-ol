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
