/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 14:41:09 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/17 15:25:07 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	elements;

	if (lst == NULL)
		return (0);
	elements = 1;
	if (lst->next != 0)
		elements += ft_lstsize(lst->next);
	return (elements);
}
