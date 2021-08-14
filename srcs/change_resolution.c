#include "fractol.h"

int
	ft_change_resolution(int key, t_fractol *fractol)
{
	if (key == K_W)
		fractol->max_iter += ITER_STEP;
	else if (fractol->max_iter - ITER_STEP >= MIN_ITER)
		fractol->max_iter -= ITER_STEP;
	ft_draw_fractal(*fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->screen.mlx_win,
		fractol->screen.img, 0, 0);
	return (HOOK_SUCCESS);
}
