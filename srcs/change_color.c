#include "fractol.h"

int
	ft_make_red(t_fractol *fractol)
{
	fractol->base_hue = RED;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}

int
	ft_make_blue(t_fractol *fractol)
{
	fractol->base_hue = BLUE;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}

int
	ft_make_green(t_fractol *fractol)
{
	fractol->base_hue = GREEN;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}

int
	ft_change_color_mode(t_fractol *fractol)
{
	if (fractol->is_value_shift_mode)
		fractol->is_value_shift_mode = FALSE;
	else
		fractol->is_value_shift_mode = TRUE;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}
