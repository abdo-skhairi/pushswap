/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:59:31 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 01:49:58 by abdo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct t_stack
{
	struct t_stack	*next;
	struct t_stack	*target_node;
	bool			is_in_first_half;
	int				cheap;
	int				price;
	int				index;
	int				value;
}			stack;

stack	*find_smallest_node(stack	*a);
stack	*find_cheapest(stack	*stack);
stack	*find_smallest_node(stack	*a);

void	reverse_rotate_both(stack **a, stack **b, stack *cheapest_node);
void	rotate_both(stack **a, stack **b, stack *cheapest_node);
void	sort_5(stack **a, stack **b);
void	sort_3(stack **a);
void	moves(stack **a, stack **b);
void	set_price(stack *a, stack *b);
void	set_target(stack *a, stack *b);
void	set_index_position(stack *stack);
void	set_all_nodes(stack *a, stack *b);
void	sort_all_moves(stack **a, stack **b);
void	set_and_move(stack **a, stack **b);
void	finish_rotation(stack **current_stack,
			stack *cheapest_node, char stack_name);

stack	*new_node(int value);
void	creat_stack_elements(stack **a, char **str2);
int		is_higher(int value, stack *a);
int		is_sorted(stack *a);
int		is_duplicate(stack **a);
void	free_stacks(stack **a, stack **b);
void	free_stack_utils(stack **b, stack	*current, stack	*next);
int		stack_size(stack *a);

void	rr(stack **stack_a, stack **stack_b);
void	rb(stack **stack_b);
void	ra(stack **stack_a);
void	rrr(stack **stack_a, stack **stack_b);
void	rrb(stack **stack_b);
void	rra(stack **stack_a);
void	ss(stack **stack_a, stack **stack_b);
void	sb(stack **stack_b);
void	sa(stack **stack_a);
void	pa(stack **a, stack **b);
void	pb(stack **a, stack **b);

void	ft_strcpy(char *dest, const char *src);
void	free_str_array(char **arr);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char	*str);
int		validation(char	*str);
char	*ft_strdup(const char *s1);
int		ft_strchr(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif