/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:27:33 by njung             #+#    #+#             */
/*   Updated: 2025/03/04 15:19:52 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*start;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	start = *head;
	while (start->next != NULL)
		start = start->next;
	start->next = *head;
	*head = (*head)->next;
	start->next->next = NULL;
}

void	rotate_a(t_stack **head)
{
	rotate(head);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **head)
{
	rotate(head);
	ft_printf("rb\n");
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
