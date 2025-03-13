/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:01:07 by njung             #+#    #+#             */
/*   Updated: 2025/03/04 15:04:55 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_algo(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return (0);
	if (count_nodes(*stack_a) == 2)
		sort_2(*stack_a);
	else if (count_nodes(*stack_a) == 3)
		sort_3(stack_a);
	else if (count_nodes(*stack_a) == 4)
		sort_4(stack_a, stack_b);
	else if (count_nodes(*stack_a) == 5)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return (1);
}

void	sort_2(t_stack *stack_a)
{
	t_stack	*head;

	head = stack_a;
	if (head->value > stack_a->next->value)
		swap_a(&stack_a);
}

void	sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	if (is_sorted(*stack_a))
		return ;
	min_index = find_min_index(*stack_a);
	if (min_index == 1)
		swap_a(stack_a);
	else if (min_index == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min_index == 3)
		reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	push_min_to_b(stack_a, stack_b);
	push_min_to_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
