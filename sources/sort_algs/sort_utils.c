/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:13:11 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:33:49 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_less_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}

void	sort_all(t_stack *stack_a, t_stack *stack_b)
{
	// t_stack *temp_stack;
	//temp_stack = sort_stack_copy(stack);
	if (stack_a->size <= 5)
		sort_less_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}
