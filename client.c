/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:41:59 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/25 18:57:49 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Libft/libft.h"
#include "inc/printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void	send_sig(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("NO connection with server");
		exit(EXIT_FAILURE);
	}
	usleep(100);
}

void	conv_bin(const int pid, char ch, int bite)
{
	while (bite >= 0)
	{
		if (((ch >> bite) & 1) == 1)
			send_sig(pid, SIGUSR1);
		else
			send_sig(pid, SIGUSR2);
		bite--;
		usleep(200);
	}
	ft_printf("\n");
}

int	main(int agc, char **agv)
{
	int	pid;
	int	i;

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
	while (agv[2][++i])
		conv_bin(pid, agv[2][i], 7);
	return (0);
}
