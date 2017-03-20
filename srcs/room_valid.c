/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 00:45:57 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 00:46:03 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		room_valid(int i, char **room, t_list_room **s)
{
	if (i == 3 && ft_isnumber(room[1]) && ft_verifint(room[1]) != 2147484848
	&& ft_isnumber(room[2]) && ft_verifint(room[2]) != 2147484848 && room[0][0]
	!= '#' && room[0][0] != 'L' && check_name_and_pos(s, room[0],
	(int *)(int[]){ft_atoi(room[1]), ft_atoi(room[2])}))
		return (1);
	return (0);
}
