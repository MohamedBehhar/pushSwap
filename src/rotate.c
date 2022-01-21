/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:02:45 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/19 13:14:46 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack, int i)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = return_first_node(stack);
	add_back(stack, tmp);
	if (i == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack, int i)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->size <= 1)
		return ;
	tmp = return_first_node(stack);
	add_back(stack, tmp);
	if (i == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int i)
{
	ra(stack_a, i);
	rb(stack_b, i);
}
