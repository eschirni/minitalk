/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 21:09:19 by eschirni          #+#    #+#             */
/*   Updated: 2021/09/14 17:34:23 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
extern char	*g_client;

// always called when the server sends a signal
// appends a to the global so it can compare the length in the main
static void	ft_ack(int sig)
{
	char	*temp;

	if (sig == SIGUSR1)
	{
		temp = ft_appendC(g_client, 'a');
		g_client = temp;
	}
}

// sends the binary message to the server
// when it has sent 8 it checks for a server response
// waits so the signals won't get ignored
static void	ft_send_msg(int pid, char *s)
{
	size_t	i;

	i = 1;
	while (s[i - 1] != '\0')
	{
		if (s[i - 1] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		if (i % 8 == 0)
		{
			signal(SIGUSR1, ft_ack);
		}
		i++;
		usleep(160);
	}
}

// converts the string to binary
// starts from the end of the string with conversion
// puts the binary number at the end of ret
// unsigned char so it can handle unicode too
static char	*ft_to_bit(char *s, size_t i, size_t j)
{
	char	*ret;
	int		c;
	int		bytes;

	i = ft_strlen(s);
	ret = ft_calloc(i * 8 + 1, sizeof(unsigned char));
	if (ret == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = (unsigned char) s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[ft_strlen(s) * 8 - j - 1] = '1';
			else
				ret[ft_strlen(s) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}

// sends his own PID to the server
// if the PID less than 8 chars then send 01 till its 8
static void	ft_send_pid(int pid, int i)
{
	char	*client_pid;
	char	*client_bin;

	client_pid = ft_itoa(getpid());
	client_bin = ft_to_bit(client_pid, 0, 0);
	free(client_pid);
	while (client_bin[i] != '\0')
	{
		if (client_bin[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(80);
	}
	while (i < 56)
	{
		kill(pid, SIGUSR2);
		usleep(80);
		kill(pid, SIGUSR1);
		usleep(80);
		i += 2;
	}
	free(client_bin);
}

// Converts his own PID to binary and sends it to the server
// Converts the message to binary and sends it to the the server
// sends 00000000 after eveything has been sent
// compares the number of chars to the number of server responses
int	main(int argc, char **argv)
{
	int		pid;
	char	*bits;

	if (argc != 3)
	{
		ft_printf("wrong number of arguments\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	bits = ft_to_bit(argv[2], 0, 0);
	if (bits == NULL)
	{
		ft_printf("allocation error\n");
		return (0);
	}
	g_client = ft_strdup("");
	ft_send_pid(pid, 0);
	ft_send_msg(pid, bits);
	ft_send_msg(pid, "00000000");
	if (ft_strlen(argv[2]) == ft_strlen(g_client))
		ft_printf("Message arrived without problems\n");
	else
		ft_printf("Message error!\n");
	free(bits);
	free(g_client);
}
