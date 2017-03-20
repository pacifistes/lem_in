/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_join_nstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:11:03 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/13 15:11:05 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buff_join_nstr(char *str_buff, char **str, int *buff, int nbr_str)
{
	int i;

	i = 0;
	while (i < nbr_str)
	{
		while (str[i] && i < nbr_str)
		{
			buff_join(str_buff, str[i], buff);
			i++;
		}
		i++;
	}
}
