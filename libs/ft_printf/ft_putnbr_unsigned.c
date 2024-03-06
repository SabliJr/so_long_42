/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:23:26 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/29 14:18:48 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putc(char c, int *len);

void	ft_putnbr_unsigned(unsigned int nb, int *len)
{
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10, len);
	ft_putc((nb % 10) + '0', len);
}

static void	ft_putc(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
