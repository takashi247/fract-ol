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
	ft_get_color(int num_iteration, int max_iteration)
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
