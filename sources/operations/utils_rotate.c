/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:12 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:37:02 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	reverse_rotate(t_stack *stack)
{
	t_node	*tmp;

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
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
