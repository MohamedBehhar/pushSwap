/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingTest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:11:05 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 12:40:19 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	simpleSort(t_stack *stack)
{
	t_node	*ptr;
	int		i;

	if (!stack->head)
		return ;
	ptr = stack->head;
	i = -1;
	while (++i < stack->size - 1)
	{
		if (ptr->data > ptr->next->data)
		{
			sa(stack);
			ft_putnbr_fd(i, 1);
			ft_putstr_fd("===>sa\n", 1);
			print_stack(stack->head);
		}
		ptr = ptr->next;
	}
	if (ptr->data < ptr->prev->data)
	{
		sa(stack);
			ft_putnbr_fd(i, 1);
		ft_putstr_fd("===>rra\n", 1);
			print_stack(stack->head);
	}
	
}