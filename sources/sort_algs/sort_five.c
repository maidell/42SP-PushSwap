/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:21:52 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/11 17:16:29 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	if (stack_a->bottom->index == 0 && stack_a->top->index == 2)
	{
		ra(stack_a);
		sort_two(stack_a);
	}
	else if (stack_a->bottom->index == 1 && stack_a->top->index == 2)
	{
		ra(stack_a);
	}
	else if (stack_a->bottom->index == 0 && stack_a->top->index == 1)
	{
		rra(stack_a);
	}
	else if (stack_a->bottom->index == 2 && stack_a->top->index == 1)
	{
		sort_two(stack_a);
	}
	else if (stack_a->bottom->index == 1 && stack_a->top->index == 0)
	{
		sort_two(stack_a);
		ra(stack_a);
	}
}

void	sort_four(t_stack *stack_a,t_stack *stack_b)
{
	if (stack_a->top->index == 3)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_a->bottom->index == 3)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_a->bottom->index == 2)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (stack_a->top->index == 2)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
	else if (stack_a->bottom->index == 1)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		rra(stack_a);
	}
	else if (stack_a->top->index == 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	
	
	
}
void	sort_less_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	//else if (stack->size == 5)
	//	sort_five(stack);
}

void	sort_all(t_stack *stack_a, t_stack *stack_b)
{
	// t_stack *temp_stack;
	//temp_stack = sort_stack_copy(stack);
	if (stack_a->size <= 5)
		sort_less_five(stack_a, stack_b);
	//else
	//radix_sort(stack);
}
