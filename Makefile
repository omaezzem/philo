# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omaezzem <omaezzem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 10:53:12 by omaezzem          #+#    #+#              #
#    Updated: 2025/04/17 14:18:53 by omaezzem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc  

CFLAGS = -Wall -Wextra -Werror  -o  -lpthread
 #-g3 -fsanitize=thread
MAIN_SOURCES = src/parsing.c\
			   src/main.c\
			   src/dining.c\
			   src/hyper.c\
			   src/init.c\
			   src/ft_destroy.c\
			   src/dining_utils.c\
			   src/ft_slp.c\
			   src/bismillah.c\
			   utils/atoi_ph.c\
			   utils/ft_putstr_fd.c\
			   utils/isdigit.c\
			   utils/get_time.c\

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
