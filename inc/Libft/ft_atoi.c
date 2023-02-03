/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsebasti <jsebasti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:03:19 by jsebasti          #+#    #+#             */
/*   Updated: 2022/09/25 19:08:07 by jsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	limit(long long n, const char *s, int sign)
{
	long long	limit_min;
	long long	limit_max;

	limit_min = ((n * 10) + (*s - '0')) * sign;
	if (limit_min < -2147483648)
		return (0);
	limit_max = ((n * 10) + (*s - '0')) * sign;
	if (limit_max > 2147483647)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long int	result;
	int			limit_test;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		limit_test = limit(result, str, sign);
		if (limit_test == 0 || limit_test == -1)
			return (limit_test);
		result = ((result * 10) + str[i] - '0');
		i++;
	}
	return (result * sign);
}
