/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:43:03 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/06 09:44:57 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(head);
}
