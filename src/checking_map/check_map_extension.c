/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:47:14 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/12 21:36:01 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int check_extention(char *path)
{
    int fd;
    size_t  len;

    len = ft_strlen(path);
    if (open(path, O_DIRECTOTY) >= 0)
    {
        fd = (open(path, O_DIRECTOTY));
        close(fd);
        return (FAILURE);
    }
    else
    {
        fd = open(path, O_DIRECTOTY);
        close(fd);
        if ((path[len - 1] != 'b' && path[len - 3] != 'e' && path[len - 3] != 'r' 
            && path[len - 4] != '.') || fd < 0)
            return (FAILURE);
        else
            return (SUCCESS);
    }
}