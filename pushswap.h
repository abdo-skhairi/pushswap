/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdo <abdo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:59:31 by abdo              #+#    #+#             */
/*   Updated: 2025/03/09 14:48:16 by abdo             ###   ########.fr       */
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
}			t_stack;

t_stack	*find_smallest_node(t_stack	*a);
t_stack	*find_cheapest(t_stack	*stack);
t_stack	*find_smallest_node(t_stack	*a);

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	sort_5(t_stack **a, t_stack **b);
void	sort_3(t_stack **a);
void	moves(t_stack **a, t_stack **b);
void	set_price(t_stack *a, t_stack *b);
void	set_target(t_stack *a, t_stack *b);
void	set_index_position(t_stack *stack);
void	set_all_nodes(t_stack *a, t_stack *b);
void	sort_all_moves(t_stack **a, t_stack **b);
void	set_and_move(t_stack **a, t_stack **b);
void	finish_rotation(t_stack **current_stack,
			t_stack *cheapest_node, char stack_name);

t_stack	*new_node(int value);
void	creat_stack_elements(t_stack **a, char **str2);
int		is_higher(int value, t_stack *a);
int		is_sorted(t_stack *a);
int		is_duplicate(t_stack **a);
void	free_stacks(t_stack **a, t_stack **b);
void	free_stack_utils(t_stack **b, t_stack	*current, t_stack	*next);
int		stack_size(t_stack *a);

void	rr(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_b);
void	sa(t_stack **stack_a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

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