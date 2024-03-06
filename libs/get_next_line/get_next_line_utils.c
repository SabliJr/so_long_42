/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:09:39 by sabakar-          #+#    #+#             */
/*   Updated: 2023/12/11 12:56:25 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	if (!str)
		return (0);
	while (str[x])
		x++;
	return (x);
}

char	*ft_strchr(char *str, int c)
{
	int	p;

	p = 0;
	if (!str)
		return (0);
	while (str[p])
	{
		if (str[p] == (unsigned char)c)
			return ((char *)&str[p]);
		p++;
	}
	if ((unsigned char)c == 0)
		return ((char *)&str[p]);
	else
		return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_arr;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	new_arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
			+ 1);
	if (!new_arr)
		return (NULL);
	while (s1[++i])
		new_arr[i] = s1[i];
	while (s2[j])
		new_arr[i++] = s2[j++];
	new_arr[i] = '\0';
	return (free(s1), new_arr);
}
