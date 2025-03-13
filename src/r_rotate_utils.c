/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 19:22:42 by njung             #+#    #+#             */
/*   Updated: 2025/03/04 15:11:10 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*last;
	t_stack	*before_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	before_last = NULL;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	if (before_last)
		before_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	reverse_rotate_a(t_stack **head)
{
	reverse_rotate(head);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **head)
{
	reverse_rotate(head);
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
