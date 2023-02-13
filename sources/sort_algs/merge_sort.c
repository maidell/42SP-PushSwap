/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:06 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:32:27 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_node **array, int size)
{
	int		half;
	t_node	**array_tmp;

	int i, j, k;
	if (size > 1)
	{
		half = size / 2;
		array_tmp = (t_node **)malloc(size * sizeof(t_node *));
		merge_sort(array, half);
		merge_sort(array + half, size - half);
		i = 0;
		while (i < half)
		{
			array_tmp[i] = array[i];
			i++;
		}
		j = half;
		while (j < size)
		{
			array_tmp[size + half - j - 1] = array[j];
			j++;
		}
		i = 0;
		j = size - 1;
		k = 0;
		while (k < size)
		{
			if (array_tmp[i]->value <= array_tmp[j]->value)
			{
				array[k] = array_tmp[i];
				i++;
			}
			else
			{
				array[k] = array_tmp[j];
				j--;
			}
			k++;
		}
		free(array_tmp);
	}
}

void	create_index(t_stack *stack)
{
	t_node	**array;
	int		i;
	t_node	*node;

	array = (t_node **)malloc(sizeof(t_node *) * stack->size);
	node = stack->bottom;
	i = 0;
	while (node)
	{
		array[i] = node;
		node = node->next;
		i++;
	}
	merge_sort(array, stack->size);
	node = stack->bottom;
	i = 0;
	while (i < stack->size)
	{
		array[i]->index = i;
		i++;
	}
	free(array);
}
