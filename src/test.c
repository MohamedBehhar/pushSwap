/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:19:39 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 12:33:44 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**join_args(char **av)
{
	char		**str;
	static char	*res; 
	char		*space;
	int i;

	i = 0;
	space = ft_strdup(" ");
	if (!res)
		res = ft_strdup("");
	while (av[++i])
	{
		char *tmp_av = ft_strdup((av[i]));
		char *str = ft_strjoin(tmp_av, space);
		res = ft_strjoin(res, str);
		free(str);
	}
	free(space);
	str = ft_split(res, ' ');
	free(res);
	return (str);
}

int main(int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;

	if (ac < 2)
		return (0);
	stack_a.head = NULL;
	stack_b.head = NULL;
	stack_a.last = NULL;
	stack_b.last = NULL;
	
	stack_a.s_data = join_args(av);
	check_double(stack_a.s_data);
	check_integers(stack_a.s_data);
	int j = -1;
	while (stack_a.s_data[++j])
	{
		if (push_swap_atoi(stack_a.s_data[j]) > INT32_MAX ||
			push_swap_atoi(stack_a.s_data[j]) < INT32_MIN)
			handle_error("SOME ARGS ARE BIGGER THAN AN INTEGER\n");
		add_back(&stack_a, creat_node(push_swap_atoi(stack_a.s_data[j])));
	}
	free_str(stack_a.s_data);
	printf("====STACK A====\n");
	print_stack(stack_a.head);
	printf("last %d\n", stack_a.last->data);
	printf("size %ld\n", stack_a.size);

	
	printf("====SORTING OPERATIONS====\n");
	simpleSort(&stack_a);
	printf("==========================\n");
	
	printf("====STACK A====\n");
	print_stack(stack_a.head);
	printf("last %d\n", stack_a.last->data);
	printf("size %ld\n", stack_a.size);

	free_stack(stack_a.head);
	// while (1)
	// {
		
	// }
	// printf("====STACK B====\n");
	// print_stack_rev(&stack_b);
	// printf("last %d\n", stack_b.last->data);
	// printf("size %ld\n", stack_b.size);

}
