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

NAME_SERVER = server
NAME_CLIENT = client

FLAGS = -Wall -Wextra -Werror -g

SRC = server.c client.c utils.c utils2.c server_extra.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

all: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: server.o utils.o utils2.o server_extra.o Makefile minitalk.h
	${CC} ${FLAGS} server.o utils.o utils2.o server_extra.o -o ${NAME_SERVER}

${NAME_CLIENT}: client.o utils.o utils2.o Makefile minitalk.h
	${CC} ${FLAGS} client.o utils.o utils2.o -o ${NAME_CLIENT}

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME_SERVER)
	rm -rf $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
