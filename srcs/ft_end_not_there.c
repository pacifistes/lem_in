/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_not_there.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:14:38 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 04:14:41 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_end_not_there(t_graph **graph, int a)
{
	int i;

	i = 0;
	while (i < ((*graph)[a]).nbr_connection)
	{
		if ((((*graph)[a]).next[i])->start_end == 2)
			return (0);
		i++;
	}
	return (1);
}
