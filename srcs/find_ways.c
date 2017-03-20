/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:14:12 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 04:14:14 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	search_laps(t_graph **graph, int a, int nbr)
{
	int	i;

	i = 0;
	while (i < ((*graph)[a]).nbr_connection)
	{
		if (((nbr < (((*graph)[a]).next[i])->laps
		&& (((*graph)[a]).next[i])->laps != 0)
		|| (((*graph)[a]).next[i])->laps == -1)
		&& (ft_end_not_there(graph, a) || a == 0))
		{
			(((*graph)[a]).next[i])->laps = nbr;
			search_laps(graph, (((*graph)[a]).next[i])->pos_graph, nbr + 1);
		}
		i++;
	}
}

static void	find_number(t_graph **graph, int a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < ((*graph)[a]).nbr_connection)
	{
		if ((((*graph)[a]).next[i])->laps > 0 &&
		((((*graph)[a]).next[i])->laps < j || j == 0))
			j = (((*graph)[a]).next[i])->laps;
		i++;
	}
	((*graph)[a]).laps = (j == 0) ? -1 : j + 1;
}

static void	finish_laps(t_graph **graph, int a)
{
	int i;

	i = 0;
	while (i < ((*graph)[a]).nbr_connection)
	{
		if ((((*graph)[a]).next[i])->laps == -1)
			find_number(graph, (((*graph)[a]).next[i])->pos_graph);
		i++;
	}
}

static int	find_a_way(t_graph **graph)
{
	int i;

	i = 0;
	while (i < ((*graph)[1]).nbr_connection)
	{
		if ((((*graph)[1]).next[i])->laps > 0)
			return (1);
		i++;
	}
	return (0);
}

int			find_ways(t_graph **graph)
{
	search_laps(graph, 0, 2);
	finish_laps(graph, 1);
	if (find_a_way(graph))
		return (1);
	return (0);
}
