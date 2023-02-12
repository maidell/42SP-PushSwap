/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:06 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/12 00:06:34 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ordena um array de inteiros usando o algoritmo merge sort prenchendo o array de cima para baixo
void	merge_sort(t_node **array, int size)
{
	int		half;
	t_node	**array_tmp;

	int i, j, k;
	if (size > 1)
	{
		// calcula o half do array
		half = size / 2;
		// aloca o array temporário
		array_tmp = (t_node **)malloc(size * sizeof(t_node *));
		// ordena a primeira metade do array
		merge_sort(array, half);
		// ordena a segunda metade do array
		merge_sort(array + half, size - half);
		// intercala as duas metades ordenadas
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
		// libera o array temporário
		free(array_tmp);
	}
}

// função create_index, recebe uma stack e cria um array com os valores da stack
// ordena o array usando a função merge_sort,
// preenche o campo index de cada nodo da stack em orden crescente iniciando de 0
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
