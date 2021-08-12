#include "fractol.h"

int
	ft_shift_window_up(t_fractol *fractol)
{
	fractol->min_imag += (fractol->max_imag - fractol->min_imag) / 20;
	fractol->max_imag += (fractol->max_imag - fractol->min_imag) / 20;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}

int
	ft_shift_window_down(t_fractol *fractol)
{
	fractol->min_imag -= (fractol->max_imag - fractol->min_imag) / 20;
	fractol->max_imag -= (fractol->max_imag - fractol->min_imag) / 20;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}

int
	ft_shift_window_right(t_fractol *fractol)
{
	fractol->min_real += (fractol->max_real - fractol->min_real) / 20;
	fractol->max_real += (fractol->max_real - fractol->min_real) / 20;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}

int
	ft_shift_window_left(t_fractol *fractol)
{
	fractol->min_real -= (fractol->max_real - fractol->min_real) / 20;
	fractol->max_real -= (fractol->max_real - fractol->min_real) / 20;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}
