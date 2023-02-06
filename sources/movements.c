/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:06:12 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/06 01:14:47 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_pa (int *op, t_stack *a, t_stack *b)
{
    *op += 1;
    push(a, b);
}

void op_pb (int *op, t_stack *a, t_stack *b)
{
    *op += 1;
    push(b, a);
}

void op_sa (int *op, t_stack *a)
{
    *op += 1;
    swap(a);
}

void op_sb (int *op, t_stack *b)
{
    *op += 1;
    swap(b);
}

void op_ss (int *op, t_stack *a, t_stack *b)
{
    *op += 1;
    swap(a);
    swap(b);
}

void op_ra (int *op, t_stack *a)
{
    *op += 1;
    rotate(a);
}

void op_rb (int *op,t_stack *b)
{
    *op += 1;
    rotate(b);
}

void op_rr (int *op, t_stack *a, t_stack *b)
{
    *op += 1;
    rotate(a);
    rotate(b);
}

void reverse_rotate(t_stack *stack)
{
    t_nodo *tmp;

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

void op_rra (int *op, t_stack *a)
{
    *op += 1;
    reverse_rotate(a);
}

void op_rrb (int *op, t_stack *b)
{
    *op += 1;
    reverse_rotate(b);
}

void op_rrr (int *op, t_stack *a, t_stack *b)
{
    *op += 1;
    reverse_rotate(a);
    reverse_rotate(b);
}
