/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:41:46 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 12:21:40 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*last;
	size_t	size;
	char	**s_data;
}	t_stack;

// UTILS
t_node	*creat_node(int data);
t_node	*return_first_node(t_stack *stack);
t_node	*return_last_node(t_stack *stack);
t_node	*add_back(t_stack *stack, t_node *new);
void	add_front(t_stack *stack, t_node *new);

// PRINT STACK
void	print_stack(t_node *head);
void	print_stack_rev(t_stack *stack);

// OPERATIONS FUNCTIONS 
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// ERRORS FUNCTIONS 
long	push_swap_atoi(const char *str);
void	check_double(char **str);
void	check_integers(char **str);
void	handle_error(char *str);

// FREE DATA 
void	free_str(char **str);
void	free_stack(t_node *head);

// DATA HANDLER FUNCTIONS
char	**join_args(char**av);

// SORTING FUNCTIONS
void	simpleSort(t_stack *stack);

#endif