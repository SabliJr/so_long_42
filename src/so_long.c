/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:40:45 by sabakar-          #+#    #+#             */
/*   Updated: 2024/03/13 11:29:26 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./so_long.h"

int main(int argc, char *argv[]) 
{
    t_data data;
    if (argc != 2)
        printf("\e[31mError: please provide a map! \e0\n");

    create_map(&data, argv[1]);
    init_map (&data);
    check_map(&data);
    init_player(&data);
    
}