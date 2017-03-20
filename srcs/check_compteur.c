/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compteur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 04:32:33 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/07 04:32:35 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_compteur(int laps, int *size_room)
{
	int i;
	int compteur;

	i = 0;
	compteur = 0;
	while (size_room[i] != -1)
	{
		if (size_room[i] <= laps)
			compteur++;
		i++;
	}
	return ((compteur == 0) ? 1 : compteur);
}
