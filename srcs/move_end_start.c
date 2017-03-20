/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_end_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:15:08 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/01 16:15:30 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_start_in_first_position(t_list_room **room)
{
	while (*room && (*room)->start_end != 1)
		do_rra_rrb(room);
}

void	put_end_in_secon_position(t_list_room **room)
{
	do_rra_rrb(room);
	while (*room && (*room)->start_end != 2)
	{
		do_rra_rrb(room);
		do_sa_sb(room);
	}
	do_ra_rb(room);
}
