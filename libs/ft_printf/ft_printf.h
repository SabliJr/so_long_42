/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:08:56 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/29 15:40:22 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_putpercentage(void);
int		ft_formates(va_list args, const char formate);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(unsigned long long ptr);
int		ft_puthex(unsigned int nb, const char formate);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_unsigned(unsigned int nb, int *len);

#endif
