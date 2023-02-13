/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:10:30 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 10:02:08 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!(new))
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	new->index = 0;
	return (new);
}

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

t_node	*insert_node(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = create_node(num);
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
	return (new_node);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node)
	{
		tmp = node;
		node = node->prev;
		free(tmp);
	}
	free(stack);
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
