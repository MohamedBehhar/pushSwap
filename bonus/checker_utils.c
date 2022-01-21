/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbehhar <mbehhar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:40:24 by mbehhar           #+#    #+#             */
/*   Updated: 2022/01/18 12:29:56 by mbehhar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*push_swap_strjoin(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;
	int		l;

	result = NULL;
	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
	l = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (l + 1));
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

char	*get_line_annex(int a, int fd, char *buffer, char *line)
{
	while (1)
	{
		a = read(fd, buffer, 1);
		if (a == -1)
		{
			if (buffer)
				free(buffer);
			free(line);
			return (NULL);
		}
		if (a == 0)
		{
			free(buffer);
			return (line);
		}
		buffer[1] = 0;
		if (buffer[0] == '\n')
		{
			line = push_swap_strjoin(line, buffer);
			free(buffer);
			return (line);
		}
		line = push_swap_strjoin(line, buffer);
	}
}

char	*get_line(int fd)
{
	char	*line;
	char	*buffer;
	int		a;

	line = NULL;
	buffer = NULL;
	a = 0;
	buffer = (char *)malloc(sizeof(char) * 2);
	line = get_line_annex(a, fd, buffer, line);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*result;

	result = NULL;
	if (fd < 0)
		return (NULL);
	result = get_line(fd);
	return (result);
}
