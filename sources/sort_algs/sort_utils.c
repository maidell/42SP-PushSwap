/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:13:11 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/11 22:01:06 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// max_index retorna o indice do maior valor da stack
int max_index(t_stack *stack)
{
    int max;
    int index;
    int i;
    t_node *node;

    max = stack->top->value;
    index = 0;
    i = 0;
    node = stack->top;
    while (node)
    {
        if (node->value > max)
        {
            max = node->value;
            index = i;
        }
        node = node->next;
        i++;
    }
    return (index);
}

// min_index retorna o indice do menor valor da stack   
int min_index(t_stack *stack)
{
    int min;
    int index;
    int i;
    t_node *node;

    min = stack->top->value;
    index = 0;
    i = 0;
    node = stack->top;
    while (node)
    {
        if (node->value < min)
        {
            min = node->value;
            index = i;
        }
        node = node->next;
        i++;
    }
    return (index);
}

// verifica se a stack está ordenada
int	is_sorted(t_node **node)
{
	t_node		*temp;

	temp = *node;
	while (temp)
	{
		if (!temp->next)
			return (1);
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
