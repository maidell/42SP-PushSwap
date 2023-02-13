/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:03 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 09:34:29 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	if (node == NULL)
		return ;
	ft_printf("%d (%d)\n", node->value, node->index);
	print_node(node->prev);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	check_err(argc, argv);
	insufficient_args(argc);
	a = create_stack();
	b = create_stack();
	fill_stack(argc, argv, a);
	is_input_sort(argc, argv);
	create_index(a);
	sort_all(a, b);
	free_all(a, b);
	return (0);
}
