/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2023/12/24 15:51:45 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	t_stack		*a;
	t_stack		*b;

	i = 1;
	a = NULL;
	(void)b;
	if (ac >= 2)
	{
		while (av[i])
		{
			a = malloc(sizeof(t_stack));
			if (!a)
				return (0);
			a->n = ft_atoi(av[i]);
			ft_printf("%d\n", a->n);
			free(a);
			i++;
		}
	}
}
