/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:44:42 by eschirni          #+#    #+#             */
/*   Updated: 2021/08/25 15:21:41 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int	specifierxXp(char c, va_list lst, char *s, size_t strsize)
{
	if (c == 'x' || c == 'X')
	{
		s = ft_hexitoa(va_arg(lst, unsigned int), c);
		ft_putstr_fd(s, 1);
		strsize = ft_strlen(s);
		free(s);
		return (strsize);
	}
	else
	{
		s = ft_hexitoa(va_arg(lst, unsigned long), c);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(s, 1);
		strsize = ft_strlen(s);
		free(s);
		return (strsize + 2);
	}
}

static int	specifieridu(char c, va_list lst, char *s, size_t strsize)
{
	if (c == 'i' || c == 'd')
	{
		s = ft_itoa(va_arg(lst, int));
		ft_putstr_fd(s, 1);
		strsize = ft_strlen(s);
		free(s);
		return (strsize);
	}
	else if (c == 'u')
	{
		s = ft_uitoa(va_arg(lst, unsigned int));
		ft_putstr_fd(s, 1);
		strsize = ft_strlen(s);
		free(s);
		return (strsize);
	}
	else
		return (specifierxXp(c, lst, s, 0));
}

static int	specifier(char c, va_list lst)
{
	char	*s;

	s = NULL;
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(lst, int), 1);
		return (1);
	}
	else if (c == 's')
	{
		s = va_arg(lst, char *);
		if (s == NULL)
		{
			write(1, "(null)", 6);
			return (6);
		}
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	else
		return (specifieridu(c, lst, s, 0));
}

static void	check_string(size_t *i, int *ret, const char *s, va_list lst)
{
	if (s[*i] == '%' && s[*i + 1] == '%')
	{
		ft_putchar_fd('%', 1);
		*i += 1;
		*ret += 1;
	}
	else if (s[*i] == '%' && s[*i + 1] != '\0')
	{
		*ret += specifier(s[*i + 1], lst);
		*i += 1;
	}
	else
	{
		ft_putchar_fd(s[*i], 1);
		*ret += 1;
	}
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	int		ret;
	va_list	lst;

	i = 0;
	ret = 0;
	va_start(lst, s);
	while (s[i] != '\0')
	{
		check_string(&i, &ret, s, lst);
		i++;
	}
	va_end(lst);
	return (ret);
}
