/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:47:34 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/26 13:47:49 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + ft_strlen(src));
	while (i + 1 < dstsize)
	{
		if (src[i - dst_len] == '\0')
			break ;
		dst[i] = src[i - dst_len];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src) + dst_len);
}
