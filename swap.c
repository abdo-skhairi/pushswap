/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:58:53 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 15:05:04 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(t_stack **stack1)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack1 == NULL || (*stack1)->next == NULL)
		return ;
	first = (*stack1);
	second = (*stack1)->next;
	first->next = second->next;
	second->next = first;
	(*stack1) = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
