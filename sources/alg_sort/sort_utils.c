/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:13:11 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/06 16:36:14 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(t_stack *stack)
{
	int		max;
	t_nodo	*tmp;

	max = MAX_INT;
	max = stack->top->value;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->prev;
	}
	return (max);
}

// the function return the min value of the stack
int	min_value(t_stack *stack)
{
	int min;
	min = MIN_INT;
	t_nodo *tmp;

	min = stack->top->value;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->prev;
	}
	return (min);
}