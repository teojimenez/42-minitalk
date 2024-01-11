# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 15:49:47 by teojimen          #+#    #+#              #
#    Updated: 2024/01/10 15:49:47 by teojimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = all

NAME_CLIENT = client
NAME_SERVER = server

FLAGS = -Wall -Wextra -Werror -g

SRC = server.c client.c utils.c utils2.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME_SERVER) server.o utils.o utils2.o
	$(CC) $(FLAGS) -o $(NAME_CLIENT) client.o utils.o utils2.o

# tiene relinks
%.o: %.c Makefile minitalk.h
	$(CC) $(FLAGS) -I ./ -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME_SERVER)
	rm -rf $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
