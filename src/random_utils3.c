/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:48:12 by njung             #+#    #+#             */
/*   Updated: 2025/03/04 15:19:17 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;
	int	stack_size;

	min_index = find_min_index(*stack_a);
	stack_size = count_nodes(*stack_a);
	if (min_index <= stack_size / 2)
	{
		while (min_index > 0)
		{
			rotate_a(stack_a);
			min_index--;
		}
	}
	else
	{
		while (min_index < stack_size)
		{
			reverse_rotate_a(stack_a);
			min_index++;
		}
	}
	push_b(stack_a, stack_b);
}
