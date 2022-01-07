/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:46:08 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 09:51:19 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_b->head == NULL)
		return ;
	tmp = return_first_node(stack_b);
	add_front(stack_a, tmp);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;

	if (stack_a->head == NULL)
		return ;
	tmp = return_first_node(stack_a);
	add_front(stack_b, tmp);
}
