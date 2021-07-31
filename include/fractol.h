#ifndef FRACTOL_H
# define FRACTOL_H

/* required header files */
# include "mlx.h"
# include "math.h"
# include "stdlib.h"

# define MAX_ITERATION 50
# define THRESHOLD_RADIUS 2.0

typedef struct s_screen
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_screen;

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#endif
