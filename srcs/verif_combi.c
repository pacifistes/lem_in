/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_combi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:02:54 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/11 21:02:56 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	this_is_good_laps(t_way *w, int *size_room)
{
	int	ant;
	int min;
	int compteur;
	int laps;

	min = size_room[0];
	compteur = check_compteur(1 + min - 1, size_room);
	laps = min;
	ant = compteur;
	while (ant < w->ant)
	{
		compteur = check_compteur(laps + 1, size_room);
		laps = laps + 1;
		ant = ant + compteur;
	}
	return (laps);
}

static int	find_laps(t_way *w, int nombre_salle)
{
	int i;
	int j;
	int *size_room;

	size_room = (int*)malloc(sizeof(int) * (nombre_salle + 1));
	j = 0;
	i = 0;
	while (w->tmp_room[j] != -1)
	{
		if (w->tmp_room[j] == 1)
		{
			size_room[i] = size_way(w->way[j]);
			i++;
		}
		j++;
	}
	size_room[i] = -1;
	order_tab(&size_room);
	i = this_is_good_laps(w, size_room);
	free(size_room);
	return (i);
}

static int	single_room(t_way *w, int nombre_salle)
{
	int i;
	int j;
	int salle_selection[nombre_salle];
	int biggest_way;

	i = 0;
	j = 0;
	while (w->tmp_room[i] != -1)
	{
		if (w->tmp_room[i] == 1)
		{
			salle_selection[j] = i;
			j++;
		}
		i++;
	}
	biggest_way = size_way(w->way[salle_selection[0]]);
	i = w->ant + (biggest_way - 1);
	return (i);
}

static int	multi_room(t_way *w, int nombre_salle, int i, int j)
{
	int salle_selection[nombre_salle];

	while (w->tmp_room[i] != -1)
	{
		if (w->tmp_room[i] == 1)
		{
			salle_selection[j] = i;
			j++;
		}
		i++;
	}
	j = 0;
	i = j + 1;
	while (i < nombre_salle)
	{
		while (i < nombre_salle)
		{
			if (cmp_way(w, salle_selection[j], salle_selection[i]))
				return (0);
			i++;
		}
		j++;
		i = j + 1;
	}
	return (find_laps(w, nombre_salle));
}

void		verif_combi(t_way *w, int nombre_salle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (nombre_salle == 1)
		i = single_room(w, nombre_salle);
	else
		i = multi_room(w, nombre_salle, 0, 0);
	if (i > 0 && (i < w->laps || w->laps == 0))
	{
		copy_tab(w);
		w->laps = i;
	}
}
