#include "fractol.h"

static void
	zoom_in(double x, double y, t_fractol *fractol)
{
	fractol->min_real = ZOOM_FACTOR * fractol->min_real + (1 - ZOOM_FACTOR) * x;
	fractol->max_real = ZOOM_FACTOR * fractol->max_real + (1 - ZOOM_FACTOR) * x;
	fractol->max_imag = ZOOM_FACTOR * fractol->max_imag + (1 - ZOOM_FACTOR) * y;
	fractol->min_imag = ZOOM_FACTOR * fractol->min_imag + (1 - ZOOM_FACTOR) * y;
}

static void
	zoom_out(double x, double y, t_fractol *fractol)
{
	fractol->min_real = 1 / ZOOM_FACTOR * fractol->min_real
		- (1 - ZOOM_FACTOR) / ZOOM_FACTOR * x;
	fractol->max_real = 1 / ZOOM_FACTOR * fractol->max_real
		- (1 - ZOOM_FACTOR) / ZOOM_FACTOR * x;
	fractol->max_imag = 1 / ZOOM_FACTOR * fractol->max_imag
		- (1 - ZOOM_FACTOR) / ZOOM_FACTOR * y;
	fractol->min_imag = 1 / ZOOM_FACTOR * fractol->min_imag
		- (1 - ZOOM_FACTOR) / ZOOM_FACTOR * y;
}

int
	ft_zoom_w_mouse(int button, int x, int y, t_fractol *fractol)
{
	const double	pos_x = fractol->min_real
		+ (fractol->max_real - fractol->min_real) * x / SCREEN_WIDTH;
	const double	pos_y = fractol->max_imag
		- (fractol->max_imag - fractol->min_imag) * y / SCREEN_HEIGHT;

	if (button == MOUSE_ZOOM_IN)
		zoom_in(pos_x, pos_y, fractol);
	else if (button == MOUSE_ZOOM_OUT)
		zoom_out(pos_x, pos_y, fractol);
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}
