#include <stdarg.h>
#include "ft_printf.h"
#include <stdio.h>

int	ft_conversion(char chr, va_list arr)
{
	int	i;

	i = 0;
	if (chr == 'c')
		i = ft_putchar_fd(va_arg(arr, int), 1);
	else if (chr == 's')
		i = ft_putstr_fd(va_arg(arr, char *), 1);
	//else if (chr =='p')
	//	i = ft_putchar_fd(va_arg(arr, int), 1);
	else if (chr == 'd' || chr == 'i')
		i = ft_putnbr_fd(va_arg(arr, int), 1);
	else if (chr == 'u')
		i = ft_unsigned_fd(va_arg(arr, int), 1);
	else if (chr == 'x')
		i = ft_hexanbrlow_fd(va_arg(arr, int), 1);
	else if (chr == 'X')
		i = ft_hexanbrup_fd(va_arg(arr, int), 1);
	else if (chr == '%')
		i = ft_putchar_fd('%', 1);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arr;
	int		count;
	int		count_percent;
	int		count_str;

	count = 0;
	count_percent = 0;
	count_str = 0;
	va_start(arr, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			count_str += ft_conversion(str[count + 1], arr);
			count_percent++;
		}
		else
			ft_putchar_fd(str[count], 1);
		count++;
	}
	count -= count_percent;
	va_end(arr);
	return (count + count_str);
}

#include <stdio.h>

int	main(void)
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
	printf(" - Return: %d\n", printf("Ori: %s", str));
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

	num1 = 123;
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


    printf("\n--unsigned (%%i)--\n");
	unsigned int	num3;

	num3 = 4294967295;
	printf(" - Return: %d | ", printf("Ori: %u", num3));
	printf(" - Return: %d\n\n", ft_printf("Own: %u", num3));

	num3 = 0xFFFFFFFF;
	printf(" - Return: %d | ", printf("Ori: %u", num3));
	printf(" - Return: %d\n\n", ft_printf("Own: %u", num3));


    printf("\n--Hexadecimal Lowercase (%%x)--\n");
	int	num4;

	for (num4 = 0; num4 < 21; num4++)
	{
	printf("Number: %d	| ", num4);
	printf(" - Return: %d	| ", printf("Ori: %x", num4));
	printf(" - Return: %d\n", ft_printf("Own: %x", num4));
	}

	num4 = 174;
	printf("Number: %d	| ", num4);
	printf(" - Return: %d	| ", printf("Ori: %x", num4));
	printf(" - Return: %d\n", ft_printf("Own: %x", num4));

	num4 = 2147483647;
	printf("Number: %d	| ", num4);
	printf(" - Return: %d	| ", printf("Ori: %x", num4));
	printf(" - Return: %d\n", ft_printf("Own: %x", num4));


	printf("\n--Hexadecimal Uppercase (%%X)--\n");
	int num5;

	for (num5 = 0; num5 < 21; num5++)
	{
		printf("Number: %d	| ", num5);
		printf(" - Return: %d	| ", printf("Ori: %X", num5));
		printf(" - Return: %d\n", ft_printf("Own: %X", num5));	
	}2147483647

	num5 = 174;
	printf("Number: %d	| ", num5);
	printf(" - Return: %d	| ", printf("Ori: %X", num5));
	printf(" - Return: %d\n", ft_printf("Own: %X", num5));	

	num5 = 2147483647;
	printf("Number: %d	| ", num5);
	printf(" - Return: %d	| ", printf("Ori: %X", num5));
	printf(" - Return: %d\n", ft_printf("Own: %X", num5));
*/

	printf("\n--Percent Sign (%%%%)--\n");
	printf(" - Return: %d | ", printf("Ori: %%"));
	printf(" - Return: %d\n", ft_printf("Own: %%"));

	printf(" - Return: %d | ", printf("Ori: %% %%"));
	printf(" - Return: %d\n", ft_printf("Own: %% %%"));
}
