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

#endif
