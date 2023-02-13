/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:07:59 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:30:52 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_input_sort(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return ;
		i++;
	}
	exit(1);
}

void	insufficient_args(int argc)
{
	if (argc <= 2)
	{
		exit(0);
	}
}

int	check_sort_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while (node->prev)
	{
		if (node->value > node->prev->value)
			return (0);
		node = node->prev;
	}
	return (1);
}
