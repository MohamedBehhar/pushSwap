/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:47:17 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/19 13:14:53 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, int i)
{
	t_node	*old_head;
	t_node	*new_head;

	if (stack->size <= 1)
		return ;
	old_head = return_first_node(stack);
	stack->size++;
	new_head = stack->head;
	if (stack->size > 2)
	{
		old_head->next = new_head->next;
		new_head->next->prev = old_head;
	}
	if (stack->size == 2)
		stack->last = old_head;
	old_head->prev = new_head;
	new_head->next = old_head;
	if (i == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack, int i)
{
	t_node	*old_head;
	t_node	*new_head;

	if (stack->size <= 1)
		return ;
	old_head = return_first_node(stack);
	stack->size++;
	new_head = stack->head;
	if (stack->size > 2)
	{
		old_head->next = new_head->next;
		new_head->next->prev = old_head;
	}
	if (stack->size == 2)
		stack->last = old_head;
	old_head->prev = new_head;
	new_head->next = old_head;
	if (i == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int i)
{
	sa(stack_a, i);
	sa(stack_b, i);
}
