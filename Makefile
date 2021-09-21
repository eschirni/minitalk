# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 20:20:09 by eschirni          #+#    #+#              #
#    Updated: 2021/09/13 20:26:52 by eschirni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@cd ft_printf && make all
	@gcc -Wall -Wextra -Werror src/server.c ft_printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror src/client.c ft_printf/libftprintf.a -o client

clean:
	@cd ft_printf && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd ft_printf && make fclean

re: fclean all

bonus: fclean
	@cd ft_printf && make all
	@gcc -Wall -Wextra -Werror "bonus src/server_bonus.c" ft_printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror "bonus src/client_bonus.c" ft_printf/libftprintf.a -o client
