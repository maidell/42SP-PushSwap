/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaidel- <mmaidel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:37:51 by mmaidel-          #+#    #+#             */
/*   Updated: 2023/02/13 11:55:01 by mmaidel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;

}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;

}					t_stack;

// stack functions
t_node				*create_node(int value);
t_stack				*create_stack(void);
t_node				*insert_node(t_stack *stack, int num);
void				fill_stack(int argc, char **argv, t_stack *stack);

// free functions
void				free_all(t_stack *a, t_stack *b);

// handle errors
void				error_message(void);
int					has_duplicates(int argc, char *argv[]);
int					limits_int(char *str);
int					not_digit(char *str);
int					invalid_number(char *argv[]);
void				check_err(int argc, char *argv[]);

// checkers
void				insufficient_args(int argc);
int					check_sort_stack(t_stack *stack);
void				is_input_sort(int argc, char *argv[]);

// movements
void				swap(t_stack *stack);
void				rotate(t_stack *stack);
void				push(t_stack *x, t_stack *y);

// operations functions
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				reverse_rotate(t_stack *stack);

// sort less than six functions
void				sort_two(t_stack *stack);
void				sort_three(t_stack *stack_a);
void				sort_four(t_stack *stack_a, t_stack *stack_b);
void				sort_five(t_stack *stack_a, t_stack *stack_b);
void				utils_sort_four(t_stack *stack_a, t_stack *stack_b);
void				utils_sort_five(t_stack *stack_a, t_stack *stack_b);
void				update_five_sorts(t_stack *stack_a, t_stack *stack_b);

// handle index
void				create_index(t_stack *stack);

// utils sort functions
int					is_sorted(t_node **node);

// sort_algs
void				sort_less_five(t_stack *stack_a, t_stack *stack_b);
void				sort_all(t_stack *stack_a, t_stack *stack_b);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);
void				bubble_sort(t_node **array, int tamanho);

#endif
