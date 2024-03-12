/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 11:23:24 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/12 10:44:01 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_what_left(char *str)
{
	int		i;
	int		y;
	char	*unread_lines;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
		return (free(str), NULL);
	unread_lines = (char *)malloc((ft_strlen(str) - i + 1) * sizeof(char));
	i++;
	if (!unread_lines)
		return (NULL);
	y = 0;
	while (str[i])
		unread_lines[y++] = str[i++];
	unread_lines[y] = '\0';
	return (free(str), unread_lines);
}

char	*ft_get_line(char *str)
{
	int		f;
	char	*la_line;

	f = 0;
	if (!str[f])
		return (NULL);
	while (str[f] && str[f] != '\n')
		f++;
	la_line = (char *)malloc(sizeof(char) * (f + 2));
	if (!la_line)
		return (NULL);
	f = 0;
	while (str[f] && str[f] != '\n')
	{
		la_line[f] = str[f];
		f++;
	}
	if (str[f] == '\n')
	{
		la_line[f] = str[f];
		f++;
	}
	la_line[f] = '\0';
	return (la_line);
}

char	*ft_read_file(int fd, char *lines)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(lines, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(buff), NULL);
		buff[rd_bytes] = '\0';
		lines = ft_strjoin(lines, buff);
	}
	return (free(buff), lines);
}

char	*get_next_line(int fd)
{
	static char	*lines[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	lines[fd] = ft_read_file(fd, lines[fd]);
	if (!lines[fd])
		return (NULL);
	line = ft_get_line(lines[fd]);
	lines[fd] = ft_get_what_left(lines[fd]);
	return (line);
}

/*
int	main(void)
{
  int f1;
  char *s1;

  f1 = open("./get_next_line.h", O_RDONLY);
  while (1)
  {
	s1 = get_next_line(f1);
	if (!s1)
		break ;
	printf("%s", s1);
  }
  free(s1);
  close(f1);
  return (0);
}
*/