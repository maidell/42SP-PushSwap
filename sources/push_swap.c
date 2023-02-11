/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:03 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/11 17:28:02 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_node(t_node *node)
{
	if (node == NULL)
		return ;
	printf("%d (%d)\n", node->value,node->index);
	print_node(node->prev);
}

void	fill_stack(int argc, char **argv, t_stack *stack)
{
	int	i;
	stack->size = argc - 1;
	
	i = argc - 1;
	//i = 1;
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
	check_sort(argc, argv);
	
	//printa a stack a preenchida:
		//printf("Stack A\n");
		//print_node(a->top);
	
	//chama a função create_index
	create_index(a);
		//printf("Stack A com indices\n");
		//print_node(a->top);
	sort_all(a, b);
	
	//printa a stack a preenchida com os indices:
		//printf("Stack A ordenada\n");
		//	print_node(a->top);

	
	free_all(a, b);
	return (0);
}

