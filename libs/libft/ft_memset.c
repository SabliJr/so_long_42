/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:10:13 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/18 15:18:10 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

void	*ft_memset(void *a, int c, size_t len)
{
	unsigned char	*y;

	y = (unsigned char *)a;
	if (len <= 0)
		return (a);
	while (len > 0)
	{
		*y = (unsigned char)c;
		y++;
		len--;
	}
	return (a);
}
