#include <unistd.h>

int	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(fd, &c[i], 1);
		i++;
	}
	return (i);
}
