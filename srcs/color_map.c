/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:58:06 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/10 16:58:08 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	color_map(char **str, char *line, t_bonus *b, int i)
{
	if (b->color == 1)
	{
		*str = (i == 0) ? ft_free_njoin((char**)(char*[]){*str, "\e[38;5;196m",
		line, "\e[0;0m", "\n"}, 5, (int *)(int[]){1, 0, 1, 0, 0}) : *str;
		*str = (i == 1) ? ft_free_njoin((char**)(char*[]){*str, "\e[1;2m",
		line, "\e[0;0m", "\n"}, 5, (int *)(int[]){1, 0, 1, 0, 0}) : *str;
		*str = (i == 2) ? ft_free_njoin((char**)(char*[]){*str, "\e[38;5;33m",
		line, "\e[0;0m", "\n"}, 5, (int *)(int[]){1, 0, 1, 0, 0}) : *str;
		*str = (i == 3) ? ft_free_njoin((char**)(char*[]){*str, "\e[38;5;40m",
		line, "\e[0;0m", "\n"}, 5, (int *)(int[]){1, 0, 1, 0, 0}) : *str;
		*str = (i == 4) ? ft_free_njoin((char**)(char*[]){*str, "\e[38;5;202m",
		line, "\e[0;0m", "\n"}, 5, (int *)(int[]){1, 0, 1, 0, 0}) : *str;
	}
	else
	{
		*str = ft_free_njoin((char**)(char*[]){*str, line,
		"\n"}, 3, (int *)(int[]){1, 1, 0});
	}
}

void	color_algo(char *str, int *buff, t_bonus *b, int i)
{
	if (b->color == 1)
	{
		(i == 0) ? buff_join_nstr(str, (char**)(char*[]){"\e[38;5;61m",
		"\nRésultat :\n", "\e[0;0m"}, buff, 3) : (void)i;
		(i == 1) ? buff_join_nstr(str, (char**)(char*[]){"\e[38;5;61m",
		"\nChemins utilisé :\n", "\e[0;0m"}, buff, 3) : (void)i;
		(i == 2) ? buff_join_nstr(str, (char**)(char*[]){"\e[38;5;61m",
		"\nChemins consideré :\n", "\e[0;0m"}, buff, 3) : (void)i;
		(i == 3) ? buff_join_nstr(str, (char**)(char*[]){"\e[0;0m"},
		buff, 1) : (void)i;
	}
	else
	{
		(i == 0) ? buff_join_nstr(str, (char**)(char*[]){"\nRésultat :\n"},
		buff, 1) : (void)i;
		(i == 1) ? buff_join_nstr(str, (char**)(char*[]){
		"\nChemins utilisé :\n"}, buff, 1) : (void)i;
		(i == 2) ? buff_join_nstr(str, (char**)(char*[]){
		"\nChemins consideré :\n"}, buff, 1) : (void)i;
	}
}
