/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:52:18 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/09 17:14:08 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*point;
	size_t	i;

	point = b;
	i = 0;
	while (i < len)
	{
		point[i] = c;
		i++;
	}
	return (point);
}
