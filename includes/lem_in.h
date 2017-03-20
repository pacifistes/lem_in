/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:11:33 by bbrunell          #+#    #+#             */
/*   Updated: 2017/02/13 17:11:47 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_ant
{
	int				ant;
}					t_ant;

typedef struct		s_graph
{
	char			*name;
	int				start_end;
	int				laps;
	int				nbr_connection;
	int				pos_graph;
	struct s_graph	**next;
}					t_graph;

typedef struct		s_way
{
	int				ant;
	int				**way;
	int				size;
	int				*room;
	int				*tmp_room;
	int				*pos_ant;
	int				*col_ant;
	int				laps;
	int				begin;
	int				end;
}					t_way;

typedef struct		s_list_room
{
	char			*name;
	char			*connection;
	int				pos_graph;
	int				pos[2];
	int				start_end;
	void			*next;
}					t_list_room;

typedef struct		s_check_room
{
	char			**room;
	int				i;
	int				j;
	int				start_or_end;
	int				start;
	int				end;
}					t_check_room;

typedef struct		s_connect_room
{
	int				limit_graph;
	int				pos_graph;
}					t_connect_room;

typedef struct		s_index
{
	int				i;
	int				j;
}					t_index;

typedef struct		s_check_connection
{
	char			**room;
	t_index			index;
}					t_check_connection;

typedef struct		s_parse_map
{
	char			*final_str;
	char			*line;
}					t_parse_map;

typedef struct		s_possible
{
	int				nbr_way;
	t_index			index;
	int				h;
	int				nbr_possibility;
}					t_possible;

/*
** -c -r -wf -wu -wf -l -hm -ha
*/

typedef struct		s_bonus
{
	int				color;
	int				nbr_room;
	int				way_find;
	int				way_use;
	int				laps;
	int				hide_map;
	int				hide_algo;
}					t_bonus;

typedef struct		s_algo
{
	int				i;
	int				nbr_choose_way;
	char			str[BUFFER];
	int				j;
	int				buff;
	int				laps;
	int				*size_room;
}					t_algo;

void				do_rra_rrb(t_list_room **stack_a);
void				do_ra_rb(t_list_room **stack_a);
void				do_sa_sb(t_list_room **stack_a);
int					ft_error();
int					do_gnl(char **line, int fd, int *ret);
int					ft_isnumber(char *str);
void				put_start_in_first_position(t_list_room **room);
void				put_end_in_secon_position(t_list_room **room);
void				lstadd_room(t_list_room **s, char *str, int *pos);
int					lst_add_connection(t_list_room **s, char *str1, char *str2);
int					ft_find_address(char *str, t_list_room **s);
int					check_ant(t_way *w, t_parse_map *p, t_bonus *b);
int					check_room(t_list_room **s, t_parse_map *p, t_bonus *b);
int					check_connection(t_list_room **s, t_parse_map *p,
t_bonus *b);
int					connect_room(t_graph **graph, t_list_room **room);
int					check_name_and_pos(t_list_room **s, char *str, int *pos);
int					room_valid(int i, char **room, t_list_room **s);
int					find_ways(t_graph **graph);
int					ft_end_not_there(t_graph **graph, int a);
void				find_nbr_way(t_graph **graph, int a, int *nbr);
void				complete_way(t_way *w, int *h);
void				order_way(int **tab, int **way);
int					size_way(int *tab);
int					cmp_way(t_way *w, int j, int i);
void				order_tab(int **tab);
void				copy_tab(t_way *w);
void				reset_tab(int **tab, int nbr_way);
void				put_in_str(t_graph **graph, t_way *w, t_bonus *b);
int					check_compteur(int laps, int *size_room);
void				incremante_ant(t_graph **graph, t_way *w, int compteur);
void				find_best_possibility(t_graph **graph, t_way *w,
t_bonus *b);
void				choose_ways(t_way *w, int i, int nbr_way);
void				color_map(char **str, char *line, t_bonus *b, int i);
void				color_algo(char *str, int *buff, t_bonus *b, int i);
void				verif_combi(t_way *w, int nombre_salle);
void				print_information(t_graph **graph, t_way *w, t_bonus *b,
t_algo *a);
int					error_free_tab(char **tab, int i);

#endif
