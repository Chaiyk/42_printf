/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychai <ychai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:26:32 by ychai             #+#    #+#             */
/*   Updated: 2024/04/30 14:54:15 by ychai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *c)
{
	int	i;

	i = 0;
	if (c)
	{
		while (c[i])
		{
			i += ft_putchar_fd(c[i]);
		}
	}
	else
		i += ft_putstr_fd("(null)");
	return (i);
}
