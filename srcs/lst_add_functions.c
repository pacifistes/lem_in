/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:20:48 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/01 16:20:50 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lstadd_room(t_list_room **s, char *str, int *pos)
{
	t_list_room	*temp;

	temp = ft_memalloc(sizeof(t_list_room));
	temp->name = ft_strdup(str);
	temp->connection = ft_strnew(0);
	temp->start_end = pos[2];
	temp->pos[0] = pos[0];
	temp->pos[1] = pos[1];
	temp->next = *s;
	*s = temp;
}

static void	register_connection(t_list_room *tmp, t_list_room *temp,
char *str1, char *str2)
{
	char *tmp2;

	if (ft_strcmp(temp->name, tmp->name) && (!ft_strstr(tmp->connection, str2)
	|| (tmp->start_end == 1 && temp->start_end == 2)
	|| (tmp->start_end == 2 && temp->start_end == 1)))
	{
		tmp2 = tmp->connection;
		tmp->connection = ft_strjoin(tmp->connection, str2);
		free(tmp2);
		tmp2 = tmp->connection;
		tmp->connection = ft_strjoin(tmp->connection, " ");
		free(tmp2);
		tmp2 = temp->connection;
		temp->connection = ft_strjoin(temp->connection, str1);
		free(tmp2);
		tmp2 = temp->connection;
		temp->connection = ft_strjoin(temp->connection, " ");
		free(tmp2);
	}
}

int			lst_add_connection(t_list_room **s, char *str1, char *str2)
{
	t_list_room *tmp;
	t_list_room *temp;

	temp = *s;
	tmp = *s;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str1))
		{
			while (temp)
			{
				if (!ft_strcmp(temp->name, str2))
				{
					register_connection(tmp, temp, str1, str2);
					return (1);
				}
				temp = temp->next;
			}
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}
