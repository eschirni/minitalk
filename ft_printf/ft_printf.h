/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:42:04 by eschirni          #+#    #+#             */
/*   Updated: 2021/08/24 16:49:35 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

char	*ft_uitoa(unsigned int n);
char	*ft_hexitoa(unsigned long n, char cha);
int		ft_printf(const char *s, ...);

#endif
