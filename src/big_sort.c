/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:04:59 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/20 19:00:34 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	size;
	int	shifter;

	size = stack_a->size;
	shifter = 0;
	while (is_sorted(stack_a) == 0)
	{
		i = -1;
		while (++i < size)
		{
			if (((stack_a->head->index >> shifter) & 1) == 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b, 1);
		}
		while (stack_b->size)
			pa(stack_a, stack_b, 1);
		shifter++;
	}
}
