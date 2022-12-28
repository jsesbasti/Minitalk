/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:41:59 by jsebasti          #+#    #+#             */
/*   Updated: 2022/12/28 10:16:08 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	showpid(void)
{
	pid_t	pid;
	
	pid = getpid();
	ft_printf("PID = %i", pid);
	return (1);
}

int	main(void)
{
	return (showpid());
}
