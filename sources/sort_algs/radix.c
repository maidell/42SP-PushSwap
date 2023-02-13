/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:32:10 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 07:23:26 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//count how many bits are needed to represent the biggest number
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

// bitwise shift_right and iterator
// basicamente desloca i casa binarias pra direita
// então "cria" uma linha e compara as portas
// logicas, se o resultado do if for 1
// permanece na stack a se não "pb"

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
