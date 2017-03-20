/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:10:56 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/13 15:10:58 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	buff_join(char *str_buff, char *str, int *buff)
{
	int i;

	i = 0;
	str_buff[*buff] = 0;
	while (str && str[i])
	{
		if (*buff == BUFFER)
		{
			write(1, str_buff, *buff);
			*buff = *buff - BUFFER;
		}
		str_buff[*buff] = str[i];
		*buff = *buff + 1;
		i++;
	}
	if (*buff == BUFFER)
	{
		write(1, str_buff, *buff);
		*buff = *buff - BUFFER;
	}
}
