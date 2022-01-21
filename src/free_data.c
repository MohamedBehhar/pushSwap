/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:43:03 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/18 11:41:26 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**join_args(int i, char **av)
{
	static char	*res;
	char		*space;
	char		**str;
	char		*tmp_av;
	char		*s;

	space = ft_strdup(" ");
	if (!res)
		res = ft_strdup("");
	while (av[++i])
	{
		if (av[i][0] == '\0')
			handle_error("SOME ARGS AREN'T INTEGERS\n");
		tmp_av = ft_strdup((av[i]));
		s = ft_strjoin(tmp_av, space);
		res = ft_strjoin(res, s);
		free(s);
	}
	free(space);
	str = ft_split(res, ' ');
	free(res);
	return (str);
}

int	find_smallest(t_stack *stack)
{
	t_node	*ptr;
	int		min;
	int		i;

	ptr = stack->head;
	min = stack->head->data;
	i = 0;
	while (ptr->next)
	{
		if (ptr->data < min)
			min = ptr->data;
		ptr = ptr->next;
	}
	if (ptr->data < min)
		min = ptr->data;
	return (min);
}

int	find_biggest(t_stack *stack)
{
	t_node	*ptr;
	int		max;
	int		i;

	ptr = stack->head;
	max = stack->head->data;
	i = 0;
	while (ptr->next)
	{
		if (ptr->data > max)
			max = ptr->data;
		ptr = ptr->next;
	}
	if (ptr->data > max)
		max = ptr->data;
	return (max);
}

void	free_str(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = -1;
	while (str[++i])
	{
		free(str[i]);
	}
	free(str[i]);
	free(str);
}

void	free_stack(t_node *head)
{
	t_node	*tmp;

	if (head == NULL)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}
