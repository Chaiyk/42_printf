/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychai <ychai@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:24:17 by ychai             #+#    #+#             */
/*   Updated: 2024/04/30 15:54:36 by ychai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_convertion(char c, va_list array);
int	ft_putchar_fd(char c);
int	ft_putstr_fd(char *c);
int	ft_putnbr_fd(int n);
int	ft_pointer(unsigned long long int n);
int	ft_unsigned_fd(unsigned int n);
int	ft_hexanbrlow_fd(unsigned int n);
int	ft_hexanbrup_fd(unsigned int n);

#endif
