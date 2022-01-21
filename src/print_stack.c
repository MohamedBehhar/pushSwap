/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:48:18 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/18 11:52:04 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *head, char c)
{
	t_node	*ptr;

	if (c == 'a')
		ft_putstr_fd("--------- STACK_A ----------\n", 1);
	else if (c == 'b')
		ft_putstr_fd("--------- STACK_B ----------\n", 1);
	if (head == NULL)
	{
		ft_putstr_fd("THE STACK IS EMPTY\n", 1);
		ft_putstr_fd("----------------------------\n", 1);
		return ;
	}
	ptr = head;
	while (ptr)
	{
		ft_putnbr_fd(ptr->data, 1);
		ft_putstr_fd("\n", 1);
		ptr = ptr->next;
	}
	ft_putstr_fd("----------------------------\n", 1);
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
