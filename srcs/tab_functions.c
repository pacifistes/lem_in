/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:32:43 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 04:32:45 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset_tab(int **tab, int nbr_way)
{
	int i;

	i = 0;
	while (i < nbr_way)
	{
		(*tab)[i] = 0;
		i++;
	}
}

void	copy_tab(t_way *w)
{
	int i;

	i = 0;
	while (w->tmp_room[i] != -1)
	{
		w->room[i] = w->tmp_room[i];
		i++;
	}
}

void	order_tab(int **tab)
{
	int i;
	int swap;

	i = 0;
	while ((*tab)[i] != -1)
	{
		if ((*tab)[i] > (*tab)[i + 1] && (*tab)[i + 1] != -1)
		{
			swap = (*tab)[i];
			(*tab)[i] = (*tab)[i + 1];
			(*tab)[i + 1] = swap;
			order_tab(tab);
		}
		i++;
	}
}
