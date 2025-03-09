/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:59:51 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 14:59:37 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (!stack1 || !(*stack1))
		return ;
	tmp = (*stack1);
	*stack1 = (*stack1)->next;
	tmp->next = (*stack2);
	(*stack2) = tmp;
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
