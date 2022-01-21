/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:49:23 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/20 18:54:25 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_error(char *str)
{
	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
	ft_putstr_fd(str, 1);
	exit(0);
}

int	is_sorted(t_stack *stack)
{
	t_node	*ptr;

	ptr = stack->head;
	while (ptr->next)
	{
		if (ptr->data > ptr->next->data)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

long	push_swap_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}

void	check_double(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		if (!str[j])
			return ;
		while (ft_strcmp(str[i], str[j]) != 0 && str[j])
			j++;
		if ((ft_strcmp(str[i], str[j]) == 0))
		{
			free_str(str);
			handle_error("THERE ARE DUPLICATES\n");
		}
		i++;
	}
}

void	check_integers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '+' || str[i][j] == '-')
			j++;
		if (str[i][j] == '\0')
			handle_error("SOME ARGS AREN'T INTEGERS\n");
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
			{
				handle_error("SOME ARGS AREN'T INTEGERS\n");
			}
			j++;
		}
		i++;
	}
}
