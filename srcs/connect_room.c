/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:07:28 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 02:07:29 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	build_connection(t_graph **graph, t_list_room *tmp,
t_list_room **lst_room, t_connect_room *r)
{
	char	**room;
	int		nbr_connec;
	int		j;

	nbr_connec = 0;
	j = -1;
	((*graph)[r->pos_graph]).name = tmp->name;
	((*graph)[r->pos_graph]).start_end = tmp->start_end;
	if (tmp->start_end == 1 || tmp->start_end == 2)
		((*graph)[r->pos_graph]).laps = (tmp->start_end == 1) ? 1 : 0;
	else
		((*graph)[r->pos_graph]).laps = -1;
	room = ft_strsplit(tmp->connection, ' ');
	while (room && room[nbr_connec])
		nbr_connec++;
	((*graph)[r->pos_graph]).next = (t_graph**)malloc(sizeof(t_graph*)
	* (nbr_connec + 1));
	while (++j < nbr_connec)
	{
		(((*graph)[r->pos_graph]).next)[j] =
		&((*graph)[ft_find_address(room[j], lst_room)]);
	}
	((*graph)[r->pos_graph]).nbr_connection = nbr_connec;
	(((*graph)[r->pos_graph]).next)[j] = &((*graph)[r->pos_graph]);
	free_tab_str(room);
}

int			connect_room(t_graph **graph, t_list_room **room)
{
	t_list_room		*tmp;
	t_connect_room	r;

	put_start_in_first_position(room);
	put_end_in_secon_position(room);
	tmp = *room;
	r.limit_graph = 0;
	r.pos_graph = 0;
	while (tmp)
	{
		r.limit_graph++;
		tmp->pos_graph = r.limit_graph;
		tmp = tmp->next;
	}
	*graph = (t_graph *)malloc(sizeof(t_graph) * (r.limit_graph + 1));
	tmp = *room;
	ft_bzero(&((*graph)[r.limit_graph]), sizeof(t_graph));
	while (r.pos_graph < r.limit_graph)
	{
		build_connection(graph, tmp, room, &r);
		((*graph)[r.pos_graph]).pos_graph = r.pos_graph;
		tmp = tmp->next;
		r.pos_graph++;
	}
	return (1);
}
