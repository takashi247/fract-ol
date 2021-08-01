#include "fractol.h"

void
	ft_mlx_pixel_put_screen(t_screen *screen, int x, int y, int color)
{
	char	*dst;

	dst = screen->addr + (y * screen->line_length + x * (screen->bpp / 8));
	*(unsigned int *)dst = color;
}
