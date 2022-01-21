/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:17:10 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/20 16:33:52 by mbehhar          ###   ########.fr       */
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

void	check_inst(char *inst, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(inst, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(inst, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(inst, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(inst, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(inst, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strcmp(inst, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(inst, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(inst, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(inst, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(inst, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(inst, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
		handle_error("Invalid Instruction\n");
}

void	get_inst(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	char	*inst;

	i = 0;
	inst = get_next_line(0);
	while (inst != NULL)
	{
		check_inst(inst, stack_a, stack_b);
		free (inst);
		inst = get_next_line(0);
	}
	if (is_sorted(stack_a) == 1 && stack_b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		j;
	int		i;

	init_stack(&stack_a, &stack_b);
	i = 0;
	if (ac < 2)
		return (0);
	stack_a.s_data = join_args(i, av);
	check_double(stack_a.s_data);
	check_integers(stack_a.s_data);
	j = -1;
	while (stack_a.s_data[++j])
	{
		if (push_swap_atoi(stack_a.s_data[j]) > 2147483647)
			handle_error("SOME ARGS ARE BIGGER THAN MAXINT\n");
		add_back(&stack_a, creat_node(push_swap_atoi(stack_a.s_data[j])));
	}
	free_str(stack_a.s_data);
	find_median(&stack_a);
	get_inst(&stack_a, &stack_b);
	free_stack(stack_b.head);
	free_stack(stack_a.head);
}
