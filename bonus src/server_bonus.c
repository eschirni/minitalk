/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 20:22:26 by eschirni          #+#    #+#             */
/*   Updated: 2021/09/14 17:31:39 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
extern char	*g_client;

// resets the global variable (25 line problem)
static void	ft_del_global(void)
{
	free(g_client);
	g_client = NULL;
}

// converts binary to ascii or unicode
// returns the result as an integer
// if it's not just for comparison it prints the character
static int	ft_convert(char *s, int b_write)
{
	int				pow;
	int				c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	if (b_write == 1)
	{
		write(1, &c, 1);
		return ((char) NULL);
	}
	return (c);
}

// reads every bit and appends it to bits
// if its a 8 bit ascii char or a 24 bit unicode char it converts it
// the result gets printed and the server sends the client an ack
static void	ft_confirm(int sig)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_appendC(bits, '0');
	else
		bits = ft_appendC(bits, '1');
	if ((bitcount == 8 && ft_convert(bits, 0) < 255) || bitcount == 24)
	{
		if (ft_convert(bits, 0) == 0 && bitcount != 24)
			ft_del_global();
		else
		{
			ft_convert(bits, 1);
			kill(ft_atoi(g_client), SIGUSR1);
		}
		free(bits);
		bits = NULL;
	}
}

// safes all bits in a string and conerts every byte to a char
// the char will get appended to the client variable (PID)
static void	ft_get_pid(int sig)
{
	static char	*bits;
	static int	bitcount;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_appendC(bits, '0');
	else
		bits = ft_appendC(bits, '1');
	if (bitcount == 8)
	{
		g_client = ft_appendC(g_client, ft_convert(bits, 0));
		free(bits);
		bits = NULL;
	}
}

// if it has not the clinet PID it takes 8 bytes the client PID
// otherwise it will decode the binary to ascii and print it
int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	while (1 == 1)
	{
		if (g_client == NULL)
		{
			g_client = ft_strdup("");
			while (ft_strlen(g_client) < 7)
			{
				signal(SIGUSR1, ft_get_pid);
				signal(SIGUSR2, ft_get_pid);
				pause();
			}
		}
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause();
	}
	return (0);
}
