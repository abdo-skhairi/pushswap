/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:00:21 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 14:48:58 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_duplicate(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (a == NULL || *a == NULL)
		return (0);
	first = *a;
	while (first != NULL)
	{
		second = first->next;
		while (second != NULL)
		{
			if (first->value == second->value)
				return (1);
			second = second->next;
		}
		first = first->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_higher(int value, t_stack *a)
{
	a = a->next;
	while (a)
	{
		if (value < a->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*find_cheapest(t_stack *b)
{
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->cheap == 1)
			return (b);
		b = b->next;
	}
	return (NULL);
}

t_stack	*find_smallest_node(t_stack *a)
{
	t_stack	*smallest;

	smallest = a;
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}
