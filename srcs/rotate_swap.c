/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:23:13 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/01 16:23:37 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	do_sa_sb_next(t_list_room **stack_a, t_list_room *temp,
t_list_room *tmp, t_list_room *tmp2)
{
	t_list_room *tmpt;

	if (ft_strcmp(temp->name, tmp2->name))
	{
		tmpt = temp->next;
		while (ft_strcmp(tmpt->name, tmp2->name))
		{
			temp = temp->next;
			tmpt = temp->next;
		}
		temp->next = tmp;
		tmp2->next = NULL;
		tmp->next = tmp2;
	}
	else
	{
		tmp->next = tmp2;
		tmp2->next = NULL;
		*stack_a = tmp;
	}
}

void		do_sa_sb(t_list_room **stack_a)
{
	t_list_room *tmp;
	t_list_room *temp;
	t_list_room	*tmp2;

	tmp = *stack_a;
	temp = *stack_a;
	if (tmp != NULL && tmp->next != NULL)
	{
		while (tmp->next != NULL)
		{
			tmp2 = tmp;
			tmp = tmp->next;
		}
		do_sa_sb_next(stack_a, temp, tmp, tmp2);
	}
}

void		do_ra_rb(t_list_room **stack_a)
{
	t_list_room *tmp;
	t_list_room *temp;

	tmp = *stack_a;
	if (tmp != NULL && tmp->next != NULL)
	{
		while (tmp->next != NULL)
		{
			temp = tmp;
			tmp = tmp->next;
		}
		temp->next = NULL;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void		do_rra_rrb(t_list_room **stack_a)
{
	t_list_room	*tmp;
	t_list_room *temp;
	t_list_room *tmp2;

	tmp = *stack_a;
	temp = *stack_a;
	if (tmp != NULL && tmp->next != NULL)
	{
		tmp2 = tmp->next;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = temp;
		temp->next = NULL;
		*stack_a = tmp2;
	}
}
