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

/* X11 masks */

# define KEY_PRESS_MASK 1L << 0
# define KEY_RELEASE_MASK 1L << 1
# define BUTTON_PRESS_MASK 1L << 2
# define BUTTON_RELEASE_MASK 1L << 3
# define POINTER_MOTION_MASK 1L << 6
# define STRUCTURE_NOTIFY_MASK 1L << 17

/*
** Keyboard LETTERS
*/

# define K_A 0x61
# define K_D 0x64
# define K_S 0x73
# define K_W 0x77

/*
** Keyboard ARROWS and ESC
*/

# define K_AR_U 0xff52
# define K_AR_D 0xff54
# define K_AR_L 0xff51
# define K_AR_R 0xff53
# define K_ESC 0xff1b

/*
** X11 events
** CLIENT_MESSAGE is used for
*/

typedef enum e_events
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	BUTTON_PRESS = 4,
	BUTTON_RELEASE = 5,
	MOTION_NOTIFY = 6,
	CLIENT_MESSAGE = 33
}	t_events;

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
int			ft_close_fractol(t_fractol *fractol);
int			ft_key_press(int key, t_fractol *fractol);

/* draw_mandelbrot.c */
void		ft_draw_mandelbrot(t_fractol fractal);

#endif
