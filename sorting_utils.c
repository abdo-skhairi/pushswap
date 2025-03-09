/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:58:30 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 15:02:47 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_stack **a)
{
	if (!a)
		return ;
	if (is_higher((*a)->value, *a))
		ra(a);
	else if (is_higher((*a)->next->value, *a))
		rra(a);
	if (is_sorted(*a) == 0)
		sa(a);
}

void	sort_5(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		set_all_nodes(*a, *b);
		finish_rotation(a, find_smallest_node(*a), 'a');
		pb(a, b);
	}
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rr(a, b);
	set_index_position(*a);
	set_index_position(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b);
	set_index_position(*a);
	set_index_position(*b);
}
