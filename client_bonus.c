/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:45:54 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/24 21:34:16 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Libft/libft.h"
#include "inc/printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int	g_recived;

void	handler(int sig)
{
	if (sig <= 0)
	{
		ft_printf("Error");
		exit(EXIT_FAILURE);
	}
	if (sig == SIGUSR1)
	{
		ft_printf("Signal recived");
		usleep(100);
		g_recived++;
	}
}

void	send_sig(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("NO connection with server");
		exit(EXIT_FAILURE);
	}
	usleep(200);
}

int	conv_bin(const int pid, char ch, int bite)
{
	int	send;

	send = 0;
	ft_printf("'%c' \u2911  ", ch);
	while (bite >= 0)
	{
		if (((ch >> bite) & 1) == 1)
		{
			ft_printf("1");
			send_sig(pid, SIGUSR1);
			send++;
		}
		else
		{
			ft_printf("0");
			send_sig(pid, SIGUSR2);
			send++;
		}
		bite--;
		usleep(300);
	}
	ft_printf("\n");
	return (send);
}

int	main(int agc, char **agv)
{
	int	send;
	int	pid;
	int	i;

	g_recived = 0;
	send = 0;
	i = -1;
	if (agc <= 2 || agc >= 4)
	{
		if (agc <= 2)
			ft_printf("Too few arguments");
		if (agc >= 4)
			ft_printf("Too many arguments");
		return (-1);
	}
	pid = ft_atoi(agv[1]);
	handler(pid);
	signal(SIGUSR1, handler);
	while (agv[2][++i])
		send += conv_bin(pid, agv[2][i], 7);
	return (0);
}
