/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:12:10 by sabakar-          #+#    #+#             */
/*   Updated: 2023/11/18 15:46:53 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	size_t			i;

	i = 0;
	src_len = ft_strlen(src);
	if (!len && !dst)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (len <= dst_len)
		return (len + src_len);
	while (src[i] && ((dst_len + i) < len - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
