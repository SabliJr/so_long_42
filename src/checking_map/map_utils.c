/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:19 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/18 10:21:59 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	*ft_strdup(char *s)
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

void	ft_free(char **arr)
{
	size_t	k;

	k = 0;
	while (arr[k] != NULL)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
	arr = NULL;
	return ;
}
