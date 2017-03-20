/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:31:40 by bbrunell          #+#    #+#             */
/*   Updated: 2016/02/09 11:51:25 by bbrunell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# define BUFF_SIZE 32
# define BUFFER 2000

size_t				ft_strlen(const char *s);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
long int			ft_verifint(const char *str);
char				**ft_strsplit(char const *s, char c);
void				ft_strdel(char **as);
int					get_next_line(int const fd, char **line);
int					ft_check_end(char *s1);
void				*ft_memalloc(size_t size);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *s, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
void				ft_putendl(char const *s);
char				*ft_itoll(long long int n);
char				*ft_free_join(char *s1, char *s2);
char				*ft_free_join_char(char *s1, char *s2, char c);
int					ft_strlen_char(char *str, char c);
void				free_tab_str(char **tab);
char				*ft_free1_join_char(char *s1, char *s2, char c);
char				*ft_free_njoin(char **str, int nbr_str, int *str_free);
void				buff_join(char *str_buff, char *str, int *buff);
void				buff_join_nstr(char *str_buff, char **str, int *buff,
int nbr_str);
#endif
