/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:33:02 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 04:33:05 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	find_nbr_way(t_graph **graph, int a, int *nbr)
{
	int i;

	i = 0;
	if (((*graph)[a]).pos_graph == 0)
	{
		*nbr = *nbr + 1;
		return ;
	}
	if (((*graph)[a]).laps == -1)
		return ;
	while (i < ((*graph)[a]).nbr_connection)
	{
		if ((((*graph)[a]).next[i])->pos_graph == 0)
			*nbr = *nbr + 1;
		else if ((((*graph)[a]).next[i])->laps == ((*graph)[a]).laps - 1)
			find_nbr_way(graph, (((*graph)[a]).next[i])->pos_graph, nbr);
		i++;
	}
}

void	complete_way(t_way *w, int *h)
{
	int i;

	i = 0;
	while (i < w->size)
	{
		w->way[*h][i] = w->room[i];
		i++;
	}
}

void	order_way(int **tab, int **way)
{
	int i;
	int swap[2];

	i = 0;
	while ((*tab)[i] != -1)
	{
		if ((*tab)[i + 1] != -1 && (*tab)[i] > (*tab)[i + 1])
		{
			swap[0] = (*tab)[i];
			swap[1] = (*way)[i];
			(*tab)[i] = (*tab)[i + 1];
			(*way)[i] = (*way)[i + 1];
			(*tab)[i + 1] = swap[0];
			(*way)[i + 1] = swap[1];
			i = 0;
		}
		i++;
	}
}

int		size_way(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != -1)
		i++;
	return (i);
}

int		cmp_way(t_way *w, int j, int i)
{
	int h;

	h = 1;
	while (w->way[j][h] != -1 && w->way[i][h] != -1)
	{
		if (w->way[j][h] == w->way[i][h])
			return (1);
		h++;
	}
	return (0);
}
