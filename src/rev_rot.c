/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:03:32 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/19 13:14:41 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack, int i)
{
	t_node	*tmp;

	if (stack->head == NULL)
		return ;
	tmp = return_last_node(stack);
	add_front(stack, tmp);
	if (i == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack, int i)
{
	t_node	*tmp;

	if (stack->head == NULL)
		return ;
	tmp = return_last_node(stack);
	add_front(stack, tmp);
	if (i == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int i)
{
	rra(stack_a, i);
	rrb(stack_b, i);
}
