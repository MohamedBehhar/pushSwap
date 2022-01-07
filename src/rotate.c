/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:02:45 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 09:52:36 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = return_first_node(stack);
	add_back(stack, tmp);
}

void	rb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = return_first_node(stack);
	add_back(stack, tmp);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
