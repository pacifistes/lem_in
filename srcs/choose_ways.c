/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:36:51 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/11 18:36:53 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	best_way(t_way *w, int nbr_way)
{
	t_index index;
	int		laps_max;

	index.i = 0;
	laps_max = 0;
	while (index.i < nbr_way)
	{
		if (w->room[index.i] == 1)
		{
			index.j = 0;
			while (w->way[index.i][index.j] != -1)
				index.j++;
			if (w->way[index.i][index.j] > laps_max)
				laps_max = w->way[index.i][index.j];
		}
		index.i++;
	}
	if (w->laps <= laps_max)
		return (1);
	return (0);
}

static void	change_combi(int *salle_selection, t_index *index)
{
	salle_selection[index->i] = salle_selection[index->i] + 1;
	index->j = index->i - 1;
	while (index->j >= 0 && salle_selection[index->j] ==
	salle_selection[index->j + 1] - 1)
		index->j--;
	if (index->j >= 0)
	{
		salle_selection[index->j] = salle_selection[index->j] + 1;
		index->j--;
		while (++index->j < index->i)
			salle_selection[index->j + 1] = salle_selection[index->j] + 1;
	}
	else
		salle_selection[index->i] = salle_selection[index->i] + 1;
}

void		choose_ways(t_way *w, int g, int nbr_way)
{
	int		salle_selection[g];
	t_index index;

	if (g == nbr_way + 1)
		return ;
	index.i = -1;
	while (++index.i < g)
		salle_selection[index.i] = index.i;
	index.i = g - 1;
	while (salle_selection[index.i] < nbr_way)
	{
		while (salle_selection[index.i] < nbr_way)
		{
			index.j = g;
			while (--index.j >= 0)
				w->tmp_room[salle_selection[index.j]] = 1;
			verif_combi(w, g);
			reset_tab(&(w->tmp_room), nbr_way);
			salle_selection[index.i] = salle_selection[index.i] + 1;
		}
		change_combi(salle_selection, &index);
	}
	if (best_way(w, nbr_way))
		return ;
	choose_ways(w, g + 1, nbr_way);
}
