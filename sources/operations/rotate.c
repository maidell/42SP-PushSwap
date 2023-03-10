/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:55:26 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/09 02:35:11 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node *tmp;

	if (stack->top == stack->bottom)
		return ;
	tmp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	tmp->prev = NULL;
	tmp->next = stack->bottom;
	stack->bottom->prev = tmp;
	stack->bottom = tmp;
}
