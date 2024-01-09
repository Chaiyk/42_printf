#include "ft_printf.h"

int	ft_unsigned_fd(unsigned int n, int fd)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_unsigned_fd(n / 10, fd);
		n %= 10;
	}
	if (n < 10)
	{
		i++;
		ft_putchar_fd(n + 48, fd);
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned int	i;

	i = 4294967295;
	ft_PutUnsignedNbr_fd(i, 1);
	printf("\n");

	i = 0xFFFFFFFF;
	ft_PutUnsignedNbr_fd(i, 1);
}
*/
