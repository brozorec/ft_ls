# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbarakov <bbarakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/30 18:09:49 by bbarakov          #+#    #+#              #
#    Updated: 2014/12/30 18:27:19 by bbarakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = attr.c attr1.c attr2.c attr_time.c dirs.c errors.c get_biggest.c \
main.c options.c params.c print.c sort.c

INCLUDES = .

all: $(NAME)

lib:
	@make re -C ./libft
	@make clean -C ./libft

$(NAME): lib
	@gcc -Wall -Werror -Wextra $(SRC) -I $(INCLUDES) -L ./libft -lft -o $(NAME)

clean:

fclean: clean
	@rm -f $(NAME)

re: fclean clean
