/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name_and_pos.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 00:49:46 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 00:49:48 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_name_and_pos(t_list_room **s, char *str, int *pos)
{
	t_list_room	*tmp;
	int			i;

	tmp = *s;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str) || (tmp->pos[0] == pos[0] &&
		tmp->pos[1] == pos[1]))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
