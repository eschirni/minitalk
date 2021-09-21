/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:11:58 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/20 19:54:46 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_write_num(int n, int fd)
{
	char	c[10];
	int		i;

	if (n < 0)
	{
		n *= -1;
		write(fd, &"-", 1);
	}
	c[0] = n + '0';
	if (n == 0)
		write(fd, &c[0], 1);
	i = -1;
	while (n != 0)
	{
		i++;
		c[i] = n % 10 + '0';
		n /= 10;
	}
	while (i >= 0)
	{
		write(fd, &c[i], 1);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		ft_write_num(n, fd);
	}
}
