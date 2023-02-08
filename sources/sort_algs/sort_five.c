/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:21:52 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/08 13:29:23 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	sa(stack);
}

void	sort_three(t_stack *stack)
{
	// se max_value for o topo
	if (stack->top->value == max_value(stack))
	{
		ra(stack);
		sort_two(stack);
	}
	// se max_value for o bottom
	else if (stack->bottom->value == max_value(stack))
		sort_two(stack);
	// se min_value for o bottom, faço rra
	else if (stack->bottom->value == min_value(stack))
	{
		rra(stack);
	}
	//se min_value for o bottom e max_value for o topo
	else if (!(stack->bottom->value == min_value(stack)
				&& stack->top->value == max_value(stack)))
	{
		rra(stack);
		sort_two(stack);
	}
}

int 	sort_five(t_stack *stack)
{
	int		i;
	int		j;
	int		min;
	int		max;
	t_stack	*stack_b;

	i = 0;
	j = 0;
	stack_b = create_stack();
	while (i < 2)
	{
		min = min_value(stack);
		max = max_value(stack);
		if (stack->top->value == min || stack->top->value == max)
		{
			pb(stack, stack_b);
			i++;
		}
		else
		{
			ra(stack);
			j++;
		}
	}
	sort_three(stack);
	while (j > 0)
	{
		rra(stack);
		j--;
	}
	pa(stack, stack_b);
	pa(stack, stack_b);
	return (1);
}
