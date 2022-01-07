/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:47:17 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 09:53:32 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
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
}

void	sb(t_stack *stack)
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
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sa(stack_b);
}
