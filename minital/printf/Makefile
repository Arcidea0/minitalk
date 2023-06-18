# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armgevor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 08:42:24 by armgevor          #+#    #+#              #
#    Updated: 2023/06/07 18:15:03 by armgevor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =	ft_printf.c	ft_utils.c

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
