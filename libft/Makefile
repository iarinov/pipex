# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiarinov <aiarinov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:55:06 by aiarinov          #+#    #+#              #
#    Updated: 2022/08/01 12:59:05 by aiarinov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = ft_strlen.c ft_strchr.c ft_strjoin.c ft_split.c ft_strncmp.c



all: $(NAME)

$(NAME):	$(SOURCE)
	gcc -Werror -Wextra -Wall $^ -c

	ar -rs $(NAME) *.o


clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	clean fclean all re
