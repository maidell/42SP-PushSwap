/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:03 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 17:31:20 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	check_err(argc, argv);
	insufficient_args(argc);
	a = create_stack();
	b = create_stack();
	fill_stack(argc, argv, a);
	create_index(a);
	sort_all(a, b);
	free_all(a, b);
	return (0);
}
