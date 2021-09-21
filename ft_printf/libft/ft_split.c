/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:32:32 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/20 20:26:21 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_create_array(size_t start, const char *s, size_t chars)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = malloc(chars + 1);
	while (i < chars)
	{
		dst[i] = s[start];
		start += 1;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_inner_string(size_t *start, const char *s, char c)
{
	size_t	chars;
	size_t	i;
	char	*dst;

	chars = 0;
	while (*start < ft_strlen(s))
	{
		if (s[*start] != c)
		{
			i = *start;
			while (i < ft_strlen(s) && s[i] != c)
			{
				chars++;
				i++;
			}
			break ;
		}
		*start += 1;
	}
	dst = ft_create_array(*start, s, chars);
	*start += chars + 1;
	return (dst);
}

static int	ft_count_string(const char *s, char c)
{
	size_t	i;
	int		string_count;

	i = 0;
	string_count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			string_count++;
			while (i < ft_strlen(s) && s[i] != c)
				i++;
		}
		i++;
	}
	return (string_count);
}

char	**ft_split(const char *s, char c)
{
	int		string_count;
	size_t	i;
	size_t	start;
	char	**split;

	string_count = ft_count_string(s, c);
	split = ft_calloc(string_count + 1, sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (i < (size_t) string_count)
	{
		split[i] = ft_inner_string(&start, s, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
