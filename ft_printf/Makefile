# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:52:18 by gmorais-          #+#    #+#              #
#    Updated: 2022/11/21 11:34:49 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_words ft_numbers ft_printf\

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME): $(SRC:=.o)
		ar rc $(NAME) $(SRC:=.o)
clean:
	$(RM) $(SRC:=.o)
fclean: clean
		$(RM) $(NAME)
re: fclean $(NAME)