/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:01:05 by simonwautel       #+#    #+#             */
/*   Updated: 2022/02/15 20:30:45 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*gnl(char *result, char *buffer, int size, int fd)
{
	while (size > 0)
	{
		result = ft_straddback(result, buffer, size);
		if (!result)
			return (NULL);
		if (ft_end_of_line(result) == 1)
			return (result);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*result;
	ssize_t		size;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	result = ft_initialize(buffer);
	if (!result)
		return (NULL);
	if (ft_end_of_line(result) == 1)
		return (result);
	size = read(fd, buffer, BUFFER_SIZE);
	if (size == 0 && result[0] != '\0')
		return (result);
	if (size <= 0)
	{
		free (result);
		return (NULL);
	}
	result = gnl(result, buffer, size, fd);
	return (result);
}
