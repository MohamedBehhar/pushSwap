/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:19:39 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/20 19:00:29 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->head = NULL;
	stack_b->head = NULL;
	stack_a->last = NULL;
	stack_b->last = NULL;
	stack_b->size = 0;
	stack_a->size = 0;
}

void	find_errors(t_stack *stack_a)
{
	int	j;

	j = -1;
	check_double(stack_a->s_data);
	check_integers(stack_a->s_data);
	while (stack_a->s_data[++j])
	{
		if (push_swap_atoi(stack_a->s_data[j]) > 2147483647)
			handle_error("SOME ARGS ARE BIGGER THAN MAXINT\n");
		add_back(stack_a, creat_node(push_swap_atoi(stack_a->s_data[j])));
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	if (ac < 2)
		return (0);
	init_stack(&stack_a, &stack_b);
	i = 0;
	stack_a.s_data = join_args(i, av);
	find_errors(&stack_a);
	free_str(stack_a.s_data);
	find_median(&stack_a);
	if (stack_a.size > 100)
		ft_radix_sort(&stack_a, &stack_b);
	handle_sort(&stack_a, &stack_b);
	free_stack(stack_a.head);
}
