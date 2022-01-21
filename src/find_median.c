/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:39:33 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/18 12:56:30 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	define_index(t_stack *stack, long *arr)
{
	t_node	*ptr;
	int		size;
	int		i;

	ptr = stack->head;
	size = stack->size;
	while (ptr)
	{
		i = 0;
		while (i < size)
		{
			if (ptr->data == arr[i])
					ptr->index = i;
			i++;
		}
		ptr = ptr->next;
	}
}

void	sort_arr(t_stack *stack, long *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	check_doubles_in_arr(t_stack *stack, long *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				free_stack(stack->head);
				handle_error("THERE ARE DUPLICATES\n");
			}
			j++;
		}
		i++;
	}
}

void	find_median(t_stack *stack)
{
	long	*arr;
	t_node	*ptr;
	size_t	size;
	int		quart;
	int		i;

	size = stack->size;
	ptr = stack->head;
	quart = size / 4;
	i = -1;
	arr = (long *)malloc(sizeof(long) * stack->size);
	if (!arr)
		return ;
	while (++i < size)
	{
		arr[i] = ptr->data;
		ptr = ptr->next;
	}
	sort_arr(stack, arr, size);
	check_doubles_in_arr(stack, arr, stack->size);
	stack->quarter = arr[quart];
	stack->median = arr[quart * 2];
	stack->three_qrt = arr[quart * 3];
	define_index(stack, arr);
	free(arr);
}
