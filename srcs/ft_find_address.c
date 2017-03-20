/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:12:30 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/01 16:12:37 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_find_address(char *str, t_list_room **s)
{
	t_list_room *tmp;

	tmp = *s;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str))
			return (tmp->pos_graph - 1);
		tmp = tmp->next;
	}
	return (0);
}
