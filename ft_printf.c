/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychai <ychai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:21:13 by ychai             #+#    #+#             */
/*   Updated: 2024/06/12 12:10:51 by ychai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arr;
	int		i;
	int		len;

	va_start(arr, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_convertion(str[i], arr);
		}
		else
		{
			len += ft_putchar_fd(str[i]);
		}
		i++;
	}
	va_end(arr);
	return (len);
}

int	ft_convertion(char c, va_list array)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar_fd(va_arg(array, int));
	else if (c == 's')
		len = ft_putstr_fd(va_arg(array, char *));
	else if (c == 'p')
		len = ft_pointer(va_arg(array, unsigned long long int));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_fd(va_arg(array, int));
	else if (c == 'u')
		len = ft_unsigned_fd(va_arg(array, unsigned int));
	else if (c == 'x')
		len = ft_hexanbrlow_fd(va_arg(array, unsigned int));
	else if (c == 'X')
		len = ft_hexanbrup_fd(va_arg(array, unsigned int));
	else if (c == '%')
		len = ft_putchar_fd('%');
	else
		return (0);
	return (len);
}
/*
int	main(void)
{
	int		i;
	int		rtn;
	char	*str;

	i = 0;
	rtn = 0;

	printf("\n-----\nChar (%%c)\n-----\n");
	while (i < 177)
	{
		rtn = ft_printf("Own: %c", i);
		printf(" (Rtn: %d) | ", rtn);
		rtn = printf("Ori: %c", i);
		printf(" (Rtn: %d)\n", rtn);
		i++;
	}
	

	printf("\n-----\nStr (%%s)\n-----\n");

	str = "Hello World!";
	rtn = ft_printf("Own: %s", str);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %s", str);
	printf(" (Rtn: %d)\n", rtn);


	str = "                             What is this?!?!";
	rtn = ft_printf("Own: %s", str);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %s", str);
	printf(" (Rtn: %d)\n", rtn);

	str = NULL;
	rtn = ft_printf("Own: NULL %s NULL", str);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: NULL %s NULL", str);
	printf(" (Rtn: %d)\n", rtn);


	printf("\n-----\nThe Void * (%%p)\n-----\n");

	int			void_test;
	static int	void_test2;
	
	rtn = ft_printf("Own: %p", &void_test);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %p", &void_test);
	printf(" (Rtn: %d)\n", rtn);

	rtn = ft_printf("Own: %p", &void_test2);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %p", &void_test2);
	printf(" (Rtn: %d)\n", rtn);


	printf("\n-----\nDecimal (%%d)\n-----\n");

	i = 12345;
	rtn = ft_printf("Own: %d", i);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %d", i);
	printf(" (Rtn: %d)\n", rtn);

	i = -12345;
	rtn = ft_printf("Own: %d", i);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %d", i);
	printf(" (Rtn: %d)\n", rtn);

	i = -0x80000000;
	rtn = ft_printf("Own: %d", i);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %d", i);
	printf(" (Rtn: %d)\n", rtn);

	i = 42;
	rtn = ft_printf("Own: %d", i);
	printf(" (Rtn: %d) | ", rtn);
	rtn = printf("Ori: %d", i);
	printf(" (Rtn: %d)\n", rtn);


	printf("\n-----\nInteger (%%i)\n-----\n");
	i = 12345;
	rtn = ft_printf("Own: %i", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %i", i);
	printf(" (Rtn: %i)\n", rtn);

	i = -12345;
	rtn = ft_printf("Own: %i", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %i", i);
	printf(" (Rtn: %i)\n", rtn);

	i = -0x80000000;
	rtn = ft_printf("Own: %i", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %i", i);
	printf(" (Rtn: %i)\n", rtn);


	printf("\n-----\nUnsigned (%%u)\n-----\n");
	i = 0xFFFFFFFF;
	rtn = ft_printf("Own: %u", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %u", i);
	printf(" (Rtn: %i)\n", rtn);

	i = 0xFFFFFFFF + 1;
	rtn = ft_printf("Own: %u", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %u", i);
	printf(" (Rtn: %i)\n", rtn);

	i = -5;
	rtn = ft_printf("Own: %u", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %u", i);
	printf(" (Rtn: %i)\n", rtn);


	printf("\n-----\nLower Case Hexa (%%x)\n-----\n");
	i = 2147483647;
	rtn = ft_printf("Own: %x", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %x", i);
	printf(" (Rtn: %i)\n", rtn);

	i = 2050705070;
	rtn = ft_printf("Own: %x", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %x", i);
	printf(" (Rtn: %i)\n", rtn);

	i = -1;
	rtn = ft_printf("Own: %x", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %x", i);
	printf(" (Rtn: %i)\n", rtn);


	printf("\n-----\nUpper Case Hexa (%%X)\n-----\n");
	i = 2147483647;
	rtn = ft_printf("Own: %X", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %X", i);
	printf(" (Rtn: %i)\n", rtn);

	i = 2050705070;
	rtn = ft_printf("Own: %X", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %X", i);
	printf(" (Rtn: %i)\n", rtn);

	i = -1;
	rtn = ft_printf("Own: %X", i);
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %X", i);
	printf(" (Rtn: %i)\n", rtn);


	printf("\n-----\nPercent (%%%%)\n-----\n");
	rtn = ft_printf("Own: %%");
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %%");
	printf(" (Rtn: %i)\n", rtn);

	rtn = ft_printf("Own: %%%%");
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %%%%");
	printf(" (Rtn: %i)\n", rtn);

	rtn = ft_printf("Own: %%%%%%%%");
	printf(" (Rtn: %i) | ", rtn);
	rtn = printf("Ori: %%%%%%%%");
	printf(" (Rtn: %i)\n", rtn);
}
*/
