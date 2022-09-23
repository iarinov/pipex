# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 10:15:32 by aiarinov          #+#    #+#              #
#    Updated: 2022/07/26 12:48:48 by aiarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FAGS = 	-Wall -Wextra -Werror  -fsanitize=address -static-libasan -g
NAME = 	pipex
SRC = 	main.c error.c free.c pipex_utils.c
OBJ = 	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(OBJ) ./libft/libft.a -o $(NAME) $(FLAGS)

clean:
	make clean -C ./libft/
	rm -fr $(OBJ)

fclean: clean
	make fclean -C ./libft/
	rm -fr $(NAME)

re: fclean all
