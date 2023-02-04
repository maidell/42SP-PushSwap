/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:03 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/04 20:05:48 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_nodo(t_nodo *nodo)
{
    if (nodo == NULL)
        return;
    printf("%d\n", nodo->value);
    print_nodo(nodo->prev);
    
}

int	main(void)
{
	t_stack *nova = create_stack();

	int n;
	printf("Digite um numero: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("Digite um numero: ");
		int x;
		scanf("%d", &x);
		insert_node(nova, x);
	}
   print_nodo(nova->top);
        
}
