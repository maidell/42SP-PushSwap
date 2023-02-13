/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_less_than_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:24:17 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 11:31:14 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	utils_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->bottom->next->index == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_a->top->prev->index == 3)
	{
		ra(stack_a);
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
}

void	utils_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->prev->index == 4)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_a->top->prev->prev->index == 4)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_a->bottom->next->index == 4)
	{
		update_five_sorts(stack_a, stack_b);
	}
}

void	update_five_sorts(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->bottom->next->index == 4)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
	else if (stack_a->bottom->index == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
