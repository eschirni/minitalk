# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 14:05:23 by eschirni          #+#    #+#              #
#    Updated: 2021/08/24 16:41:05 by eschirni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "libftprintf.a"

FILES = ft_hexitoa.c	ft_printf.c	ft_uitoa.c

OBJECTS = ft_hexitoa.o	ft_printf.o	ft_uitoa.o

all:
	@gcc -c -Wall -Wextra -Werror $(FILES)
	@cd libft && make all
	@ar rcs $(NAME) $(OBJECTS) libft/*.o
	
clean:
	@rm -f $(OBJECTS)
	@cd libft && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean

re: fclean all
