/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:59:03 by njung             #+#    #+#             */
/*   Updated: 2025/03/04 15:12:36 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index_part(t_stack *stack, int min, int i)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->value == min && temp->index == -1)
		{
			temp->index = i;
			break ;
		}
		temp = temp->next;
	}
}

void	set_index(t_stack *stack_a, int size)
{
	t_stack	*current;
	int		min;
	int		i;

	i = 0;
	while (i < size)
	{
		min = INT_MAX;
		current = stack_a;
		while (current)
		{
			if (current->value < min && current->index == -1)
				min = current->value;
			current = current->next;
		}
		set_index_part(stack_a, min, i);
		i++;
	}
}

void	radix_sort_part(t_stack **a, t_stack **b, int size, int bit_pos)
{
	int		j;

	j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit_pos) & 1)
			rotate_a(a);
		else
			push_b(a, b);
		j++;
	}
	while (*b)
		push_a(a, b);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		max_bits;
	int		i;

	if (!*stack_a || !stack_b)
		return ;
	if (is_sorted(*stack_a))
		return ;
	size = count_nodes(*stack_a);
	set_index(*stack_a, size);
	max_bits = 0;
	i = size - 1;
	while ((i >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		radix_sort_part(stack_a, stack_b, size, i);
		i++;
	}
}
