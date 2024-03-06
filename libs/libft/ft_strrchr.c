/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:13:20 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/23 13:03:23 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			j = i;
		i++;
	}
	if (str[i] == (char)c)
		j = i;
	if (j != -1)
		return ((char *)str + j);
	return (NULL);
}
