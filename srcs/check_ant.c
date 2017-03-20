/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:05:10 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/02 16:05:12 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ant(t_way *w, t_parse_map *p, t_bonus *b)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_isnumber(line) && ft_verifint(line) != 2147484848)
		{
			w->ant = ft_atoi(line);
			if (w->ant <= 0)
				return (0);
			color_map(&p->final_str, line, b, 0);
			return (1);
		}
		if (!line || (line && line[0] != '#') || !ft_strcmp("##start", line)
		|| !ft_strcmp("##end", line))
		{
			ft_strdel(&line);
			return (0);
		}
		color_map(&p->final_str, line, b, 1);
	}
	if (ret != -1)
		ft_strdel(&line);
	return (0);
}
