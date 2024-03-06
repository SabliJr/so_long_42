/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:09:56 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/23 11:39:12 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	i = 0;
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	if (dest_cpy > src_cpy)
	{
		while (len-- > 0)
			dest_cpy[len] = src_cpy[len];
	}
	else
	{
		while (i < len)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	return (dest_cpy);
}
