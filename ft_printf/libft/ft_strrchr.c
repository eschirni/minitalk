/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:13:45 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/20 20:33:30 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = (char *) NULL;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			last = (char *)&s[i];
		i++;
	}
	if (c == '\0')
		last = (char *)&s[i];
	return (last);
}
