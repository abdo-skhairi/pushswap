/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:00:08 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 01:00:10 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_str_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack_utils(stack **b, stack	*current, stack	*next)
{
	if (b)
	{
		current = *b;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*b = NULL;
	}
}

void	free_stacks(stack **a, stack **b)
{
	stack	*current;
	stack	*next;

	if (a)
	{
		current = *a;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
		*a = NULL;
	}
	free_stack_utils(b, current, next);
}
