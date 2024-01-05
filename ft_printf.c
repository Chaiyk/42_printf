#include <stdarg.h>
#include "ft_printf.h"

void	ft_conversion(char chr, va_list arr)
{

	if(chr == 'c')
	{
		ft_putchar_fd(va_arg(arr, int), 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	arr;
	int		count;
	
	count = 0;
	va_start(arr, str);

	while(str[count])
	{
		if(str[count] == '%')
		{
			ft_conversion(str[count + 1], arr);
			count++;
		}
		else
			ft_putchar_fd(str[count], 1);
		count++;
	}
	va_end(arr);
	return (count);
}

#include <stdio.h>

int main(void)
{

    printf("\n--Character--\n");
    printf("\n--Small Letter--\n");
	for(int chr = 'a'; chr <= 'z'; chr++)
	{
    printf("Char: %c | Ori: %c | ", chr, chr);
    ft_printf("Own: %c\n", chr);
	}
    printf("\n--Big Letter--\n");
	for(int chr = 'A'; chr <= 'Z'; chr++)
	{
    printf("Char: %c | Ori: %c | ", chr, chr);
    ft_printf("Own: %c\n", chr);
	}
}
