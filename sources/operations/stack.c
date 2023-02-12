/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:10:30 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/11 22:46:07 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cria nodo com valor apontando NULL
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

t_node	*insert_node(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = create_node(num);
	if (stack->bottom == NULL && stack->top == NULL)
	{
		stack->bottom = new_node;
		stack->top = new_node;
		//new_node->index = 0;
	}
	else
	{
		new_node->prev = stack->top;
		stack->top->next = new_node;
		stack->top = new_node;
		//new_node->index = new_node->prev->index + 1;
	}

	return (new_node);
}

// função que recebe uma stack e da free em todos os nodos iniciando do topo, depois da free no topo e no bottom da stack
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

// free all
void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}