/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:00:19 by kaan              #+#    #+#             */
/*   Updated: 2023/11/21 14:54:14 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	m;

	n = 1;
	m = 0;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == 32)
	{
		nptr++;
	}
	if (*nptr == '+')
	{
		n = +n;
		nptr++;
	}
	else if (*nptr == '-')
	{
		n = -n;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		m = (m * 10) + (*nptr - 48);
		nptr++;
	}
	return (n * m);
}
