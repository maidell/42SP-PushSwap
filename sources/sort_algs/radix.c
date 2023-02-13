/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:32:10 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:32:39 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n >> 1;
		i++;
	}
	return (i);
}

int	get_bit(int n, int i)
{
	return ((n >> i) & 1);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	if (check_sort_stack(stack_a) == 0)
	{
		while (i < count_bits(stack_a->size))
		{
			j = 0;
			while (j < stack_a->size)
			{
				if (get_bit(stack_a->top->index, i) == 1)
					ra(stack_a);
				else
					pb(stack_a, stack_b);
				j++;
			}
			while (!(stack_b->top == NULL))
			{
				pa(stack_a, stack_b);
			}
			i++;
		}
	}
}
