/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:11:31 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/01 16:17:15 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_error(void)
{
	ft_putstr("ERROR\n");
	return (0);
}

int		error_free_tab(char **tab, int i)
{
	free_tab_str(tab);
	return (i);
}
