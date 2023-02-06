/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:37:51 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/05 23:15:15 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_nodo
{
	int				value;
	struct s_nodo	*next;
    struct s_nodo   *prev;

}					t_nodo;

typedef struct s_stack
{
    t_nodo  *top;
    t_nodo  *bottom;
    
}   t_stack;

// stack functions
t_nodo	*create_nodo(int value);
t_stack *create_stack(void);
t_nodo	*insert_node(t_stack *stack, int num);

// movements
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	push(t_stack *x, t_stack *y);


// free functions
void	free_stack(t_stack *stack);
void    free_all(t_stack *a, t_stack *b);





#endif
