/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:41:46 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/19 15:02:06 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	char	**s_data;
	t_node	*head;
	t_node	*last;
	size_t	size;
	int		quarter;
	int		median;
	int		three_qrt;
	int		bigg;
	int		small;
	int		lenght;
}	t_stack;

// UTILS
t_node	*creat_node(int data);
t_node	*return_first_node(t_stack *stack);
t_node	*return_last_node(t_stack *stack);
t_node	*add_back(t_stack *stack, t_node *new);
void	add_front(t_stack *stack, t_node *new);

// STACK
void	print_stack(t_node *head, char c);
void	print_stack_rev(t_stack *stack);
void	init_stack(t_stack *stack_a, t_stack *stack_b);

// INSTRUCTIONS
void	sa(t_stack *stack, int i);
void	sb(t_stack *stack, int i);
void	ss(t_stack *stack_a, t_stack *stack_b, int i);
void	pa(t_stack *stack_a, t_stack *stack_b, int i);
void	pb(t_stack *stack_a, t_stack *stack_b, int i);
void	ra(t_stack *stack, int i);
void	rb(t_stack *stack, int i);
void	rr(t_stack *stack_a, t_stack *stack_b, int i);
void	rra(t_stack *stack, int i);
void	rrb(t_stack *stack, int i);
void	rrr(t_stack *stack_a, t_stack *stack_b, int i);

// ERRORS
long	push_swap_atoi(const char *str);
void	check_double(char **str);
void	check_integers(char **str);
void	handle_error(char *str);
int		is_sorted(t_stack *stack);

// FREE DATA 
void	free_str(char **str);
void	free_stack(t_node *head);

// DATA HANDLER
char	**join_args(int i, char**av);

// SORTING
void	sort_a(t_stack *stack_a, t_stack *stack_b);
void	sort_b(t_stack *stack_a, t_stack *stack_b, int min, int max);
void	handle_sort(t_stack *stack_a, t_stack *stack_b);
void	five_sort(t_stack *stack_a, t_stack *stack_b);
void	three_sort(t_stack *stack);
void	empty_stack(t_stack *stack_a, t_stack *stack_b);
void	define_delimiter(t_stack *stack, int k);
void	define_index(t_stack *stack, long *arr);
void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b);
void	sort_b_annex(t_stack *stack_a, t_stack *stack_b, int j);

//	FIND
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
void	find_median(t_stack *stack);
void	sort_arr(t_stack *stack, long *arr, int size);

//BONUS
char	*get_next_line(int fd);
char	*get_line(int fd);
char	*push_swap_strjoin(char *s1, char *s2);
#endif