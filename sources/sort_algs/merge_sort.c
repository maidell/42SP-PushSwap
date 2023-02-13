/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:06 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:40:54 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort(t_node **array, int size)
{
	int		half;
	t_node	**array_tmp;
	int		i;
	int		j;
	int		k;

	if (size > 1)
	{
		half = size / 2;
		array_tmp = (t_node **)malloc(size * sizeof(t_node *));
		merge_sort(array, half);
		merge_sort(array + half, size - half);
		i = 0;
		j = half;
		k = 0;
		while (i < half && j < size)
			array_tmp[k++] = array[i]->value <= array[j]->value ? array[i++] : array[j++];
		while (i < half)
			array_tmp[k++] = array[i++];
		while (j < size)
			array_tmp[k++] = array[j++];
		for (i = 0; i < size; i++)
			array[i] = array_tmp[i];
		free(array_tmp);
	}
}
