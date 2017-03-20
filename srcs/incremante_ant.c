/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incremante_ant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:46:12 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 04:46:13 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_the_way(t_graph **graph, t_way *w, int pos)
{
	int i;
	int j;
	int size_room;

	i = 0;
	while (w->room[i] != -1)
	{
		if (w->room[i] == 1)
		{
			size_room = size_way(w->way[i]);
			j = 0;
			while (j < size_room)
			{
				if (!ft_strcmp(((*graph)[w->pos_ant[pos]]).name,
				((*graph)[w->way[i][j]]).name))
				{
					w->col_ant[pos] = i;
					return ((j == size_room - 1) ? 1 : w->way[i][j + 1]);
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}

static int	find_the_way_second(t_way *w, int pos, int i, int j)
{
	int *size_room;
	int *way;
	int tmp;
	int tmp2;

	size_room = (int*)malloc(sizeof(int) * (w->size + 1));
	way = (int*)malloc(sizeof(int) * (w->size + 1));
	while (w->room[++j] != -1)
	{
		if (w->room[j] == 1)
		{
			size_room[i] = size_way(w->way[j]);
			way[i] = j;
			i++;
		}
	}
	size_room[i] = -1;
	way[i] = -1;
	order_way(&size_room, &way);
	tmp = way[pos];
	tmp2 = size_room[pos];
	free(size_room);
	free(way);
	w->col_ant[w->end] = tmp;
	return ((tmp2 > 1) ? w->way[tmp][1] : 1);
}

void		incremante_ant(t_graph **graph, t_way *w, int compteur)
{
	int i;
	int n;

	i = w->end - 1;
	n = 0;
	while (w->end < w->ant && compteur > n)
	{
		w->pos_ant[w->end] = find_the_way_second(w, n, 0, -1);
		n++;
		w->end++;
	}
	while (i >= 0 && w->pos_ant[i] != 0)
	{
		if (w->pos_ant[i] != -1)
			w->pos_ant[i] = find_the_way(graph, w, i);
		i--;
	}
	w->begin = i + 1;
}
