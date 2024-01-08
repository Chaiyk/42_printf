#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_gethexnum(int n)
{
	char *hex_num;

	hex_num = "123456789ABCDEF";

	return (hex_num[n]);
	
}

char	*ft_pointer(int c)
{
	char *ret;

	ret = (char *)malloc(sizeof(int));
	ret = ft_gethexnum(c % 16);
}

int	main(void)
{
	int i;

	i = 91;

	printf("Return: %s\n", ft_pointer(i));
}
