NAME		:= fractol

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

SRCS		:= draw_fractal.c \
				fractol.c \
				util_complex.c \
				util_mlx.c \
				util_color.c \
				zoom.c \
				shift_window.c \
				change_color.c

SRCSDIR		:= ./srcs/

SRCS		:= $(addprefix $(SRCSDIR), $(SRCS))

OBJS		:= $(SRCS:.c=.o)

MLXDIR		:= ./mlx/
MLXGITPATH	:= https://github.com/42Paris/minilibx-linux.git

LIBDIR		:= ./libft
LIBPATH		:= $(LIBDIR)/libft.a

ifeq ($(shell uname),Linux)
INCLUDE		:= -I$(MLXDIR) -I./include -I./libft/

LIBRARY		:= -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz -L$(LIBDIR) -lft
else
INCLUDE		:= -I$(MLXDIR) -I/usr/X11/include -I/usr/X11R6/include -I./include -I./libft/

LIBRARY		:= -L/usr/X11R6/lib -L$(MLXDIR) -lmlx -lX11 -lXext -L$(LIBDIR) -lft -framework OpenGL -framework AppKit
endif

RM			:= rm -f

# DEBUG 		:=
DEBUG		:= -g

all:		mlx_clone $(NAME)

$(NAME):	$(OBJS) $(LIBPATH)
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) $^ $(LIBRARY) -o $@

.c.o:
	$(CC) $(CFLAGS) $(DEBUG) $(INCLUDE) -c $< -o $@

$(LIBPATH):
	$(MAKE) plus -C $(LIBDIR)

mlx_clone:
	if [ ! -d "$(MLXDIR)" ]; then \
		git clone $(MLXGITPATH) $(MLXDIR); \
	fi; \
	$(MAKE) -C $(MLXDIR);

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBDIR)
	if [ -d "$(MLXDIR)" ]; then \
		$(MAKE) clean -C $(MLXDIR); \
	fi;


mlx_clean:
	$(RM) -r $(MLXDIR)

fclean:		clean
	$(RM) $(NAME)
	if [ -d "$(MLXDIR)" ]; then \
		$(MAKE) fclean -C $(LIBDIR); \
	fi;

re:			fclean all

bonus:		all

.PHONY:		all clean fclean re mlx_clone mlx_clean bonus