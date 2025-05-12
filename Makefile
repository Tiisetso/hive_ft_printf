# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timurray <timurray@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 16:04:25 by timurray          #+#    #+#              #
#    Updated: 2025/05/08 16:09:44 by timurray         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprint.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES =	ft_isprintf.c \
			libftprint.h

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
