# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrunell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 12:08:07 by bbrunell          #+#    #+#              #
#    Updated: 2016/02/09 12:01:16 by bbrunell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c ft_atoi.c \
		ft_strcmp.c ft_putstr.c ft_putchar.c ft_putstr_fd.c ft_verifint.c \
		ft_putnbr.c ft_strsplit.c ft_strdel.c get_next_line.c ft_check_end.c \
		ft_memalloc.c ft_strdup.c ft_bzero.c ft_strstr.c ft_putendl.c \
		ft_itoll.c ft_free_join.c ft_free_join_char.c  ft_strlen_char.c \
		free_tab_str.c ft_free1_join_char.c ft_free_njoin.c buff_join.c \
		buff_join_nstr.c

OBJECT = $(SRCS:.c=.o)

$(NAME): 
		gcc -c $(SRCS) -I ./
		ar rc $(NAME) $(OBJECT)
		ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
