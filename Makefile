# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+          #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 14:29:14 by teojimene         #+#    #+#              #
#    Updated: 2024/01/27 14:29:14 by teojimene        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = all

NAME_CLIENT = client
NAME_SERVER = server

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = server.c client.c utils.c utils2.c server_extra.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME_SERVER) server.o utils.o utils2.o server_extra.o
	$(CC) $(FLAGS) -o $(NAME_CLIENT) client.o utils.o utils2.o server_extra.o

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
