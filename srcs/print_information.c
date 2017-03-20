/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_information.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:53:52 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/13 15:53:54 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_nbr_room(t_graph **graph, t_bonus *b, t_algo *a)
{
	int		i;
	char	*tmp;

	i = 0;
	while (((*graph)[i]).name)
		i++;
	tmp = ft_itoll(i);
	if (b->color == 1)
	{
		buff_join_nstr(a->str, (char**)(char*[]){"\e[36;3m",
		"\nNombre de salles : ", tmp, "\n\e[0;0m"}, &a->buff, 4);
	}
	else
	{
		buff_join_nstr(a->str, (char**)(char*[]){"\nNombre de salles : ",
		tmp, "\n"}, &a->buff, 3);
	}
	free(tmp);
}

void	print_way_find(t_graph **graph, t_way *w, t_bonus *b, t_algo *a)
{
	int		i;
	int		j;
	char	*tmp_col;
	char	*tmp_way;

	color_algo(a->str, &a->buff, b, 2);
	i = -1;
	while (w->way[++i])
	{
		j = -1;
		tmp_col = ft_itoll(196 + (i % 6) * 6);
		tmp_way = ft_itoll(i + 1);
		(b->color == 1) ? buff_join_nstr(a->str, (char**)(char*[]){"\e[38;5;",
		tmp_col, "mchemin ", tmp_way, " : "}, &a->buff, 5) : buff_join_nstr(
		a->str, (char**)(char*[]){"chemin ", tmp_way, " : "}, &a->buff, 3);
		while (w->way[i][++j] != -1)
			buff_join_nstr(a->str, (char**)(char*[]){"[",
			((*graph)[w->way[i][j]]).name, "]"}, &a->buff, 3);
		buff_join_nstr(a->str, (char**)(char*[]){"[", ((*graph)[1]).name,
		"]\n"}, &a->buff, 3);
		if (b->color == 1)
			buff_join_nstr(a->str, (char**)(char*[]){"\e[0;0m"}, &a->buff, 1);
		free(tmp_way);
		free(tmp_col);
	}
}

void	print_name_room(t_graph **graph, t_way *w, t_algo *a, t_index *ind)
{
	ind->j = 0;
	while (w->way[ind->i][ind->j] != -1)
	{
		buff_join_nstr(a->str, (char**)(char*[]){"[",
		((*graph)[w->way[ind->i][ind->j]]).name, "]"}, &a->buff, 3);
		ind->j++;
	}
}

void	print_way_use(t_graph **graph, t_way *w, t_bonus *b, t_algo *a)
{
	t_index	ind;
	int		h;
	char	*tmp_col;
	char	*tmp_way;

	color_algo(a->str, &a->buff, b, 1);
	h = -1;
	while (w->room[++h] != -1)
		if (w->room[h] == 1)
		{
			ind.i = h;
			tmp_col = ft_itoll(196 + (ind.i % 6) * 6);
			tmp_way = ft_itoll(ind.i + 1);
			(b->color == 1) ? buff_join_nstr(a->str, (char**)(char*[]){
			"\e[38;5;", tmp_col, "mchemin ", tmp_way, " : "}, &a->buff, 5) :
			buff_join_nstr(a->str, (char**)(char*[]){"chemin ", tmp_way, " : "},
			&a->buff, 3);
			print_name_room(graph, w, a, &ind);
			buff_join_nstr(a->str, (char**)(char*[]){"[", ((*graph)[1]).name,
			"]\n"}, &a->buff, 3);
			color_algo(a->str, &a->buff, b, 3);
			free(tmp_way);
			free(tmp_col);
		}
}

void	print_information(t_graph **graph, t_way *w, t_bonus *b, t_algo *a)
{
	if (b->nbr_room == 1)
		print_nbr_room(graph, b, a);
	if (b->way_find == 1)
		print_way_find(graph, w, b, a);
	if (b->way_use == 1)
		print_way_use(graph, w, b, a);
}
