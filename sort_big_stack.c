/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:59:01 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 00:59:03 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	finish_rotation(stack **current_stack,
						stack *cheapest_node, char stack_name)
{
	while (*current_stack != cheapest_node)
	{
		if (stack_name == 'a')
		{
			if (cheapest_node->is_in_first_half)
				ra(current_stack);
			else
				rra(current_stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest_node->is_in_first_half)
				rb(current_stack);
			else
				rrb(current_stack);
		}
	}
}

void	moves(stack **a, stack **b)
{
	stack	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->is_in_first_half
		&& cheapest_node->target_node->is_in_first_half)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->is_in_first_half)
		&& !(cheapest_node->target_node->is_in_first_half))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b);
}

void	set_and_move(stack **a, stack **b)
{
	while (*b)
	{
		set_all_nodes(*a, *b);
		moves(a, b);
	}
}

void	sort_all_moves(stack **a, stack **b)
{
	stack	*small_node;

	if (stack_size(*a) == 5)
		sort_5(a, b);
	if ((stack_size(*a) > 3))
	{
		while (stack_size(*a) > 3)
			pb(a, b);
	}
	sort_3(a);
	set_and_move(a, b);
	set_index_position(*a);
	small_node = find_smallest_node(*a);
	if (small_node->is_in_first_half)
	{
		while (*a != small_node)
			ra(a);
	}
	else
	{
		while (*a != small_node)
			rra(a);
	}
}
