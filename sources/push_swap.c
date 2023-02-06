/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:03 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/06 01:34:25 by mmaidel-         ###   ########.fr       */
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

void fill_stack(int argc, char **argv, t_stack *x)
{
    int i = argc - 1;
    while (i > 0)
    {
        insert_node(x, ft_atoi(argv[i]));
        i--;
    }
}

int	main(int argc, char **argv)
{
	t_stack *a = create_stack();
    t_stack *b = create_stack();
    
    fill_stack(argc, argv, a);
   
    // swap(a);
    // pa(a, b);
   // printf("O topo da stack a é: %d\n", a->top->value);
    //printf("O topo da stack b é: %d\n", b->top->value);
    //p
    push(a, b);
    //printf("Depos de push\n");
   //printf("O topo da stack a é: %d\n", a->top->value);
    //printf("O topo da stack b é: %d\n", b->bottom->value);
   // printf("O topo da stack a é:%d\n", a->top->value);
    print_nodo(a->top);
    //print_nodo(b->top);
    free_all(a, b);
    
    return (0);
        
}
