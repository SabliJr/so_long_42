/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:17:19 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/29 14:16:35 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...);
int	ft_formates(va_list args, const char formate);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		length;
	int		i;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_formates(args, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}

int	ft_formates(va_list args, const char formate)
{
	int	length;
	int	len;

	length = 0;
	len = 0;
	if (formate == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (formate == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (formate == 'p')
		length += ft_putptr(va_arg(args, unsigned long long));
	else if (formate == 'd' || formate == 'i')
		(ft_putnbr(va_arg(args, int), &len), length += len);
	else if (formate == 'u')
		(ft_putnbr_unsigned(va_arg(args, unsigned int), &len), length += len);
	else if (formate == 'x' || formate == 'X')
		length += ft_puthex(va_arg(args, unsigned int), formate);
	else if (formate == '%')
		length += ft_putpercentage();
	return (length);
}
