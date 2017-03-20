/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 02:42:10 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 02:42:12 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	free_room_and_return(char **room, int i)
{
	free_tab_str(room);
	return (i);
}

static int	check_connections(t_list_room **s, t_parse_map *p,
t_check_connection *c, t_bonus *b)
{
	c->index.i = 0;
	c->index.j = 0;
	if (!(p->line) || (p->line && p->line[0] == '\0'))
		return (1);
	c->index.j = ft_strlen_char(p->line, '-');
	if (c->index.j > 1)
		return (1);
	c->room = ft_strsplit(p->line, '-');
	while (c->room && c->room[c->index.i])
		c->index.i++;
	if (c->index.i == 2 && c->room[0][0] != '#')
	{
		if (!lst_add_connection(s, c->room[0], c->room[1]))
			return (free_room_and_return(c->room, 1));
	}
	else if (c->index.i >= 1 && c->room[0][0] == '#' &&
	ft_strcmp("##start", c->room[0]) && ft_strcmp("##end", c->room[0]))
		(void)c->index.i;
	else
		return (free_room_and_return(c->room, 1));
	(c->room[0][0] == '#') ? color_map(&p->final_str, p->line, b, 1) :
	color_map(&p->final_str, p->line, b, 4);
	free_tab_str(c->room);
	return (0);
}

int			check_connection(t_list_room **s, t_parse_map *p, t_bonus *b)
{
	t_check_connection c;

	c.index.j = ft_strlen_char(p->line, '-');
	if (c.index.j > 1 || c.index.j == 0)
		return (0);
	c.index.i = 0;
	c.room = ft_strsplit(p->line, '-');
	while (c.room && c.room[c.index.i])
		c.index.i++;
	if (c.index.i == 2)
	{
		if (lst_add_connection(s, c.room[0], c.room[1]))
			color_map(&p->final_str, p->line, b, 4);
		else
			return (free_room_and_return(c.room, 0));
	}
	else
		return (free_room_and_return(c.room, 0));
	free_tab_str(c.room);
	while (get_next_line(0, &p->line) > 0 && !check_connections(s, p,
	&c, b))
		(void)c;
	return (1);
}
