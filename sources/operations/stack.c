/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:10:30 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 11:41:21 by mmaidel-         ###   ########.fr       */
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

void	fill_stack(int argc, char **argv, t_stack *stack)
{
	int	i;

	stack->size = argc - 1;
	i = argc - 1;
	while (i > 0)
	{
		insert_node(stack, ft_atoi(argv[i]));
		i--;
	}
}
