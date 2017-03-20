/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 21:06:07 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 21:06:09 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	verif_bonus(int ac, char **av, t_bonus *b)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp("-c", av[i]))
			b->color = 1;
		else if (!ft_strcmp("-r", av[i]))
			b->nbr_room = 1;
		else if (!ft_strcmp("-wf", av[i]))
			b->way_find = 1;
		else if (!ft_strcmp("-wu", av[i]))
			b->way_use = 1;
		else if (!ft_strcmp("-l", av[i]))
			b->laps = 1;
		else if (!ft_strcmp("-hm", av[i]))
			b->hide_map = 1;
		else if (!ft_strcmp("-ha", av[i]))
			b->hide_algo = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

static int	verif_laps_too_big(t_graph **graph, t_way *w)
{
	int i;
	int min;

	i = 0;
	min = 0;
	while (i < ((*graph)[1]).nbr_connection)
	{
		if (min == 0 || (((((*graph)[1]).next[i])->laps) > 0 &&
		((((*graph)[1]).next[i])->laps) < min))
			min = ((((*graph)[1]).next[i])->laps);
		i++;
	}
	if (w->ant + (min - 1) > 2147483647)
		return (0);
	return (1);
}

static int	lem_in(t_graph **graph, t_way *w, t_bonus *b, t_parse_map *p)
{
	t_list_room *room;

	room = NULL;
	if (check_ant(w, p, b) && check_room(&room, p, b) &&
	check_connection(&room, p, b) && connect_room(graph, &room) &&
	find_ways(graph) && verif_laps_too_big(graph, w))
		return (1);
	return (0);
}

static void	print_usage(void)
{
	ft_putstr("ERROR\n");
	ft_putstr("usage : ./lem-in [bonus] < map\nbonus :\n-c : couleur\n");
	ft_putstr("-r : nombre de salle\n-wf : way_find\n-wu : way_use\n-l : ");
	ft_putstr("nombre de coup\n-hm : cacher la map\n-ha : cacher l'algo\n");
}

int			main(int ac, char **av)
{
	t_graph		*graph;
	t_way		w;
	t_bonus		b;
	t_parse_map p;

	graph = NULL;
	graph = NULL;
	ft_bzero(&b, sizeof(t_bonus));
	p.final_str = ft_strnew(0);
	if (ft_strcmp("./lem-in", av[0]) == 0 && verif_bonus(ac, av, &b))
	{
		if (lem_in(&graph, &w, &b, &p))
		{
			if (b.hide_map != 1)
				ft_putstr(p.final_str);
			find_best_possibility(&graph, &w, &b);
		}
		else
			return (ft_error());
	}
	else
		print_usage();
	return (0);
}
