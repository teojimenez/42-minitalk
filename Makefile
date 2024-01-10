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

NAME_CLIENT = client

NAME_SERVER = server

FLAGS = -Wall -Wextra -Werror -g

SRC =	server.c client.c utils.c

OBJECTS = $(SRC:.c=.o)

CC = gcc

$(NAME_CLIENT):	client.o Makefile minitalk.h utils.o
		${CC} ${FLAGS} client.o Makefile minitalk.h utils.o -o ${NAME_CLIENT}

$(NAME_SERVER):	${OBJECTS} client.o Makefile minitalk.h
		${CC} ${FLAGS} server.o Makefile minitalk.h utils.o -o ${NAME_SERVER} ${OBJECTS}

all: $(NAME_SERVER) $(NAME_CLIENT)

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME_SERVER)
	rm -rf $(NAME_CLIENT)

re:	fclean all

.PHONY: 	all clean fclean re
