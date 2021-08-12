#ifndef FRACTOL_H
# define FRACTOL_H

/* required header files */
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include "libft.h"

/* for open */
# include <fcntl.h>

/* for read */
# include <unistd.h>

/* for perror */
# include <stdio.h>

/* program related macro variables */

# define PROGRAM_NAME "fract-ol"

/* screen size */

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800

/* Maximum number of interation for each fractal */

# define MAX_ITER_M 20
# define MAX_ITER_J 100
# define MAX_ITER_B 50

/* Threshold radius for diversion check */

# define THRESHOLD_RADIUS 2.0

/* parameters to display README */

# define PATH_TO_README "./tools/readme.txt"
# define BUF_SIZE 1024

/* initial max/min values for real / imaginary axis */

# define MIN_REAL -2.5
# define MIN_IMAG -2.5
# define MAX_REAL 2.5
# define MAX_IMAG 2.5

/* parameter for mouse wheel zoom-in/out speed */

# define ZOOM_FACTOR 0.9

/* exit status of hook function */

# define HOOK_SUCCESS 0

/*
** X11 masks
** key press: (1L << 0) = 1
** key release: (1L << 1) = 2
** button press: (1L << 2) = 4
** button release: (1L << 3) = 8
** pointer motion: (1L << 6) = 64
** structure notify: (1L << 17) = 131072
** focus change mask: (1L << 21) = 2097152
*/

# define KEY_PRESS_MASK 1
# define KEY_RELEASE_MASK 2
# define BUTTON_PRESS_MASK 4
# define BUTTON_RELEASE_MASK 8
# define POINTER_MOTION_MASK 64
# define STRUCTURE_NOTIFY_MASK 131072
# define FOCUS_CHANGE_MASK 2097152

/*
** Keyboard LETTERS
*/

# define K_C 0x63
# define K_R 0x72
# define K_G 0x67
# define K_B 0x62

/*
** Keyboard ARROWS and ESC
*/

# define K_AR_U 0xff52
# define K_AR_D 0xff54
# define K_AR_L 0xff51
# define K_AR_R 0xff53
# define K_ESC 0xff1b

/*
** mouse buttons
*/

# define MOUSE_ZOOM_OUT 4
# define MOUSE_ZOOM_IN 5

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
	FOCUS_IN = 9,
	CLIENT_MESSAGE = 33
}	t_events;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

/* hue values */

typedef enum e_hue
{
	RED = 0,
	GREEN = 85,
	BLUE = 170
}	t_hue;

typedef struct s_screen
{
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_screen;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

typedef struct s_fractol
{
	char		type;
	t_bool		is_value_shift_mode;
	int			base_hue;
	void		*mlx;
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	t_complex	c;
	t_screen	screen;
}	t_fractol;

/* util_complex.c */
t_complex	ft_square_complex(t_complex z);
t_complex	ft_add_complex(t_complex z, t_complex c);
double		ft_get_modulus(t_complex z);

/* util_mlx.c */
void		ft_mlx_pixel_put_screen(t_screen *screen, int x, int y, int color);
int			ft_close_fractol(t_fractol *fractol);
int			ft_key_press(int key, t_fractol *fractol);
int			ft_create_rgb(int r, int g, int b);
int			ft_put_image_to_window(t_fractol *fractol);

/* draw_fractal.c */
void		ft_draw_fractal(t_fractol fractal);

/* util_color.c */
int			ft_count_iteration(t_complex z, t_complex c, int max_iteration);
int			ft_get_color_h(int num_iteration, int max_iteration);
int			ft_get_color_v(int num_iteration, int base_hue, int max_iteration);
int			ft_count_iteration_b(t_complex z, t_complex c, int max_iteration);

/* zoom.c */
int			ft_zoom_w_mouse(int button, int x, int y, t_fractol *fractol);

/* shift_window.c */
int			ft_shift_window_up(t_fractol *fractol);
int			ft_shift_window_down(t_fractol *fractol);
int			ft_shift_window_right(t_fractol *fractol);
int			ft_shift_window_left(t_fractol *fractol);

/* change_color.c */
int			ft_make_red(t_fractol *fractol);
int			ft_make_green(t_fractol *fractol);
int			ft_make_blue(t_fractol *fractol);
int			ft_change_color_mode(t_fractol *fractol);

#endif
