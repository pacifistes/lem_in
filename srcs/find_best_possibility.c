/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_possibility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 20:49:44 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/11 20:49:47 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	register_possibility(t_graph **graph, int a, t_way *w, int *h)
{
	int i;

	i = 0;
	if (((*graph)[a]).pos_graph == 0)
	{
		w->room[((*graph)[a]).laps - 1] = ((*graph)[a]).pos_graph;
		complete_way(w, h);
		*h = *h + 1;
		return ;
	}
	if (((*graph)[a]).laps == -1)
		return ;
	w->room[((*graph)[a]).laps - 1] = ((*graph)[a]).pos_graph;
	while (i < ((*graph)[a]).nbr_connection)
	{
		if ((((*graph)[a]).next[i])->laps == ((*graph)[a]).laps - 1)
		{
			register_possibility(graph, (((*graph)[a]).next[i])->pos_graph,
			w, h);
		}
		i++;
	}
}

/*
**	p.nbr_way : nombre de chemin total
**	p.nbr_possibility :  nombre de chemin possible a partir des differentes
**	salle relier a la salle end.
**	way_possible[] : recupere chaque p.nbr_possibility
*/

static void	find_way_possible(t_graph **graph, t_possible *p,
int way_possible[])
{
	while (p->index.i < ((*graph)[1]).nbr_connection)
	{
		p->nbr_possibility = 0;
		p->index.j = 0;
		find_nbr_way(graph, (((*graph)[1]).next[p->index.i])->pos_graph,
		&p->nbr_way);
		p->index.j = p->index.i;
		p->nbr_possibility = p->nbr_way;
		while (p->index.j > 0)
		{
			p->nbr_possibility = p->nbr_possibility -
			way_possible[p->index.j - 1];
			p->index.j--;
		}
		way_possible[p->index.i] = p->nbr_possibility;
		p->index.i++;
	}
}

static void	register_all_way(t_graph **graph, t_way *w, t_possible *p,
int way_possible[])
{
	while (p->index.i < ((*graph)[1]).nbr_connection)
	{
		p->index.j = 0;
		w->room = (int*)malloc(sizeof(int) *
		((((*graph)[1]).next[p->index.i])->laps + 1));
		while (p->index.j < way_possible[p->index.i])
		{
			w->way[p->h] = (int*)malloc(sizeof(int) *
			((((*graph)[1]).next[p->index.i])->laps + 1));
			w->way[p->h][(((*graph)[1]).next[p->index.i])->laps] = -1;
			w->size = (((*graph)[1]).next[p->index.i])->laps;
			p->index.j++;
			p->h++;
		}
		p->nbr_possibility = p->h - p->index.j;
		register_possibility(graph, (((*graph)[1]).next[p->index.i])->pos_graph,
		w, &p->nbr_possibility);
		free(w->room);
		p->index.i++;
	}
}

static void	init_room_and_laps(t_way *w, t_possible *p)
{
	p->index.i = 0;
	while (p->index.i < p->nbr_way)
	{
		w->room[p->index.i] = 0;
		w->tmp_room[p->index.i] = 0;
		p->index.i++;
	}
	w->room[p->index.i] = -1;
	w->tmp_room[p->index.i] = -1;
	w->laps = 0;
}

void		find_best_possibility(t_graph **graph, t_way *w,
t_bonus *b)
{
	t_possible	p;
	int			way_possible[((*graph)[1]).nbr_connection];

	p.index.i = 0;
	p.nbr_way = 0;
	find_way_possible(graph, &p, way_possible);
	w->way = (int**)malloc(sizeof(int*) * p.nbr_way + 1);
	p.index.i = 0;
	w->way[p.nbr_way] = 0;
	p.h = 0;
	register_all_way(graph, w, &p, way_possible);
	w->room = (int*)malloc(sizeof(int) * (p.nbr_way + 1));
	w->tmp_room = (int*)malloc(sizeof(int) * (p.nbr_way + 1));
	init_room_and_laps(w, &p);
	choose_ways(w, 1, p.nbr_way);
	p.index.i = 0;
	w->size = 0;
	while (p.index.i < p.nbr_way)
	{
		if (w->room[p.index.i] == 1)
			w->size++;
		p.index.i++;
	}
	put_in_str(graph, w, b);
}
