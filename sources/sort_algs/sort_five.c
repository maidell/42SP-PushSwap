/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:21:52 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 10:11:54 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (check_sort_stack(stack_a) == 0)
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	if (check_sort_stack(stack_a) == 0)
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
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sort_stack(stack_a) == 0)
	{
		if (stack_a->top->index == 3)
		{
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if (stack_a->bottom->index == 3)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if (stack_a->bottom->next->index == 3)
		{
			rra(stack_a);
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if (stack_a->top->prev->index == 3)
		{
			ra(stack_a);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		if (stack_a->bottom->index == 2)
		{
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
		}
		if (stack_a->top->index == 2)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
		}
		if (stack_a->bottom->index == 1)
		{
			ra(stack_a);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			rra(stack_a);
		}
		if (stack_a->top->index == 1)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sort_stack(stack_a) == 0)
	{
		if (stack_a->top->index == 4)
		{
			pb(stack_a, stack_b);
			sort_four(stack_a, stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_a->bottom->next->index == 4)
		{
			rra(stack_a);
			rra(stack_a);
			sort_five(stack_a, stack_b);
		}
		else if (stack_a->bottom->index == 4)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_four(stack_a, stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_a->top->prev->index == 4)
		{
			ra(stack_a);
			pb(stack_a, stack_b);
			sort_four(stack_a, stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_a->bottom->next->next->index == 4)
		{
			ra(stack_a);
			ra(stack_a);
			sort_five(stack_a, stack_b);
		}
	}
}
