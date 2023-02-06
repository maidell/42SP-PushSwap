/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:03 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/06 17:24:33 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nodo(t_nodo *nodo)
{
	if (nodo == NULL)
		return ;
	printf("%d\n", nodo->value);
	print_nodo(nodo->prev);
}

void	fill_stack(int argc, char **argv, t_stack *x)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		insert_node(x, ft_atoi(argv[i]));
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
		
	printf("Antes das operações\n");
	print_nodo(a->top);
	sort_two(a);
	printf("Depois das operações\n");
	print_nodo(a->top);

	free_all(a, b);
	return (0);
}
