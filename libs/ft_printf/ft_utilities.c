/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:19:01 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/29 14:03:24 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_cnt_char(char c, int *len);

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putpercentage(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putstr(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (i);
}

void	ft_putnbr(int n, int *len)
{
	unsigned int	nbr;

	if (n < 0)
	{
		put_cnt_char('-', len);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr > 9)
		ft_putnbr(nbr / 10, len);
	put_cnt_char((nbr % 10) + '0', len);
}

static void	put_cnt_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
