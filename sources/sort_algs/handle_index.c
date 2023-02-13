/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:24:46 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 10:04:59 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_index(t_stack *stack)
{
	t_node	**array;
	t_node	*node;
	int		i;

	array = (t_node **)malloc(sizeof(t_node *) * stack->size);
	node = stack->bottom;
	i = 0;
	while (node)
	{
		array[i] = node;
		node = node->next;
		i++;
	}
	bubble_sort(array, stack->size);
	node = stack->bottom;
	i = 0;
	while (i < stack->size)
	{
		array[i]->index = i;
		i++;
	}
	free(array);
}
