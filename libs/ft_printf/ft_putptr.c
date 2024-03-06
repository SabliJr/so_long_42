/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:18:53 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/29 15:27:17 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptrlen(unsigned long long ptr);
static void	printc(char c);
static void	ft_printptr(uintptr_t ptr);

int	ft_putptr(unsigned long long ptr)
{
	int	ptr_len;

	ptr_len = 1;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	if (ptr == 0)
		write(1, "0", 1);
	else
	{
		ft_printptr(ptr);
		ptr_len += ft_ptrlen(ptr);
	}
	return (ptr_len);
}

static int	ft_ptrlen(unsigned long long ptr)
{
	int	len;

	len = 1;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

static void	ft_printptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			printc(ptr + '0');
		else
			printc((ptr - 10) + 'a');
	}
}

static void	printc(char c)
{
	write(1, &c, 1);
}
