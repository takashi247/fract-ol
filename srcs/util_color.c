#include "fractol.h"

int
	ft_count_iteration(t_complex z, t_complex c, int max_iteration)
{
	int	num_iteration;

	num_iteration = 0;
	while (num_iteration < max_iteration)
	{
		z = ft_square_complex(z);
		z = ft_add_complex(z, c);
		if (ft_get_modulus(z) > THRESHOLD_RADIUS * THRESHOLD_RADIUS)
			return (num_iteration);
		num_iteration++;
	}
	return (num_iteration);
}

int
	ft_count_iteration_b(t_complex z, t_complex c, int max_iteration)
{
	int		num_iteration;
	double	z_real_tmp;

	num_iteration = 0;
	while (num_iteration < max_iteration)
	{
		z_real_tmp = pow(z.real, 2.0) - pow(z.imag, 2.0) + c.real;
		z.imag = fabs(2 * z.real * z.imag) + c.imag;
		z.real = z_real_tmp;
		if (ft_get_modulus(z) > THRESHOLD_RADIUS * THRESHOLD_RADIUS)
			return (num_iteration);
		num_iteration++;
	}
	return (num_iteration);
}

static int
	convert_hsv_to_rgb(int hue, int satulation, int value)
{
	const int		hi = (hue * 360 / 255 / 60) % 6;
	const double	f = hue * 360 / 255 / 60 - hi;
	const int		p = (int)(value * (1 - satulation) / 255);
	const int		q = (int)(value * (1 - f * satulation) / 255);
	const int		t = (int)(value * (1 - (1 - f) * satulation) / 255);

	if (hi == 0)
		return (ft_create_rgb(value, t, p));
	else if (hi == 1)
		return (ft_create_rgb(q, value, p));
	else if (hi == 2)
		return (ft_create_rgb(p, value, t));
	else if (hi == 3)
		return (ft_create_rgb(p, q, value));
	else if (hi == 4)
		return (ft_create_rgb(t, p, value));
	else
		return (ft_create_rgb(value, p, q));
}

int
	ft_get_color_h(int num_iteration, int max_iteration)
{
	const int	hue = (int)(255 * num_iteration / max_iteration);
	const int	satulation = 255;
	int			value;

	if (num_iteration < max_iteration)
		value = 255;
	else
		value = 0;
	return (convert_hsv_to_rgb(hue, satulation, value));
}

int
	ft_get_color_v(int num_iteration, int base_hue, int max_iteration)
{
	const int	hue = base_hue;
	const int	satulation = 0;
	int			value;

	if (!num_iteration)
		num_iteration++;
	if (num_iteration < max_iteration)
		value = (int)(255 * num_iteration / max_iteration);
	else
		return (0);
	return (convert_hsv_to_rgb(hue, satulation, value));
}
