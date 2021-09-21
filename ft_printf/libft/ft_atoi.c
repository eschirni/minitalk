/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:32:43 by eschirni          #+#    #+#             */
/*   Updated: 2021/07/20 19:15:28 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_count(int *i, int *neg, const char *str)
{
	*i = 0;
	*neg = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*neg *= -1;
		*i += 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
		*i += 1;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	multiplicator;
	int	num;
	int	neg;

	multiplicator = 1;
	num = 0;
	ft_count(&i, &neg, str);
	while (i > 0 && str[i - 1] >= '0' && str[i - 1] <= '9')
	{
		num += (str[i - 1] - '0') * multiplicator;
		multiplicator *= 10;
		i--;
	}
	return (num * neg);
}
