/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:48:18 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 09:47:16 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *head)
{
	t_node	*ptr;

	if (head == NULL)
		handle_error("THE STACK IS EMPTY\n");
	ptr = head;
	while (ptr)
	{
		ft_putnbr_fd(ptr->data, 1);
		ft_putstr_fd("\n", 1);
		ptr = ptr->next;
	}
}

void	print_stack_rev(t_stack *stack)
{
	t_node	*ptr;

	if (stack->last == NULL)
		handle_error("THE STACK IS EMPTY\n");
	ptr = stack->last;
	while (ptr->prev)
	{
		ft_putnbr_fd(ptr->data, 1);
		ft_putstr_fd("\n", 1);
		ptr = ptr->prev;
	}
}
