/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:10:30 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/05 22:57:25 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cria nodo com valor apontando NULL 
t_nodo	*create_nodo(int value)
{
	t_nodo	*new;

	new = (t_nodo *)malloc(sizeof(t_nodo));
	if (!(new))
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// cria stack vazia
t_stack	*create_stack(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!(new))
		return (NULL);
	new->top = NULL;
	new->bottom = NULL;
	return (new);
}

t_nodo	*insert_node(t_stack *stack, int num)
{
	t_nodo *new_node;
	new_node = create_nodo(num);
	if (stack->bottom == NULL && stack->top == NULL)
	{
		stack->bottom = new_node;
		stack->top = new_node;
	}
	else
	{
		new_node->prev = stack->top;
		stack->top->next = new_node;
		stack->top = new_node;
	}
    return new_node;
}

void	free_stack(t_stack *stack)
{
    t_nodo *tmp;

    while (stack->bottom)
    {
        tmp = stack->bottom;
        stack->bottom = stack->bottom->next;
        free(tmp);
    }
    free(stack);
}
 
void free_all(t_stack *a, t_stack *b)
{
    free_stack(a);
    free_stack(b);
}