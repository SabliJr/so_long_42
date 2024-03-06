/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:08:53 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/18 14:55:37 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*a;

	a = str;
	while (n-- > 0)
	{
		if (*a == (unsigned char)c)
			return ((void *)a);
		a++;
	}
	return (NULL);
}
