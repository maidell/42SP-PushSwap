/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:21:52 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 11:03:54 by mmaidel-         ###   ########.fr       */
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
		if (stack_a->top->index == 2 && stack_a->bottom->index == 0)
		{
			ra(stack_a);
			sort_two(stack_a);
		}
		else if (stack_a->top->index == 1 && stack_a->bottom->index == 0)
		{
			ra(stack_a);
			ra(stack_a);
		}
		else if (stack_a->top->index == 1 && stack_a->bottom->index == 2)
			sa(stack_a);
		else if (stack_a->top->index == 0 && stack_a->bottom->index == 2)
		{
			return ;
		}
		else if (stack_a->top->index == 0 && stack_a->bottom->index == 1)
		{
			rra(stack_a);
			sort_two(stack_a);
		}
		else if (stack_a->top->index == 2 && stack_a->bottom->index == 1)
			ra(stack_a);
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
		else if (stack_a->bottom->index == 3)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_three(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_a->bottom->next->index == 3)
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
		else if (stack_a->bottom->index == 4)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_four(stack_a, stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_a->bottom->next->index == 4)
		{
			rra(stack_a);
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_four(stack_a, stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_a->bottom->next->next->index == 4)
		{
			rra(stack_a);
			rra(stack_a);
			rra(stack_a);
			pb(stack_a, stack_b);
			sort_four(stack_a, stack_b);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_a->top->prev->index == 4)
		{
			utils_sort_five(stack_a, stack_b);
		}
		else if (stack_a->top->prev->prev->index == 4)
		{
			utils_sort_five(stack_a, stack_b);
		}
		else if (stack_a->top->prev->prev->prev->index == 4)
		{
			utils_sort_five(stack_a, stack_b);
		}
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
	else if (stack_a->top->prev->prev->prev->index == 4)
	{
		ra(stack_a);
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
