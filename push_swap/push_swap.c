/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaan <kaan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:13:11 by kaan              #+#    #+#             */
/*   Updated: 2024/01/15 14:31:22 by kaan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_start_to_node(t_list *stack, int content)
{
	int		i;

	i = 0;
	while (stack->content != content)
	{
		stack = stack->next;
		i++;
	}
	stack->index = 0;
	return (i);
}

int	index_node_to_last(t_list *stack, int content)
{
	int		i;

	i = index_start_to_node(stack, content);
	i = ft_lstsize(stack) - i;
	return (i);
}

int	index_in_b_start(t_list *stack_b, int push_content)
{
	int		i;

	i = index_start_to_node(stack_b, get_max(&stack_b)->content) + 1;
	return (i);
}

int	index_in_b_to_last(t_list *stack_b, int push_content)
{
	int		i;

	i = index_start_to_node(stack_b, get_max(&stack_b)->content) + 1;
	i = ft_lstsize(stack_b) - i;
	return (i);
}

int	case_ra(t_list **stack_a)
{
	int		i;

	i = index_start_to_node(*stack_a, get_min(stack_a)->content);
	return (i);
}

int	case_rra(t_list **stack_a)
{
	int	i;

	i = index_node_to_last(*stack_a, get_min(stack_a)->content);
	return (i);
}

int	case_rb(t_list **stack_b)
{
	int		i;

	i = index_start_to_node(*stack_b, get_max(stack_b)->content);
	return (i);
}

int	case_rrb(t_list **stack_b)
{
	int	i;

	i = index_node_to_last(*stack_b, get_max(stack_b)->content);
	return (i);
}

void	apply_ra(t_list **stack_a, int ra_i)
{
	while (ra_i != 0)
	{
		ra(stack_a);
		ra_i--;
	}
}

void	apply_rb(t_list **stack_b, t_list **stack_a, int rb_i)
{
	pb(stack_b, stack_a);
	while (rb_i != 0)
	{
		rb(stack_b);
		rb_i--;
	}
}

void	apply_rra(t_list **stack_a, int rra_i)
{
	while (rra_i != 0)
	{
		rra(stack_a);
		rra_i--;
	}
}

void	apply_rrb(t_list **stack_b, t_list **stack_a, int rrb_i)
{
	while (rrb_i != 0)
	{
		rrb(stack_b);
		rrb_i--;
	}
}

void	apply_rb_i(t_list **stack_b, int rb_i)
{
	while (rb_i != 0)
	{
		rb(stack_b);
		rb_i--;
	}
}

void	apply_rrb_i(t_list **stack_b, int rrb_i)
{
	while (rrb_i != 0)
	{
		rrb(stack_b);
		rrb_i--;
	}
}

void	stack_check_a(t_list **stack_a, t_list **stack_b)
{
	int	ra_i;
	int	rra_i;
	int	rb_i;
	int	rrb_i;

	ra_i = case_ra(stack_a);
	rra_i = case_rra(stack_a);
	rb_i = index_in_b_start(*stack_b, (*stack_a)->content);
	rrb_i = index_in_b_to_last(*stack_b, (*stack_a)->content);
	if (ra_i < rra_i && ra_i < rb_i && ra_i < rrb_i)
		apply_ra(stack_a, ra_i);
	else if (rra_i < ra_i && rra_i < rb_i && rra_i < rrb_i)
		apply_rra(stack_a, rra_i);
	else if (rb_i < ra_i && rb_i < rra_i && rb_i < rrb_i)
		apply_rb(stack_b, stack_a, rb_i);
	else if (rrb_i < ra_i && rrb_i < rb_i && rrb_i < rra_i)
		apply_rrb(stack_b, stack_a, rrb_i);
}

void	stack_check_b(t_list **stack_a, t_list **stack_b)
{
	int	rb_i;
	int	rrb_i;

	rb_i = case_rb(stack_b);
	rrb_i = case_rrb(stack_b);
	if (rb_i < rrb_i)
		apply_rb_i(stack_b, rb_i);
	else if (rb_i > rrb_i)
		apply_rrb_i(stack_b, rrb_i);
}

void	push_b_thr_a(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
	{
		stack_check_a(stack_a, stack_b);
		pb(stack_b, stack_a);
	}
	if (order_check(stack_a) == 0)
		sort_thr(stack_a);
	while (ft_lstsize(*stack_b) > 3)
	{
		if (ft_lstsize(*stack_b) == 1)
		{
			pa(stack_a, stack_b);
			*stack_b = NULL;
			break ;
		}
		stack_check_b(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		pb(stack_b, stack_a);
	if (ft_lstsize(*stack_a) > 3 && order_check(stack_a) == 0)
		push_b_thr_a(stack_a, stack_b);
	if (ft_lstsize(*stack_a) == 3)
		sort_thr(stack_a);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;

	stack_a = malloc(sizeof (t_list));
	stack_b = malloc(sizeof (t_list));
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		stacking(&stack_a, ac, av);
	if (order_check(&stack_a) == 0)
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_thr(&stack_a);
		else
		{
			sort_stack(&stack_a, &stack_b);
		}
	}
	else
		ft_printf("numbers are in ascending order");

	ft_printf("size_a:%d\n", ft_lstsize(stack_a));
	ft_printf("size_b:%d\n", ft_lstsize(stack_b));
	ft_printf("a:\t");
	while (stack_a)
	{
		ft_printf("%d\t", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
	if (ft_lstsize(stack_b) != 0)
	{
		ft_printf("b:\t");
		while (stack_b)
		{
			ft_printf("%d\t", stack_b->content);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}
