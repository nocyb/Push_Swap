/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:11:48 by njung             #+#    #+#             */
/*   Updated: 2025/03/04 15:00:07 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// check_utils
void	check_input(int argc, char **argv);

// random_utils
char	**ft_free(char **s);
void	insert_value(t_stack **head, int new_value);
t_stack	*create_new_node(int new_value);
int		count_nodes(t_stack *head);
void	ft_error(void);

// random utils 2
int		find_min_index(t_stack *stack);
void	move_min_to_top(t_stack **stack, int min_index);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
long	ft_atoi_long(const char *str);

// random utils 3
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);

// push utils
void	push(t_stack **stack_src, t_stack **stack_dest);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

// swap utils
void	swap(t_stack **head);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);

// rotate utils
void	rotate(t_stack **head);
void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);

// r rotate utils
void	reverse_rotate(t_stack **head);
void	reverse_rotate_a(t_stack **head);
void	reverse_rotate_b(t_stack **head);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// initialize
void	set_order(t_stack *head, int link_size);
t_stack	*init_list(int argc, char **argv);

//algorithm ( TO FILL )
int		search_algo(t_stack **stack_a, t_stack **stack_b);
void	sort_2(t_stack *stack_a);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_3(t_stack **stack_a);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

// radix_sort
void	set_index(t_stack *stack_a, int size);
void	set_index_part(t_stack *stack, int min, int i);
void	radix_sort_part(t_stack **a, t_stack **b, int size, int bit_pos);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

#endif