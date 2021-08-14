#include "fractol.h"

int
	ft_show_manual(t_fractol *fractol)
{
	int			fd;
	int			len;
	char		buf[BUF_SIZE];

	fd = open(PATH_TO_README, O_RDONLY);
	if (fd < 0)
	{
		perror(PROGRAM_NAME);
		ft_close_fractol(fractol, EXIT_FAILURE);
	}
	while (1)
	{
		len = read(fd, buf, BUF_SIZE);
		if (!len)
			break ;
		write(STDOUT_FILENO, buf, len);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
