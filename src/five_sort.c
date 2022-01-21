/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:23:10 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/18 11:37:27 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	empty_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		pa(stack_a, stack_b, 1);
	}
}

void	three_sort(t_stack *stack)
{
	t_node	*head;
	t_node	*next;
	t_node	*last;

	while (is_sorted(stack) == 0)
	{
		head = stack->head;
		next = stack->head->next;
		last = stack->last;
		if (head->data > next->data)
		{
			if (head->data > last->data)
				ra(stack, 1);
			else
				sa(stack, 1);
		}
		else
			sa(stack, 1);
	}
}

void	five_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	while (stack_a->size > 3)
	{
		min = find_smallest(stack_a);
		if (stack_a->last->data == min)
			rra(stack_a, 1);
		else if (stack_a->last->prev->data == min)
		{
			rra(stack_a, 1);
			rra(stack_a, 1);
		}
		while (stack_a->head->data != min)
			ra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	if (stack_a->size == 3)
		three_sort(stack_a);
	empty_stack(stack_a, stack_b);
}
