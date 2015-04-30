# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/30 18:09:49 by bbarakov          #+#    #+#              #
#    Updated: 2015/01/12 12:44:28 by bbarakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=			gcc

FLAGS=		-Wall -Werror -Wextra

NAME = 		ft_ls

SRC =	 	source/dirs.c \
			source/errors_and_free.c \
			source/get_biggest.c \
			source/main.c \
			source/options.c \
			source/create_cont.c \
			source/print.c \
			source/sort.c \
			source/attributes/attr.c \
			source/attributes/attr1.c \
			source/attributes/attr2.c \
			source/attributes/attr_time.c \
			source/attributes/attr_x.c \

OBJ=		$(SRC:.c=.o)

INCLUDES = 	includes

all: $(NAME) lib

lib:
	@make re -C ./libft

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $^ -I $(INCLUDES) -L ./libft -lft -o $@

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -I $(INCLUDES) -o $@

.PHONY: clean fclean

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
