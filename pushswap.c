/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:59:38 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 15:00:02 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	check_errors(char	*str)
{
	if (validation(str) == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	sorting_function(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (is_duplicate(a) == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size > 3)
		sort_all_moves(a, b);
}

void	join_args(char	**temp, int ac, char	**av)
{
	int		i;
	char	*new_temp;

	i = 2;
	while (i < ac)
	{
		new_temp = ft_strjoin(*temp, " ");
		free(*temp);
		*temp = new_temp;
		new_temp = ft_strjoin(*temp, av[i]);
		free(*temp);
		*temp = new_temp;
		i++;
	}
}

int	main(int ac, char	**av)
{
	int		i;
	char	**str;
	char	*temp;
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	i = 1;
	while (i < ac)
		check_errors(av[i++]);
	temp = ft_strdup(av[1]);
	i = 2;
	join_args(&temp, ac, av);
	str = ft_split(temp, ' ');
	free(temp);
	creat_stack_elements(&a, str);
	free_str_array(str);
	sorting_function(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
