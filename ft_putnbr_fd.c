/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychai <ychai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:26:25 by ychai             #+#    #+#             */
/*   Updated: 2024/04/16 18:26:26 by ychai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-21474836478", fd);
		return (11);
	}
	if (n < 0)
	{
		i++;
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n >= 10)
	{
		i += ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	if (n < 10)
	{
		i++;
		ft_putchar_fd(n + 48, fd);
	}
	return (i);
}
