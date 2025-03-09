/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:59:24 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 15:00:31 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rev_rotate(t_stack **stack1)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*last;

	if (!(*stack1) || !((*stack1)->next))
		return ;
	temp1 = *stack1;
	temp2 = *stack1;
	while (temp2->next->next != NULL)
	{
		temp2 = temp2->next;
	}
	last = temp2->next;
	temp2->next = NULL;
	last->next = temp1;
	*stack1 = last;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
