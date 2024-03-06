/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 00:30:47 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/22 17:20:02 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr_cpy;
	size_t	i;

	i = 0;
	arr_cpy = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!arr_cpy)
		return (NULL);
	while (*s != '\0')
		arr_cpy[i++] = *s++;
	arr_cpy[i] = '\0';
	return (arr_cpy);
}
