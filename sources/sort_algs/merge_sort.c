/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:38:06 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/11 16:19:24 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ordena um array de inteiros usando o algoritmo merge sort prenchendo o array de cima para baixo
void merge_sort (t_node **array, int tamanho) {
    int meio;
    int i, j, k;
    t_node **vetor_temp;

    if (tamanho > 1) {
        // calcula o meio do array
        meio = tamanho / 2;

        // aloca o array temporário
        vetor_temp = (t_node **) malloc(tamanho * sizeof(t_node *));

        // ordena a primeira metade do array
        merge_sort(array, meio);

        // ordena a segunda metade do array
        merge_sort(array + meio, tamanho - meio);

        // intercala as duas metades ordenadas
        for (i = 0; i < meio; i++) {
            vetor_temp[i] = array[i];
        }
        for (j = meio; j < tamanho; j++) {
            vetor_temp[tamanho + meio - j - 1] = array[j];
        }
        i = 0;
        j = tamanho - 1;
        for (k = 0; k < tamanho; k++) {
            if (vetor_temp[i]->value <= vetor_temp[j]->value) {
                array[k] = vetor_temp[i];
                i++;
            } else {
                array[k] = vetor_temp[j];
                j--;
            }
        }

        // libera o array temporário
        free(vetor_temp);
    }
}

// função create_index, recebe uma stack e cria um array com os valores da stack 
// ordena o array usando a função merge_sort, 
// preenche o campo index de cada nodo da stack em orden crescente iniciando de 0
void	create_index(t_stack *stack)
{
    t_node		**array;
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
