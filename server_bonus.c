/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:17:49 by jsebasti          #+#    #+#             */
/*   Updated: 2023/01/24 21:24:03 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Libft/libft.h"
#include "inc/printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

void	handler(int sig, siginfo_t *info, void *data)
{
	static int				bite = 0;
	static unsigned char	ch = '\0';

	(void) data;
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_printf("NO se ha podido establecer la conexion");
	ch <<= 1;
	if (sig == SIGUSR1)
		ch |= 1;
	bite++;
	if (bite == 8)
	{
		if ((int)ch <= 126)
			ft_printf("%c", ch);
		else if ((int)ch >= 127)
			ft_printf("%c", ch);
		bite = 0;
		ch = '\0';
	}
}

void	confirm(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		ft_printf("NO PID");
	else
		ft_printf("Server PID: %i\n", getpid());
	confirm();
	while (1)
		sleep(1);
	return (0);
}
