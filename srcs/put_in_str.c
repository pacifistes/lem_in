/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:32:53 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 04:32:56 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	str_add_laps(t_graph **graph, t_way *w, t_bonus *b, t_algo *a)
{
	int		i;
	int		j;
	char	*tmp_col;
	char	*tmp_way;

	i = -1;
	j = 0;
	while (++i < w->ant)
		if (w->pos_ant[i] >= 1)
		{
			(j != 0) ? buff_join(a->str, " ", &a->buff) : (void)i;
			tmp_way = ft_itoll(i + 1);
			tmp_col = ft_itoll(196 + (w->col_ant[i] % 6) * 6);
			(b->color == 1) ? buff_join_nstr(a->str, (char**)(char*[]){
			"\e[38;5;", tmp_col, "mL",
			tmp_way, "-", ((*graph)[w->pos_ant[i]]).name, "\e[0;0m"},
			&a->buff, 7) : buff_join_nstr(a->str, (char**)(char*[]){"L",
			tmp_way, "-", ((*graph)[w->pos_ant[i]]).name}, &a->buff, 4);
			j++;
			if (w->pos_ant[i] == 1)
				w->pos_ant[i] = -1;
			free(tmp_way);
			free(tmp_col);
		}
	buff_join_nstr(a->str, (char**)(char*[]){"\n"}, &a->buff, 1);
}

void	insert_str(t_graph **graph, t_way *w, t_bonus *b, t_algo *a)
{
	int min;
	int compteur;

	min = a->size_room[0];
	w->begin = 0;
	w->end = 0;
	while (w->laps > 0)
	{
		compteur = check_compteur(w->laps, a->size_room);
		incremante_ant(graph, w, compteur);
		str_add_laps(graph, w, b, a);
		w->laps = w->laps - 1;
	}
}

void	end_laps(t_graph **graph, t_way *w, t_bonus *b, t_algo *a)
{
	t_index	index;

	a->size_room = (int*)malloc(sizeof(int) * (a->nbr_choose_way + 1));
	index.j = 0;
	index.i = 0;
	while (w->room[index.j] != -1)
	{
		if (w->room[index.j] == 1)
		{
			a->size_room[index.i] = size_way(w->way[index.j]);
			index.i++;
		}
		index.j++;
	}
	a->size_room[index.i] = -1;
	order_tab(&a->size_room);
	w->pos_ant = (int *)malloc(sizeof(int) * w->ant + 1);
	w->col_ant = (int *)malloc(sizeof(int) * w->ant + 1);
	index.i = -1;
	while (++index.i < w->ant)
		w->pos_ant[index.i] = 0;
	w->pos_ant[index.i] = -1;
	insert_str(graph, w, b, a);
}

void	put_in_str(t_graph **graph, t_way *w, t_bonus *b)
{
	t_algo	a;
	char	*tmp;

	a.i = -1;
	a.nbr_choose_way = 0;
	a.laps = w->laps;
	a.buff = 0;
	print_information(graph, w, b, &a);
	while (w->room[++a.i] != -1)
		if (w->room[a.i] == 1)
			a.nbr_choose_way++;
	(b->hide_algo != 1) ? color_algo(a.str, &a.buff, b, 0) : (void)tmp;
	(b->hide_algo != 1) ? end_laps(graph, w, b, &a) : (void)tmp;
	if (b->laps)
	{
		tmp = ft_itoll(a.laps);
		(b->color == 1) ? buff_join_nstr(a.str, (char**)(char*[])
		{"\e[38;5;5m\n", "Nombre de coups : ", tmp, "\n\e[0;0m"},
		&a.buff, 4) : buff_join_nstr(a.str, (char**)(char*[])
		{"\nNombre de coups : ", tmp, "\n"}, &a.buff, 3);
		free(tmp);
	}
	if (a.buff > 0)
		write(1, a.str, a.buff);
}
