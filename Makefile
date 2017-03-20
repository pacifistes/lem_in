NAME = lem-in

SRCSPATH = srcs/
INCLUDES = includes/
LIBFT = libft/

SRCS = 	lem_in.c rotate_swap.c ft_error.c do_gnl.c ft_isnumber.c \
move_end_start.c lst_add_functions.c ft_find_address.c check_room.c \
check_ant.c check_connection.c connect_room.c check_name_and_pos.c \
room_valid.c find_ways.c ft_end_not_there.c put_in_str.c way_functions.c \
tab_functions.c check_compteur.c incremante_ant.c find_best_possibility.c \
choose_ways.c color_map.c verif_combi.c print_information.c

SRC = $(addprefix $(SRCSPATH), $(SRCS))

WFLAGS = -Wall -Werror -Wextra -march=native -O3

CC = gcc -g

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) -c $(WFLAGS) -I $(LIBFT) -I $(INCLUDES) $< -o $@

$(NAME) : $(OBJ)
	make -C $(LIBFT)
	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) -I $(INCLUDES) -L $(LIBFT) -lft

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re : fclean all

.PHONY: all clean fclean re
