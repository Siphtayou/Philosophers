# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agilles <agilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 17:28:18 by agilles           #+#    #+#              #
#    Updated: 2024/08/05 14:58:24 by agilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=thread

SRC =	main.c \
		src/check/arg.c \
		src/err/arg_err.c \
		src/err/debug_print.c \
		src/init.c \
		src/philo_utils.c \
		src/algo/monitor.c \
		src/algo/philo_routine.c \
		src/thread.c \
		src/print_color.c \

OBJ = $(SRC:.c=.o)
NAME = philo

all: $(NAME)

exec: $(NAME)
	./philo

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re exec
