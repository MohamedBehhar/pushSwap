/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:39:30 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 09:50:39 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*creat_node(int data)
{
	t_node	*new_node;

	new_node = NULL;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_node	*return_first_node(t_stack *stack)
{
	t_node	*node;

	if (stack->head == NULL)
		return (NULL);
	node = stack->head;
	if (node->next != NULL)
	{
		stack->head = node->next;
		stack->head->prev = NULL;
	}
	if (node->next == NULL)
	{
		stack->head = NULL;
		stack->last = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

t_node	*return_last_node(t_stack *stack)
{
	t_node	*node;

	if (stack->head == NULL)
		return (NULL);
	node = stack->last;
	if (node->prev != NULL)
	{
		stack->last = stack->last->prev;
		stack->last->next = NULL;
	}
	if (node->prev == NULL)
	{
		stack->head = NULL;
		stack->last = NULL;
	}
	node->next = NULL;
	node->prev = NULL;
	stack->size--;
	return (node);
}

t_node	*add_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!new)
		return (NULL);
	if (!stack->head)
	{
		stack->head = new;
		stack->size = 0;
	}
	else
	{
		last = stack->last;
		last->next = new;
		new->prev = last;
	}
	stack->last = new;
	stack->size++;
	return (new);
}

void	add_front(t_stack *stack, t_node *new)
{
	t_node	*old_head;

	old_head = stack->head;
	if (new == NULL)
		return ;
	if (stack->head == NULL)
	{
		stack->head = new;
		stack->size = 0;
		stack->last = stack->head;
	}
	else
	{
		old_head->prev = new;
		stack->head = new;
		new->next = old_head;
	}
	stack->size++;
}
