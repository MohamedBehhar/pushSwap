/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:03:32 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 09:51:54 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL)
		return ;
	tmp = return_last_node(stack);
	add_front(stack, tmp);
}

void	rrb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL)
		return ;
	tmp = return_last_node(stack);
	add_front(stack, tmp);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
