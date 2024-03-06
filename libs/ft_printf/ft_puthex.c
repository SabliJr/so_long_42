/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:11:32 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/29 15:41:26 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int num);
static void	ft_printchar(char c);
static void	ft_printhex(unsigned int nb, const char f);

static int	hex_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static void	ft_printhex(unsigned int nb, const char f)
{
	char	*str;

	if (f == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	if (nb >= 16 && nb != 0)
		ft_printhex(nb / 16, f);
	ft_printchar(str[nb % 16]);
}

int	ft_puthex(unsigned int nb, const char formate)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		ft_printhex(nb, formate);
	return (hex_len(nb));
}

static void	ft_printchar(char c)
{
	write(1, &c, 1);
}
