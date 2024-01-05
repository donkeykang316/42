/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.de>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/05 13:48:50 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_node(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 2)
	{
		push(stack_b, stack_a);
		push(stack_b, stack_a);
		ft_printf("%d\n", ft_lstsize(*stack_a));
		ft_printf("%d\n", ft_lstsize(*stack_b));
	}
	else
		ft_printf("just swap\n");
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = malloc(sizeof (t_list));
	stack_b = malloc(sizeof (t_list));
	stack_a = NULL;
	stack_b = NULL;
	stacking(&stack_a, ac, av);
	if (order_check(&stack_a) == 0)
	{
		target_node(&stack_a, &stack_b);
	}
	else
		ft_printf("numbers are in ascending order");
}
