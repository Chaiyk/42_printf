#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_conversion(char chr, va_list arr)
{	
	int	i;

	i = 0;
	if(chr == 'c')
		i = ft_putchar_fd(va_arg(arr, int), 1);
	else if (chr == 's')
		i = ft_putstr_fd(va_arg(arr, char *), 1);
	//else if (chr =='p')
	//	i = ft_putchar_fd(va_arg(arr, int), 1);
	else if(chr == 'd' || chr == 'i')
		i = ft_putnbr_fd(va_arg(arr, int), 1);

	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arr;
	int		count;
	int		countb;
	int		count_str;
	
	count = 0;
	countb = 0;
	count_str = 0;
	va_start(arr, str);

	while(str[count + countb])
	{
		if(str[count + countb] == '%')
		{
			count_str = count_str + ft_conversion(str[count + countb + 1], arr);
			countb++;
		}
		else
			ft_putchar_fd(str[count + countb], 1);
		count++;
	}
	count--;
	va_end(arr);
	return (count + count_str);
}

#include <stdio.h>

int main(void)
{
/*
    printf("\n--Character (%%c)--\n");

	for(int chr = 33; chr < 127; chr++)
	{
    	printf(" - Return: %d | ", printf("Ori: %c", chr));
    	printf(" - Return: %d \n", ft_printf("Own: %c", chr));
	}

    printf("\n--String (%%s)--\n");
	char	*str;

	str = "Hello World!?!";
	printf(" - Return: %d\n", prHexadecimal valuesintf("Ori: %s", str));
	printf(" - Return: %d\n\n", ft_printf("Own: %s", str));

	str = "0123456789";
	printf(" - Return: %d\n", printf("Ori: %s", str));
	printf(" - Return: %d\n\n", ft_printf("Own: %s", str));

	str = "What is This???";
	printf(" - Return: %d\n", printf("Ori: %s", str));
	printf(" - Return: %d\n\n", ft_printf("Own: %s", str));


    printf("\n--The Void (%%p)--\n");
	static int a;
	int b;
	int *c;

	printf(" - Return: %d | ", printf("Ori: %p", (void *) &a));
	ft_printf("Own: %p\n", (void *) &a);

	printf(" - Return: %d | ", printf("Ori: %p", (void *) &b));
	ft_printf("Own: %p\n", (void *) &b);

	printf(" - Return: %d | ", printf("Ori: %p", (void *) &c));
	ft_printf("Own: %p\n", (void *) &c);


    printf("\n--Decimal (%%d)--\n");
	int	num1;

	num = 123;
	printf(" - Return: %d | ", printf("Ori: %d", num1));
	printf(" - Return: %d\n\n", ft_printf("Own: %d", num1));

	num1 = -123;
	printf(" - Return: %d | ", printf("Ori: %d", num1));
	printf(" - Return: %d\n\n", ft_printf("Own: %d", num1));

	num1 = -2147483648;
	printf(" - Return: %d | ", printf("Ori: %d", num1));
	printf(" - Return: %d\n\n", ft_printf("Own: %d", num1));

    printf("\n--Integer (%%i)--\n");
	int	num2;
	num2 = 123;
	printf(" - Return: %d | ", printf("Ori: %i", num2));
	printf(" - Return: %d\n\n", ft_printf("Own: %i", num2));

	num2 = -123;
	printf(" - Return: %d | ", printf("Ori: %i", num2));
	printf(" - Return: %d\n\n", ft_printf("Own: %i", num2));

	num2 = -2147483648;
	printf(" - Return: %d | ", printf("Ori: %i", num2));
	printf(" - Return: %d\n\n", ft_printf("Own: %i", num2));
*/
}
