/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 00:43:00 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 00:43:01 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	register_start_or_end(t_list_room **s, t_parse_map *p,
t_check_room *r, t_bonus *b)
{
	while (r->j != -2 && (r->j = get_next_line(0, &p->line)) > 0)
	{
		if (ft_strlen_char(p->line, ' ') != 2 && (p->line)[0] != '#')
			return (0);
		free_tab_str(r->room);
		r->room = ft_strsplit(p->line, ' ');
		r->i = 0;
		while (r->room && r->room[r->i])
			r->i++;
		if (room_valid(r->i, r->room, s))
		{
			lstadd_room(s, r->room[0], (int *)(int[]){ft_atoi(r->room[1]),
			ft_atoi(r->room[2]), r->start_or_end});
			r->j = -2;
		}
		else if (r->i >= 1 && r->room[0][0] == '#' &&
		((r->start_or_end == 2 && ft_strcmp("##start", r->room[0])) ||
		(r->start_or_end == 1 && ft_strcmp("##end", r->room[0]))))
			(void)r->i;
		else
			return (0);
		(r->j == -2) ? color_map(&p->final_str, p->line, b, 2) :
		color_map(&p->final_str, p->line, b, 1);
	}
	return ((r->j == 0) ? 0 : 1);
}

static int	regist_start(t_list_room **s, t_parse_map *p, t_check_room *r,
t_bonus *b)
{
	if (r->start == 0)
	{
		color_map(&p->final_str, p->line, b, 3);
		r->start_or_end = 1;
		r->j = 0;
		if (!register_start_or_end(s, p, r, b))
		{
			free_tab_str(r->room);
			return (0);
		}
		r->start = 1;
	}
	else
		return (0);
	return (1);
}

static int	regist_end(t_list_room **s, t_parse_map *p, t_check_room *r,
t_bonus *b)
{
	if (r->end == 0)
	{
		color_map(&p->final_str, p->line, b, 3);
		r->start_or_end = 2;
		r->j = 0;
		if (!register_start_or_end(s, p, r, b))
		{
			free_tab_str(r->room);
			return (0);
		}
		r->end = 1;
	}
	else
		return (0);
	return (1);
}

static int	verif_room(t_list_room **s, t_parse_map *p, t_check_room *r,
t_bonus *b)
{
	while (r->room && r->room[r->i])
		r->i++;
	if (r->i == 1 && !ft_strcmp("##start", r->room[0]))
		return (regist_start(s, p, r, b));
	else if (r->i == 1 && !ft_strcmp("##end", r->room[0]))
		return (regist_end(s, p, r, b));
	else if (ft_strlen_char(p->line, ' ') != 2 && (p->line)[0] != '#' &&
	(r->start != 1 || r->end != 1))
	{
		free_tab_str(r->room);
		return (0);
	}
	else if (room_valid(r->i, r->room, s))
	{
		lstadd_room(s, r->room[0], (int *)(int[]){ft_atoi(r->room[1]),
		ft_atoi(r->room[2]), 0});
		color_map(&p->final_str, p->line, b, 2);
	}
	else if (r->i >= 1 && r->room[0][0] == '#')
		color_map(&p->final_str, p->line, b, 1);
	else if (r->start == 1 && r->end == 1)
		return (error_free_tab(r->room, 2));
	else
		return (error_free_tab(r->room, 0));
	return (1);
}

int			check_room(t_list_room **s, t_parse_map *p, t_bonus *b)
{
	t_check_room	r;
	int				checker;

	r.start = 0;
	r.end = 0;
	checker = 0;
	while (get_next_line(0, &p->line) > 0)
	{
		r.i = 0;
		r.room = ft_strsplit(p->line, ' ');
		checker = verif_room(s, p, &r, b);
		if (checker == 0 || checker == 2)
			return ((checker == 0) ? 0 : 1);
		free_tab_str(r.room);
	}
	return (0);
}
