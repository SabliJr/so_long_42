/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:08:56 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/16 14:37:59 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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
