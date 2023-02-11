/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:55:23 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/09 02:35:11 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Moves the top of stack x to the top of stack y
void	push(t_stack *x, t_stack *y)
{
	t_node *tmp;

	if (x->top == NULL)
		return ;
	tmp = x->top;
	x->top = x->top->prev;
	if (x->top != NULL)
		x->top->next = NULL;
	else
		x->bottom = NULL;
	tmp->prev = y->top;
	tmp->next = NULL;
	y->top = tmp;
	if (y->top->prev != NULL)
		y->top->prev->next = y->top;
	else
		y->bottom = y->top;
}