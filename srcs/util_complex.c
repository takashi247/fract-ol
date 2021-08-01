#include "fractol.h"

t_complex
	ft_square_complex(t_complex z)
{
	t_complex	squared;

	squared.real = pow(z.real, 2.0) - pow(z.imag, 2.0);
	squared.imag = 2.0 * z.real * z.imag;
	return (squared);
}

t_complex
	ft_add_complex(t_complex z, t_complex c)
{
	t_complex	added;

	added.real = z.real + c.real;
	added.imag = z.imag + c.imag;
	return (added);
}

double
	ft_get_modulus(t_complex z)
{
	return (pow(z.real, 2.0) + pow(z.imag, 2.0));
}
