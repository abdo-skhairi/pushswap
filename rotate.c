/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:59:18 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 00:59:23 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	rotate(stack **stack1)
{
	stack	*temp1;
	stack	*temp2;

	if (!(*stack1) || !((*stack1)->next))
		return ;
	temp1 = *stack1;
	while ((*stack1)->next)
		*stack1 = (*stack1)->next;
	temp2 = *stack1;
	*stack1 = temp1->next;
	temp2->next = temp1;
	temp1->next = NULL;
}

void	ra(stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(stack	**stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(stack **stack_a, stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
