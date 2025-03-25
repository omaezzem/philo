# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 10:53:12 by omaezzem          #+#    #+#              #
#    Updated: 2025/03/24 21:56:21 by omaezzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

MAIN_SOURCES = src/parsing.c\
			   src/main.c\
			   src/philo.c\
			   src/dining.c\
			   src/hyper.c\
			   src/dining_utils.c\
			   src/utils.c\
			   utilis/atoi_ph.c\
			   utilis/ft_putstr_fd.c\
			   utilis/isdigit.c\
			   utilis/get_time.c\

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
