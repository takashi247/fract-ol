#ifndef FRACTOL_H
# define FRACTOL_H

/* required header files */
# include "mlx.h"
# include "math.h"
# include "stdlib.h"

# define MAX_ITERATION 50
# define THRESHOLD_RADIUS 2.0
# define SCREEN_TITLE_JULIA "Julia set"
# define SCREEN_TITLE_MANDELBROT "Mandelbrot set"
# define BLUE 0x000000FF

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_screen
{
	void	*mlx_win;
	int		width;
	int		height;
	char	*title;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_screen;

typedef struct s_fractol
{
	char		type;
	void		*mlx;
	t_screen	screen;
}	t_fractol;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

/* draw_julia.c */
void		ft_draw_julia(t_fractol fractol, t_complex c);

/* util_complex.c */
t_complex	ft_square_complex(t_complex z);
t_complex	ft_add_complex(t_complex z, t_complex c);
double		ft_get_modulus(t_complex z);

/* util_mlx.c */
void		ft_mlx_pixel_put_screen(t_screen *screen, int x, int y, int color);

/* draw_mandelbrot.c */
void		ft_draw_mandelbrot(t_fractol fractal);

#endif
