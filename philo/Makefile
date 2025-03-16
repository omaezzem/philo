# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 10:53:12 by omaezzem          #+#    #+#              #
#    Updated: 2025/03/15 10:56:13 by omaezzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAIN_SOURCES = src/errormsg.c\
			   src/parsing.c\
			   src/philo.c\
			   utilis/atoi_ph.c\
			   utilis/ft_putstr_fd.c\
			   utilis/isdigit.c\

MAIN_OBJECTS = $(MAIN_SOURCES:.c=.o)

all : $(NAME)

$(MAIN_OBJECTS):%.o: %.c include/philo.h
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) $(MAIN_OBJECTS) -o $(NAME)

clean :
	@rm -f $(MAIN_OBJECTS)

fclean : clean
	@rm -f $(NAME)

re : fclean all
