/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:55:26 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 10:01:48 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp;

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

void	ra(t_stack *a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_stack *b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
