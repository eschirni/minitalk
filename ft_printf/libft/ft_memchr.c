/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:54:40 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/09 17:23:57 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*string;
	size_t		i;

	string = s;
	i = 0;
	while (i < n)
	{
		if (string[i] == c)
			return ((void *)&string[i]);
		i++;
	}
	return (NULL);
}
