/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:12 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/06 17:35:46 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
}

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	t_nodo	*tmp;

	if (stack->top == stack->bottom)
		return ;
	tmp = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	tmp->next = NULL;
	tmp->prev = stack->top;
	stack->top->next = tmp;
	stack->top = tmp;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
