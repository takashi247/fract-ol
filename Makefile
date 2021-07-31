NAME		:= fractol

CC			:= gcc

CFLAGS		:= -Wall -Wextra -Werror

SRCS		:= fractol.c

SRCSDIR		:= ./srcs/

SRCS		:= $(addprefix $(SRCSDIR), $(SRCS))

OBJS		:= $(SRCS:.c=.o)

MLXDIR		:= ./mlx/
MLXGITPATH	:= https://github.com/42Paris/minilibx-linux.git

LIBDIR		:= ./libft/
LIBPATH		:= $(LIBDIR)libft.a

ifeq ($(shell uname),Linux)
INCLUDE		:= -I$(MLXDIR) -I./include -I$(LIBDIR)

LIBRARY		:= -L$(MLXDIR) -lmlx_linux -lXext -lX11 -lm -lz -L$(LIBDIR) -lft
else
INCLUDE		:= -I$(MLXDIR) -I/usr/X11/include -I/usr/X11R6/include -I./include -I$(LIBDIR)

LIBRARY		:= -L/usr/X11R6/lib -L$(MLXDIR) -lmlx -lX11 -lXext -L$(LIBDIR) -lft -framework OpenGL -framework AppKit
endif

RM			:= rm -f

all:		mlx_clone $(NAME)

$(NAME):	$(OBJS) $(LIBPATH)
	$(CC) $(CFLAGS) $(INCLUDE) $^ $(LIBRARY) -o $@

$(LIBPATH):
	$(MAKE) plus -C $(LIBDIR)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

mlx_clone:
	if [ ! -d "$(MLXDIR)" ]; then \
		git clone $(MLXGITPATH) $(MLXDIR); \
		$(MAKE) -C mlx/; \
	fi;

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(LIBDIR)

mlx_clean:
	$(RM) -r $(MLXDIR)

fclean:		clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBDIR)

re:			fclean all

.PHONY:		all clean fclean re mlx_clone mlx_clean