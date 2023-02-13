/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:55:29 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:31:44 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top == stack->bottom)
		return ;
	tmp = stack->top->prev;
	stack->top->prev = tmp->prev;
	stack->top->next = tmp;
	tmp->prev = stack->top;
	tmp->next = NULL;
	stack->top = tmp;
	if (stack->top->prev == NULL)
		stack->bottom = stack->top->next;
}
