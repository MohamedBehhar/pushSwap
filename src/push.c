/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:46:08 by mbehhar           #+#    #+#             */
/*   Updated: 2022/03/30 16:07:29 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_node	*tmp;

	if (stack_b->head == NULL)
		return ;
	tmp = return_first_node(stack_b);
	add_front(stack_a, tmp);
	if (i == 1)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int i)
{
	t_node	*tmp;

	if (stack_a->head == NULL || stack_a->size == 1)
		return ;
	tmp = return_first_node(stack_a);
	add_front(stack_b, tmp);
	if (i == 1)
		ft_putstr_fd("pb\n", 1);
}
