# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 18:06:29 by eschirni          #+#    #+#              #
#    Updated: 2021/07/16 11:16:29 by eschirni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "libft.a"

all:
	@gcc -c -Wall -Wextra -Werror ft_[!l]*.c
	@ar rcs libft.a *.o
	
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: fclean
	@gcc -c -Wall -Wextra -Werror *.c
	@ar rcs libft.a *.o