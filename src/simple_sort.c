/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:11:13 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/18 12:56:52 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	median_to_the_top(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_node	*ptr;
	int		i;

	ptr = stack_a->head;
	i = 0;
	while (ptr->data != stack_a->median && i++ < size / 2)
		ptr = ptr->next;
	if (i > size / 4)
	{
		while (stack_a->head->data != stack_a->median)
		{
			if (stack_a->head->data < stack_a->median)
				pb(stack_a, stack_b, 1);
			rra(stack_a, 1);
		}
	}
	else if (i <= size / 4)
	{
		while (stack_a->head->data != stack_a->median)
		{
			if (stack_a->head->data < stack_a->median)
				pb(stack_a, stack_b, 1);
			ra(stack_a, 1);
		}
	}
}

void	sort_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*ptr;
	int		size;
	int		i;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		if (stack_a->head->data < stack_a->median)
			pb(stack_a, stack_b, 1);
		else
			ra(stack_a, 1);
		if (stack_b->size != 0 && stack_b->head->data >= stack_a->median / 2)
			rb(stack_b, 1);
		i++;
	}
	median_to_the_top(stack_a, stack_b, size);
	sort_b(stack_a, stack_b, 0, 0);
}

void	sort_b(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	t_node		*ptr;
	static int	j;
	int			i;

	while (stack_b->size)
	{
		min = find_smallest(stack_b);
		max = find_biggest(stack_b);
		ptr = stack_b->head;
		i = 0;
		while (ptr->data != min && ptr->data != max && i++ < stack_b->size)
			ptr = ptr->next;
		if (i < stack_b->size / 4)
			while (stack_b->head->data != min && stack_b->head->data != max)
				rb(stack_b, 1);
		else if (i >= stack_b->size / 4)
			while (stack_b->head->data != min && stack_b->head->data != max)
				rrb(stack_b, 1);
		pa(stack_a, stack_b, 1);
		if (stack_a->head->data == min)
			ra(stack_a, 1);
	}
	sort_b_annex(stack_a, stack_b, j++);
	if (j != 0)
		return ;
}

void	sort_b_annex(t_stack *stack_a, t_stack *stack_b, int j)
{
	if (j == 0)
	{
		while (stack_a->head->data != stack_a->median)
			ra(stack_a, 1);
		ra(stack_a, 1);
		while (stack_a->head->data != stack_a->small)
		{
			pb(stack_a, stack_b, 1);
			if (stack_b->size != 0 && stack_b->head->data <= stack_a->three_qrt)
				rb(stack_b, 1);
		}
		sort_b(stack_a, stack_b, 0, 0);
	}
	else
		while (stack_a->head->data != stack_a->small)
			ra(stack_a, 1);
}

void	handle_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size <= 3)
	{
		three_sort(stack_a);
		return ;
	}
	else if (stack_a->size <= 5)
	{
		five_sort(stack_a, stack_b);
		return ;
	}
	find_median(stack_a);
	stack_a->small = find_smallest(stack_a);
	stack_a->bigg = find_biggest(stack_a);
	sort_a(stack_a, stack_b);
}
